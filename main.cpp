#include <iostream>
#include "Animal.h"
#include "Jungle.h"
#include "WildAnimal.h"
#include "DomesticAnimal.h"
#include "Pet.h"

using namespace std;

int main() {
    int numberOfAnimals;
    cout << "Enter number of animals:";
    cin >> numberOfAnimals;

    //making storage for the jungle half wild half domestic
    //+1 is for when we dont have even number of animals
    Animal **animals = new Animal*[numberOfAnimals];
    for (int i = 0, j = numberOfAnimals/2; i < numberOfAnimals/2 + 1 ; ++i, ++j) {
        animals[i] = new DomesticAnimal;
        animals[j] = new WildAnimal;
    }

    //making the jungle
    Jungle jungle(numberOfAnimals);
    for (int i = 0; i < numberOfAnimals; ++i) {
        jungle.AddAnimal(animals[i]);
    }

    //1000 movement of animals in jungle
    for (int i = 0; i < 1000; ++i) {
        jungle.movement();
    }

    cout << "total fall of animals:";
    cout << jungle.getTotalFall() << endl;

    for (int i = 0; i < numberOfAnimals; ++i) {
        delete[] animals[i];
    }
    delete[] animals;


    cout << endl << "---------------------------------------------" << endl;
    cout << "you are now in second jungle!" << endl;

    cout << "Enter number of animals:";
    cin >> numberOfAnimals;

    animals = new Animal*[numberOfAnimals];
    for (int i = 0, g = numberOfAnimals/3, k = g * 2; i < numberOfAnimals/3; ++i, ++g, ++k) {
        animals[i] = new DomesticAnimal;
        animals[g] = new WildAnimal;
        animals[k] = new Pet;
    }
    if (numberOfAnimals % 3 == 1)
        animals[numberOfAnimals-1] = new WildAnimal;
    else if (numberOfAnimals % 3 == 2){
        animals[numberOfAnimals-2] = new WildAnimal;
        animals[numberOfAnimals-1] = new Pet;
    }

    Jungle jungle2(numberOfAnimals);
    for (int i = 0; i < numberOfAnimals; ++i) {
        jungle2.AddAnimal(animals[i]);
    }
    for (int i = 0; i < 1000; ++i) {
        jungle2.movement();
    }

    cout << "total fall of animals:";
    cout << jungle2.getTotalFall();

    for (int i = 0; i < numberOfAnimals; ++i) {
        delete[] animals[i];
    }
    delete[] animals;
    return 0;
}
