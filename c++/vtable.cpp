#include <iostream>
using namespace std;

class B
{
	public:
		virtual void function1(){ cout << "B::function1()" << endl;};
		virtual void function2(){ cout << "B::function2()" << endl;};
};

class D1: public B
{
	public:
		virtual void function1(){ cout << "D1::function1()" << endl;};
};

class D2: public B
{
	public:
		virtual void function2(){ cout << "D2::function2()" << endl;};
};

int main()
{
	B b;
	D1 d1;
	D2 d2;
	B *ptr = &b;

	ptr->function1();
	ptr = &d1;
	ptr->function1();
	ptr = &d2;
	ptr->function1();

	cout << sizeof(b) << endl;

    return 0;
}
