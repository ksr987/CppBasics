#include "Cat.h"
#include <iostream>
using namespace std;

Cat::Cat() {
	cout << "Cat no-args constructor is called" << endl;
}

//call the superclass constructor since there is no 'id' variable in Cat class
Cat::Cat(int id) : Animal(id) {
	cout << "Cat parametrized constructor is called" << endl;
}

void Cat::speak() {
	cout << "RRRrrrRRR" << endl;
}

void Cat::speak2() {

}

void Cat::jump() {
	cout << " Cat jumping! " << endl;
}

string Cat::getName() {
	return this->name;
}

Cat::~Cat() {

}
