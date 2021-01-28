#pragma once
class Animal
{
private:
	int id;
public:
	Animal();
	Animal(int id);
	virtual void speak();
	void info();
	//pure virtual function
	//virtual void speak2() = 0;
	virtual ~Animal();
};

