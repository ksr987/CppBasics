#include "Person.h"
#include <iostream>
#include <sstream>

using namespace std;

//without using constructor initialization lists
Person::Person() {
	this->name = "undefined";
	this->age = 0;
}

//using constructor initialization lists
//in name("undefined"), the name is the private data member of the person class, and "undefined" is
//the value assigned to the data member.
Person::Person(): name("undefined"), age(0) {}

//without using constructor initialization lists
Person::Person(string name, int age) {
	this->name = name;
	this->age = age;
}

//using constructor initialization lists
//name(name) : the name inside parenthesis is the variable name passed as parameter.
Person::Person(string name, int age): name(name), age(age) {}


string Person::toString() {
	stringstream ss;
	ss << "Name: ";
	ss << this->name;
	ss << "; Age: ";
	ss << this->age;
	return ss.str();
}
