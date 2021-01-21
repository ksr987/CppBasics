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
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
