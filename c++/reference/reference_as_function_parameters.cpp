#include <iostream>
using namespace std;

class A
{
	public:
		A(); //constructor 
		A(const A &b); //copy constructor
		~A(); //destructor

    private:
		int a;
};

A::A()
{
	a = 0;
    cout << "A constructor" << endl;
}

A::A(const A &b)
{
	a = b.a;
	cout << "A copy constructor" << endl;
}

A::~A()
{
	cout << "A destructor" << endl;
}

void pass_by_value(A c)
{
	//pass by value will construct object c using copy constructor
    cout << "pass by value" << endl;
}

void pass_by_reference(A &c)
{
	//pass by reference will't generate variable 
    cout << "pass by reference" << endl;
}

void pass_by_address(A *c)
{
	//pass by address will generate a pointer variable 
    cout << "pass by address" << endl;
}

A a;
int main()
{
	cout << "Enter main()" << endl;
	pass_by_value(a);
	pass_by_reference(a);
	pass_by_address(&a);
}
