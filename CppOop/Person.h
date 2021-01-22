#pragma once
#include <iostream>
using namespace std;
class Person
{
private:
	string name;
	int age;
public:
	Person();
	Person(string name, int age);

	//can even use constructor initialization lists in the header
	Person() : name("undefined"), age(0) {}
	Person(string name, int age) : name(name), age(age) {}

	string toString();
	void setName(string newName);
	void speak() const;
};

