#include "Cat.h"
#include <iostream>	

using namespace std;

namespace ketan {
	
	void saySomething() {
		std::cout << "Helllo there!!" << std::endl;
	}

	Cat::Cat() {

	}

	void Cat::speak() {
		std::cout << "Meeeow" << std::endl;
	}

	Cat::~Cat() {

	}

}