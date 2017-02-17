#include <iostream>
using namespace std;
/*
1. The this pointer is a pointer accessible only within the member functions of a class, struct, or union type. 
2. It points to the object for which the member function is called. 
3. Static member functions do not have a this pointer. 
4. When a nonstatic member function is called for an object, the address of the object is passed as a hidden argument to the function
*/

class A
{
	public:
		A();
		void fun1();
		void set(int i);
		//operator must return A&, otherwise compile error: ISO C++ forbids declaration of 'operator=' with no type
		A& operator=(const A &right); //must use const A& as paramter
		static void fun2();

	private:
		int i;
};

A::A()
{
	i=1;
}

void A::fun1()
{
	//this pointer points to objects for which the memnber function is called
	cout << "member function" << endl;
	cout << "this="  << this << endl;

	cout << "i= " << i << endl; //imply call i->i
	cout << "this->i= " << this->i << endl; //explicitly call this->i, it's works but unnecessary
}

//case1: must use this pointer to disambiguate class member and local variable
void A::set(int i)
{
	//i = i; //compile ok, but will not set data member i to parameter i, don't change i value
	this->i = i; //it's works, can tell which i is member data and parameter 
}

//case2: must use this pointer, no alternative, support method chaining
A& A::operator=(const A& right)
{
	i = right.i;
	return *this;
}

void A::fun2()
{
	cout << "static member function" << endl;

	//static member function can't access no-static data member
	//cout << "i= " << i << endl;

	//'this' is unavailable for static member functions
	//cout << "this->i= " << this->i << endl;
}

int main()
{
    A a,b;
	a.set(5);
	a.fun1(); //nonstatic member function call from object a, same with call A::fun1(&a);
	b.fun1();
	//A::fun1(&a); //we can't call like this, member function can't be call by class
	a.fun2();
}
