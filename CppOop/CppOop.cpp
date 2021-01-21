#include <iostream>
#include <sstream>
#include "Cat.h"
#include "Person.h"

using namespace std;

int main()
{

    //define a class Cat in the appropriate header file, and provide the required prototypes with it.
    //The prototypes are grouped by the access modifiers. When implementing the methods in Cat.cpp, 
    //use the signature 'classname'::'methodname' to specify which method does the class belong to.

    //no need to use the new keyword for initializing an object of a class.
    Cat cat1;

    //remember to include classname before the method name in Cat.cpp, since when a private data member
    //is included in the Cat class, you want to ensure that that data member is accessed only by the 
    //methods of Cat class.

    //remember to initialize the instance variables like happy, if not initialized they will be assigned
    //random values causing inconsistencies in the program.  
    cat1.setHappy(false);
    cat1.speak();
    cat1.jump();

    //you can specifically deallocate memory using {} if you want, even before the method finishes. Eg:
    {
        Cat cat2;
        cat2.speak();
        //cat2 destructor is called immediately after this
        cout << "destroying cat 2" << endl;
    }

    
    //in c++, you cannot concatenate string and int using a + sign. You have to use string stream 
    //library for it. include the appropriate import at the top of the class, and use it as follows:
    string name = "ketan";
    int age = 22;
    
    stringstream ss;
    ss << "Name is: ";
    ss << name;
    ss << "; Age is: ";
    ss << age;

    string info = ss.str();
    cout << info << endl;

    /*
    Constructor initialization lists:  instead of passing parameters to the constructor and assigning
    the data members to those parameters, you can use shortcuts of constructor initialization lists
    to assign the data members. Example is given in the Person.cpp class and Person.h header.
    */
    Person person1;
    Person person2("Ketan", 22);

    cout << person1.toString() << endl;
    cout << person2.toString() << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
