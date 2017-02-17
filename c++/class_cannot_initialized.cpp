/* what situation class can't instantiate
 * 1. class has a pure virutal function
 * 2. private constructor function */

#include <iostream>
using namespace std;

//class A is abstract class
class A{
	public:
		A();
		~A();
		virtual void doSomething() = 0;
};

A::A()
{
    cout << "A::A() constructor" << endl;
}

A::~A()
{
    cout << "A::~A() destructor" << endl;
}

class B{
	private:
		B() { cout << "B::B() constructor" << endl;};
	public:
		~B() { cout << "B::~B() destructor" << endl;};
};

int main(void)
{
    A a; //abstract class can't be instantiated
    B b; //private constructor can't be instantiated
    return 0;
}
