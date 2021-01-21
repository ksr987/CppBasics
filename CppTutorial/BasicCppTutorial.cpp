// CppTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

void doSomething();

int main() {

	//endl -> \n equivalent, and flushes the buffer
	cout << "Hello the world" << endl;

	//flush -> does not introduce carriage return, but flushes out the buffer
	cout << "this is the next line " << flush;

	int numCats = 5;
	string txt = "this is a text string ";
	string txt2 = "ketan";

	//prints the value of numCats -> 5
	cout << numCats << endl;

	//prints the address of numCats -> 0115FA7C
	cout << &numCats << endl;

	//prints the txt string
	cout << txt + txt2 << endl;

	//getting input from user
	cout << "Enter your name: " << flush;
	string input;
	cin >> input;
	cout << "Hello " << input + "!" << endl;

	//primary data type check -> if user enters a string instead of a number, age variable is 
	//assigned a value of 0.
	cout << "Enter your age: " << flush;
	int age;
	cin >> age;
	cout << "You are " << age << " years old!" << endl;


	//max and min int value
	cout << INT_MAX << endl;
	cout << INT_MIN << endl;

	//use long long data type for numbers greater than max int range
	long long numGreaterThanIntRange = 812763812622;
	cout << numGreaterThanIntRange << endl;

	//if you know your variable is always positive, you can use unsigned int data type
	unsigned int entropy = 5;
	cout << entropy << endl;

	float avg = 34.4;
	double speed = 102.54;
	cout << avg << endl;
	cout << speed << endl;

	//7 significant digits for avg variable
	cout << fixed << avg << endl;

	//use long double for extremely precise values
	long double veryPreciseValue = 124.45276234876392;
	cout << setprecision(20) << fixed << veryPreciseValue << endl;
	//long double uses 8 bytes to store a single value
	cout << sizeof(veryPreciseValue) << endl;

	string a = "test";
	string b = "test";
	bool check = (a == b);

	//prints true for c++
	cout << check << endl;

	//you cannot compare 2 floats precisely, since after certain significant digits, the float val
	//is garbage. Hence for comparing 2 floats, you need to define the abs diff between them to be 
	//less than a certain value (eg epsilon)

	float val1 = 11.1;
	
	if (val1 == 11.1) {
		cout << "equals" << endl;
	}
	else {
		cout << "not equals" << endl;
	}

	//initialize array of length 3
	int arr[3] = { 1,2,3 };
	//initialize arr2 to 0
	int arr2[3] = {};
	cout << arr[0] << endl;
	cout << arr2[0] << endl;

	//dont have to specify array size when declaring the array at the same time
	string fruits[] = { "apple", "banana" ,"orange" };
	cout << fruits[1] << endl;

	//have to specify how many columns in 2d array even if declaring the array at the same time
	string animals[][3] = { {"fox", "fox", "fox"}, {"fox", "fox" ,"fox"}};

	//traversing 2d array
	for (unsigned int i = 0; i < sizeof(animals) / sizeof(animals[0]); i++) {
		for (unsigned int j = 0; j < sizeof(animals[0]) / sizeof(string); j++) {
			cout << animals[i][j] << " " << flush;
		}
		cout << endl;
	}

	//in c++, you have to define methods you want to call (in main) before the main method signature. 
	//otherwise c++ cant recognize the function. c++ compiler reads code in top down fashion.
	//To avoid this inconvenience, we can put a prototype of the function above the main method without
	//its implementation. And if there are multiple prototypes, all of the prototypes can be combined
	//into a single header file, and the header file included at the top of the calling class.
	doSomething();

	return 0;
}

void doSomething() {
	cout << "this is a method below the main" << endl;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu