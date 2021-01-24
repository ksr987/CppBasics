#include <iostream>
#include "Animal.h";
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

void manipulateReferenceVariable(double& value) {
    //address of the value variable in this method and main method is same, thus manipulation occurs.
    cout << "Address of the reference value variable: " << &value << endl;
    value = 123.4;
}

Animal badCreateAnimal() {
    //default constructor invoked
    Animal a;
    a.setName("Bertie");
    //copy constructor invoked when an object is returned from a function
    return a;
}

Animal& badCreateAnimal2() {
    Animal a;
    a.setName("Bertie");

    //A reference variable is returned to avoid invoking the copy constructor (invoked when return type 
    //is object). This avoid creating a duplicate variable to be returned by the method.
    return a;
}

Animal* goodCreateAnimal() {
    Animal* a = new Animal();
    a->setName("Bertie");
    return a;
}

void passArrayToFunction1(string texts[],const int nElements) {

    cout << sizeof(texts) << endl; //prints 4 (size of pointer) and not (28*3). We lose the info about the
                                   //no of elements in the array. Thus, nElements is passed as parameter.
    for (int i = 0; i < nElements; i++) {
        cout << texts[i] << endl;
    } 
}

void passArrayToFunction2(string *texts, const int nElements) {

    cout << sizeof(texts) << endl; //prints 4 (size of pointer) and not (28*3). We lose the info about the
                                   //no of elements in the array. Thus, nElements is passed as parameter.
    for (int i = 0; i < nElements; i++) {
        cout << texts[i] << endl;
    }
}

//without the need to pass the number of elements as param
void passArrayToFunction3(string (&texts)[3]) {

    cout << sizeof(texts) << endl; //prints 4 (size of pointer) and not (28*3). We lose the info about the
                                   //no of elements in the array. Thus, nElements is passed as parameter.
    for (int i = 0; i < sizeof(texts); i++) {
        cout << texts[i] << endl;
    }
}

//BAD FUNCTION: Never return a pointer to a local variable from a function. Dont do this!
string* returnArrayFromFunction() {

    string texts[] = { "one", "two", "three" };
    return texts;
}

//GOOD FUNCTION: Since the string pointer is created using new operator, it will only get deallocated 
//using the delete keyword, so it is available even outside the method scope.
string* returnArrayFromFunction2() {
    string *texts = new string[3];
    return texts;
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
    cout << "Size of fruits array: " << sizeof(fruits) << endl; //28*3=84
    cout << "Size of string: " << sizeof(string) << endl; //28 bytes
    cout << "Size of first string object in array: " << fruits[0].size() << endl; //5

    //pFruits pointer stores the value stored in fruits, which is the address of the first array element.
    string* pFruits = fruits;

    cout << "Value stored in the fruits pointer variable: " << pFruits << endl; //010FF9CC
    cout << "Value pointed by the fruits pointer variable: " << *pFruits << endl; //apple

    //sizeof() returns the size required by the type
    cout << "Size of the string pointer pFruits: " << sizeof(pFruits) << endl; //returns 4 (size of string pointer)
    cout << "Size of a string pointer: " << sizeof(string*) << endl;
    cout << "Size of the first element of pFruits: " << sizeof(pFruits[0]) << endl; //returns 28 (size of string)

    /*
    Incrementing pointers: when you increment pFruits (pFruits++), the pointer automatically points to the
    next element of the fruits array. The pointer increment will make the pFruits pointer point to a memory
    28 bytes (sizeof(string)) more than the initial memory it was pointing to.
    Example given:
    */

    for (int i = 0; i < sizeof(fruits) / sizeof(string); i++) {
        cout << *pFruits << " " << pFruits << " " << flush;
        pFruits++;
    }
    cout << endl;

    pFruits = fruits;
    string* pFruitsEnd = &fruits[3];

    //decrementing pointers: points to the required block of memory previous to the current one.
    pFruitsEnd -= 2;

    //prints banana since pFruitsEnd points to fruits[3] initially, and we only have 3 elements in fruits.
    cout << *pFruitsEnd << endl; 

    //subtracting 2 pointers 
    pFruitsEnd = &fruits[3];
    int numElements = pFruitsEnd - pFruits; 
    //prints 3
    cout << numElements << endl;

    //const- like final, cannot change value later (cannot do PI = 4.5) 
    const double PI = 3.14;
    
    //different ways to initialize char arrays
    char greeting[] = { 'h', 'e', 'l', 'l', 'o' };

    //c++ automatically converts the below statement to a char array
    char greeting2[] = "hello";

    /*
    When a char array is declared with a string, the size of the char array is 1 more than the total num
    of characters in it, as the last character is an empty char denoting the end of the string. 
    */

    //prints 6
    cout << sizeof(greeting2) / sizeof(char) << endl;
    //prints 5 since this was declared like an array.
    cout << sizeof(greeting) / sizeof(char) << endl;


    /*
    Reference Variables: using method manipulateByReference(), if we passed the pointer as parameter to
    mBR(), we changed the value held in that address. This was not achieved in mBP(). Reference variables
    are defined with an & sign while declaring (like double &value = 2). If passed as the parameter to a 
    method, it serves the same purpose as mBR(), it changes the value held in that address. Reference variables
    are alias to the original variable.
    */

    int refVar = 2.5;
    int& refVar2 = refVar;
    
    refVar2 = 12;
    cout << refVar << endl; //prints 12 since ref variable has the same address has the original variable.

    //compile time error below since reference variables cant hold a new integer (they dont have their own 
    //memory),they only hold references to existing integers.
    //  int& refVar3 = 4;

    double value = 4.321;

    //pass by value
    cout << "Address of the original value variable: " << &value << endl;
    manipulateByValue(value);
    cout << value << endl; //-> prints 4.321 ( no change in value outside the mBP() method)

    value = 4.321;
    //pass by reference
    cout << "Address of the original value variable: " << &value << endl;
    manipulateByReference(&value);
    cout << value << endl; //-> prints 123.4 (change in value variable)
    
    value = 4.321;
    //using reference variables
    cout << "Address of the original value variable: " << &value << endl;
    manipulateReferenceVariable(value);
    cout << value << endl; //-> prints 123.4 (change in value variable)


    /*
    const keyword for variables: once declared const, a variable cannot be changed later.
    const for methods: once declared const, a method cannot change the data members of an object
    in a class inside that method. Example given in speak() method of Person.cpp. A const for a method
    should be used when no change in the instance data of an object happens.
    */

    //const for pointers -> trick is to read the type of the pointer backwards.
    int constValue = 8;
    int* pConstValue = &constValue;

    cout << *pConstValue << endl; //prints 8

    int constValue2 = 11;

    //Error with this: int* const pConstValue = &constValue
    //Read backwards: constant pointer to an int, means the pointer value cannot be changed, or the memory
    //it points to cannot be changed.
    pConstValue = &constValue2; //change the pointer value (address it points to)

    cout << *pConstValue << endl; //prints 11
    
    //Error with this: const int* pConstValue = &constValue
    //Read backwards: pointer to a constant int, means int is constant (cannot change), or the value
    //the pointer memory points to cannot be changed.
    *pConstValue = 12; //change the value pointed by pointer (value at the address it points to)

    cout << *pConstValue << endl; //prints 12

    //can use const multiple times -> both lines will give error then
    //const int* const pConstValue = &constValue;

    /*
        Copy constructors
    */
    Animal animal1;
    animal1.setName("Freddy");

    //this line is where the copy constructor is invoked. Unlike Java, when you run the below line, it 
    //creates a second object animal2 by calling the copy constructor, copies all the instance members from
    //animal1 to animal2 (i.e. name of animal1 is being set to animal2 name) and any change in animal2 
    //object does not affect animal1. The default copy constructor is called unless you override it with
    //your own. Copy constructor is defined in Animal.h Check Animal.cpp for const reference.
    Animal animal2 = animal1;

    animal1.speak(); //prints Freddy
    animal2.speak(); //prints Freddy

    animal2.setName("Bob");

    animal1.speak(); //prints Freddy
    animal2.speak(); //prints Bob

    //another way to invoke copy constructor
    Animal animal3(animal1);
    animal3.speak();

    //new operator: Remember to deallocate memory used by the object created by new operator. Destructor
    //is not called by default for objects created by new operator.
    Animal* pCat1 = new Animal();
    pCat1->setName("Freddy");
    pCat1->speak();
    cout << sizeof(Animal *) << endl; //prints 4 (size of a pointer is fixed for a machine-generally 4 bytes)

    //deallocate
    delete pCat1;

    //importance of pointers

    //Example 1: returning an Animal object, very inefficient since copy constructor is called multiple
    //times.
    
    //copy constructor invoked
    /*
    Animal frog1 = badCreateAnimal();
    frog1.speak();
    */

    //Example 2: returning a reference variable of Animal -> highly risky since trying to access a local
    //variable which is out of scope of the main method

    //trying to access variable 'a' outside the scope of badCreateAnimal2(). 
    /*
    Animal& frog2 = badCreateAnimal2();
    frog2.speak();
    */

    //Example 3: use pointers- good way
    //When returning a pointer, you only return fixed bytes of memory (4/8 bytes). Even if Animal object is
    //really huge, we dont have to create copies of those animal objects. Can simply pass pointers pointing
    //to them.
    Animal* frog3 = goodCreateAnimal();
    frog3->speak();
    //deallocate
    delete frog3;

    //create object using new operator
    Animal* pAnimal = new Animal();
    cout << pAnimal << endl; //prints the memory location where pointer pAnimal resides

    //create multiple Animal objects using new operator
    Animal* pAnimalList = new Animal[10];
    pAnimalList[5].setName("George");
    pAnimalList[5].speak();

    delete pAnimal;

    //deallocation for a list of objects
    delete[] pAnimalList;

    string charToString = string(5, 'a'); //-> convert char to string. prints "aaaaa"

    Animal* pAnimalExercise = new Animal[26];

    char chPointer = 'a';
    for (int i = 0; i < 26; i++) {
        pAnimalExercise[i].setName(string(1, chPointer));
        pAnimalExercise[i].speak();
        chPointer++;
    }

    delete[] pAnimalExercise;

    //Arrays and functions
    string texts[] = { "apple", "orange" , "banana" };

    cout << sizeof(texts) << endl; //prints 28*3=84 bytes
    //different ways to pass arrays as a function parameter
    passArrayToFunction1(texts, 3);
    passArrayToFunction2(texts, 3);

    //passing array without specifying the number of elements
    passArrayToFunction3(texts);

    //returning array as a function

    // returnArrayFromFunction(); -> NEVER DO THIS-> Look at method for more details

    string* arr = returnArrayFromFunction2(); //return string pointer instead
    delete[] arr;


    /*
    Namespaces: Way to avoid conflicts between classes/global variables with same name. 2 classes with the
    same name can exist but in different namespaces. These are useful when you want to use your own 
    implementation of a certain method of a class, so you include the statement: 'using namespace <name>'
    at the top of your cpp file. And when you define the class in the header file, enclose the class in a
    namespace. 
    */
    
    //example- defining
    //namespace ksr {
    //    class Cat {
    //        //class implementation
    //    public:
    //        void speak();
    //    };
    //}

    //using a namespace
    //ksr::Cat c1;
    //c1.speak();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
