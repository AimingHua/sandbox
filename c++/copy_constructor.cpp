#include <iostream>
using namespace std;

class B
{
	public:
		B();
		B(const B &a);

		int i;
};

B::B()
{
	i = 1;
	cout << "constructor" << endl;
}

B::B(const B &a)
{
	i = a.i;
	cout << "copy constructor" << endl;
}

void fun(B b)
{
}

B fun2()
{
	B b;
	return b;
}

int main()
{
	//B b;
	//fun(b);
	fun2();
	return 0;
}
