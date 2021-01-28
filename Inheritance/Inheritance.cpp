#include "Inheritance.h"
#include "Animal.h"
#include "Cat.h"
#include "HouseCat.h"
#include <Cat.h>

int main() {
	Animal a;
	a.speak();

	Cat cat1("Freddy");
	//inherited from animal class
	cat1.speak();

	cat1.jump();

	//encapsulation
	cout << cat1.getName() << endl;

	//constructor inheritance
	Cat cat2; //prints the print statement in the Cat constructor and all the subsequent superclasses.
			  //Animal constructor FIRST, and then the Cat constructor.

	cat2.info(); //Id of the cat is 0 since the above statement invokes the Animal constructor first.

	//invoke parametrized constructor of Animal
	Animal a2(123);
	a2.info();

	//cannot call the parametrized constructor on Cat object if no such constructor 
	//with the required params is implemented in Cat class. Constructors of the superclass are NEVER
	//inherited, but only called when object of a subclass is created. 
	Cat cat3(123);
	cat3.info();

	//Polymorphism

	//you can use a derived class to create an object where a superclass was expected.
	Animal* pAnimal = new Cat(); //cat object

	//if the speak method is not defined to be virtual, then this tells the cat object that the speak method has not
	//been overridden, and will run the speak() from Animal class. However, if speak() is defined virtual, then 
	//overriding is possible and the method will return output from Cat::speak(). Virtual keyword only needs to be
	//specified in the header file. Not required in the cpp file method header.
	pAnimal->speak();

	//it is generally a good practice to define all the subclass methods to be virtual as well even though they are 
	//not being overridden.

	Animal* pAnimal2 = new HouseCat();
	pAnimal2->speak(); //even if virtual keyword is not present on the Cat::speak(), this will still output "Meow".
	//This is because it is only required to specify the base class (Animal) as virtual and C++ takes care of the 
	//correct overriden method to implement.

	Cat* pCat1 = new HouseCat(); //HouseCat object
	pCat1->speak(); //still prints "Meow" if virtual keyword not there on Cat::speak()
	pCat1->jump(); //works since HouseCat inherits all methods from Cat class

	//Good practice to declare destructors as virtual.

	//Alternatively, we can define the Animal::speak() to be abstract method(also called pure virtual function.)
	//Example is shown in Animal::speak2(). Pure virtual function forces all the derived classes to implement them.

	delete pAnimal;
	delete pAnimal2;
	delete pCat1;

	//static library example is shown in ExampleLibrary project.
	ketan::saySomething();
	ketan::Cat libraryCat;

	libraryCat.speak();

	return 0;
}
