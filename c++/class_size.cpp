#include <iostream>
using namespace std;

class Empty{};
class A: public Empty
{
	private:
		int i;
};
class B
{
	public:
		void foo(void) { cout << "foo" << endl;};
		void foo1(void) { cout << "foo1" << endl;};
		void foo2(void) { cout << "foo2" << endl;};
};
class C
{
	public:
		virtual void display(void){};
};
int main()
{
	Empty e;
	A a;
	B b;
	C c;
	cout << "sizeof(e)=" << sizeof(e) << endl; //1: size of empty class is not zero, but 1
	cout << "sizeof(a)=" << sizeof(a) << endl; //4: compiler optimize the base emtpy class 
	cout << "sizeof(b)=" << sizeof(b) << endl; //1: no data member, function is put in other place
	cout << "sizeof(c)=" << sizeof(c) << endl; //8: virtual function table pointer vptr, for X64
	//1:4:1:8
	return 0;
}
