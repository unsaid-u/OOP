#include <bits/stdc++.h>
using namespace std;

// Concepts of Object Oriented Programming using C++
// Object Oriented programming follows a paradigm of representing real life entities in a program
// by creating Objects and classes.

// An Object is an identifiable entity with some characteristics and behaviour. An Object is an instance of a Class.

// -> Class - Building blocks of OOP, User defined data type. Provides the blurprint for creating objects

class example{			//defining a class named 'example'
	
	// members of the class - attributes and behavior
	// everything inside a class in c++ is private by default


public :				// making the elements public explicitly

	string name; 
	int age;		// attributes


	example(string n, int a){		// constructor
									// It is called as an object is invoked
		name = n;
		age = a;
	}

	void introduceyourself(){			//behavior
		cout<<"My name is "<<name<<" and my age is "<<age<<"\n";
	}

};

// Encapsulation is defined as wrapping up of data and information under a single unit.
class encapsulation{

private :
	string name;	// the attributes of a class restricted from direct and easy access, to be saved
	int age; 		// these properties are now encapsulated, hidden with this class

public :
	
	// Instead of directly accessing the attributes, we make them private and create these 'setters' and 'getters' methods of access them
	void setname(string n){
		name = n;
	}

	string getname(){
		return name;
	}

	void setage(int a){			// we can modify our setter functions as we want
		if(a >= 18)
			age = a;
		else
			cout<<"Age must be greater than 18\n";
	}

	// Encapsulation leads to data abstraction or hiding.
};


// Abstraction - the process of hiding the complex background or implementation details and presenting the necessary details to the users
// Abstraction using classes
// An abstract class is a class that is designed to be specifically used as a base class. 
// An abstract class contains at least one pure virtual function. A class derived from an abstract base class will also be abstract unless you override each pure virtual function in the derived class.

class abstractclass{

	virtual void inquiry()=0;		// pure virtual function
};

class absexample:abstractclass{

	// this class will be using the abstract class
	// by overrding the virtual function

	void inquiry(){
		cout<<"virtual function overridden\n";
	}
};


// Inheritance - The capability of a class to derive properties and characteristics from another class is called Inheritance.
// It supports the concept of reusability

class parentclass{
	
	int age;
	string department;

protected:
	string name;

public: 
	parentclass(string n, int a, string dept){
		name = n; 
		age =a ;
		department = dept;
	}

	virtual void show(){		// virtual is written here for demonstrating polymorphism
		cout<<name<<"\n";
	}
};

// Once we create a constructor for a class we lose the default the constructor

class childclass: public parentclass{

public:
	int deptid;	

	childclass(string n, int a, string dept, int depid):parentclass(n,a,dept){
		deptid = depid;
	}

	// we cannot use private attributes of the parent class directly
	// we can use a protected access modifier
	void deptname(){
		cout<<name<<department<<"\n";
	}

	void show(){				// Function overloading
		cout<<"overridden\n";
	}
};


// Polymorphism - 'many' 'forms' In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form.

// The overriding of parent class functions in the child classes is one example of polymorphism

// The most comman use of polymorphism is when a parent class reference is used to refer to a child class

/*C++ supports operator overloading and function overloading.

Operator Overloading: The process of making an operator to exhibit different behaviours in different instances is known as operator overloading.
Function Overloading: Function overloading is using a single function name to perform different types of tasks.

Polymorphism is extensively used in implementing inheritance.
*/


// Dynamic Binding: In dynamic binding, the code to be executed in response to function call is decided at runtime. 
// C++ has virtual functions to support this.

int main(){

	int a;   		// predifined datatype 
	example ex1 = example("Ajay", 62);	// user defined datatype

	ex1.introduceyourself();	// calling a class method 

	childclass c = childclass("Kabir",24,12234);

	parentclass* ptr = &c;		// a pointer of the parent class with a reference of child class
								// operator overloading
	ptr->show();		// as we have the reference of childclass the show() of child will be called
						// that's why we made the show() of parent class virtual, so its most specific implementation can be called
}
