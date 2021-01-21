#include <iostream>
#include "Cat.h"

using namespace std;

Cat::Cat() {
	cout << "Cat created" << endl;
	Cat::happy = true;
}

void Cat::speak() {

	if (Cat::getHappy()) {
		cout << "meow" << endl;
	}
	else {
		cout << "not meow" << endl;
	}
	
}

void Cat::jump() {
	cout << "jumping to top of book case" << endl;
}

void Cat::setHappy(bool val) {
	Cat::happy = val;
}

bool Cat::getHappy() {
	return Cat::happy;
}

Cat::~Cat() {
	cout << "Cat destroyed" << endl;
	Cat::happy = false;
}