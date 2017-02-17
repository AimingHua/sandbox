#include <iostream>
using namespace std;

class B
{
	public:
		void fun1(int i){cout << "fun1 in B" << endl;};
		void fun3(int i){cout << "fun3 in B" << endl;};
		virtual void fun4(int i){cout << "virtual fun4 in B" <<endl;};
};

class D: public B
{
	public:
		void fun2(int i){cout << "fun2 in D" << endl;};
		using B::fun3;
		void fun3(int i, int j){cout << "fun3 in D" << endl;};
		virtual void fun4(int i){cout << "virtual fun4 in D" <<endl;};
};

int main(void)
{
	B b;
	D d;
	B *pb = &b;

	pb->fun1(2); //call B class fun1
	//pb->fun2(2); //error: 'class B' has no member named 'fun2'
	pb->fun3(2); //call D class fun3
	pb->fun4(2); //call D class fun3
    
	cout << "*************************" << endl;

	pb = &d;
	pb->fun1(2); //call B class fun1
	//pb->fun2(2); //error: 'class B' has no member named 'fun2'
	pb->fun3(2); //call D class fun3
	pb->fun4(2); //call D class fun3

	cout << "*************************" << endl;
	D *pd = &d;
	pd->fun1(2); //call B class fun1
	pd->fun2(2); //call D class fun2
	pd->fun3(2); //call D class fun3
	pd->fun3(2,2); //call D class fun3
	pd->fun4(2); //call D class fun4
}
