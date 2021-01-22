#include "Animal.h"
#include <iostream>

Animal::Animal() { cout << "Animal object created" << endl; }

//copy constructor
//const reference for other Animal object means you cannot change its data members. Thus, in the copy
//constructor, you cannot use methods like other.setName(name) since that will change the properties of
//'other' animal object. No non-const methods can be called in copy constructors. Only const methods can be
//called. Eg: other.speak() can be called.
Animal::Animal(const Animal& other): name(other.name) { cout << "Animal created by copying" << endl; }

void Animal::setName(string newName) { this->name = newName; }
void Animal::speak() const { cout << "My name is: " << this->name << endl; }

Animal::~Animal() {
	cout << "Destructor called" << endl;
}
