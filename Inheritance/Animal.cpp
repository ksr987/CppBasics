#include "Animal.h"
#include <iostream>
using namespace std;

Animal::Animal() :id(0) {
	cout << "Animal no-args constructor is called." << endl;
}

Animal::Animal(int id) : id(id) {
	cout << "Animal parametrized constructor is called." << endl;
}

void Animal::speak() {
	//???? since we dont know which animal it is, so cannot predict the sound it makes.
	cout << "?????" << endl;
}

void Animal::info() {
	cout << "My Id is: " << this->id << endl;
}

Animal::~Animal() {

}
