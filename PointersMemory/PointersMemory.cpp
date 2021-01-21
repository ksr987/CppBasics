#include <iostream>
using namespace std;

void manipulateByValue(double value) {
    cout << "2. Value of double in manipulateByValue: " << value << endl;
    cout << "Address of the value variable in the manipulateByValue method: " << &value << endl;
    value = 10.0;
    cout << "3. Value of double in manipulateByValue: " << value << endl;
}

void manipulateByReference(double* pValue) {
    cout << "2. Value of double in manipulateByReference: " << *pValue << endl;
    cout << "Address of the pValue variable in the manipulateByReference method: " << pValue << endl;
    *pValue = 10.0;
    cout << "3. Value of double in manipulateByReference: " << *pValue << endl;
    cout << "Address of the pValue variable in the manipulateByReference method after update: " 
        << pValue << endl;
}

int main()
{
    int age = 22;

    cout << "Value that int variable stores: " << age << endl;
    cout << "Address where the int variable is stored: " << &age << endl;
    
    //the pointer stores the address of the age variable
    int* pAge = &age;

    //same as the address of the int variable
    cout << "Value that int pointer variable stores: " << pAge << endl;

    //value of age is obtained by deferencing the pointer pAge
    cout << "Value that the int pointer points to: " << *pAge << endl;
    cout << "Address where the int pointer variable is stored: " << &pAge << endl;

    double temperature = 123.4;

    //pass by value: the parameter value in method manipulateByValue gets a copy of the original 
    //temperature variable, and when you manipulate the value variable, it does not change the temperature
    //variable. This is more visible from the fact that the address of the temperature and value variable
    //are totally different.
    cout << "1. Value of temperature: " << temperature << endl;
    cout << "Address of the original temperature variable: " << &temperature << endl;
    manipulateByValue(temperature);
    cout << "4. Value of temperature: " << temperature << endl;

    //pass by reference: The address of the temperature is passed to the manipulateByReference method,
    //which accepts a pointer variable, and by dereferencing and changing the value of the variable,
    //there is a change in the original temperature variable as well.
    cout << "1. Value of temperature: " << temperature << endl;
    cout << "Address of the original temperature variable: " << &temperature << endl;
    manipulateByReference(&temperature);
    cout << "4. Value of temperature: " << temperature << endl;

    /*
    Pointers and Arrays
    */
    string fruits[] = { "apple", "banana", "kiwi" };

    //fruits variable points to the first element in the array, and stores the memory where the first
    //element is stored
    cout << "Value stored in the fruits array variable: " << fruits << endl; //-> prints out 010FF9CC

    //when we access any element inside an array using [], we get the value that the string object
    //is pointing to (i.e. dereferenced) 
    cout << "Value stored in the first element of fruits array variable: " << fruits[0] << endl; //prints apple
    cout << "Value stored in the second element of fruits array variable:" << fruits[1] << endl;//banana
    cout << "Value stored in the third element of fruits array variable:" << fruits[2] << endl;//kiwi

    //the address of the first element of fruits array is the same value stored by the fruits variable
    //itself.
    cout << "Address of the first element of fruits array variable: " << &fruits[0] << endl; //prints 010FF9CC

    //IMP: The subsequent elements in the array are located in memory 28 bytes (= sizeof(string)) after the
    //the first element memory location, i.e. 010FF9CC + 28 = 010FF9E8.
    cout << "Address of the second element of fruits array variable:" << &fruits[1] << endl;
    cout << "Address of the third element of fruits array variable:" << &fruits[2] << endl;

    /*
    STRING class and size() vs sizeof(): When we do sizeof(fruits[0]) (or any array element for that matter)
    we get 28 and not the (number of characters x sizeof(char) in that array element) because 28 is the 
    size of the string object, which has an implementation including a char pointer that stores the actual
    contents of the string. This size of the actual content can be obtained from size() method of string 
    class.
    */
    cout << "Size of fruits array: " << sizeof(fruits) << endl;
    cout << "Size of string: " << sizeof(string) << endl;
    cout << "Size of first string object in array: " << fruits[0].size() << endl;

    //pFruits pointer stores the value stored in fruits, which is the address of the first array element.
    string* pFruits = fruits;

    cout << "Value stored in the fruits pointer variable: " << pFruits << endl;
    cout << "Value pointed by the fruits pointer variable: " << *pFruits << endl;

    //sizeof() returns the size required by the type
    cout << "Size of the string pointer pFruits: " << sizeof(pFruits) << endl; //returns 4 (size of string pointer)
    cout << "Size of a string pointer: " << sizeof(string*) << endl;
    cout << "Size of the first element of pFruits: " << sizeof(pFruits[0]) << endl; //returns 28 (size of string)


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
