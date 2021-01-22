#pragma once

#include <iostream>
using namespace std;
class Animal
{
private:
	string name;

public:
	Animal();

	//copy constructor
	Animal(const Animal& other);

	void setName(string newName);
	void speak() const;
	~Animal();
};

