#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;
//cat is a subclass of animal
class Cat :public Animal
{
private:
	string name;
public:
	Cat();
	Cat(string name): name(name){}

	//call the superclass constructor
	Cat(int id);
	void jump();
	string getName();
	virtual void speak();
	virtual void speak2();
	virtual ~Cat();
};

