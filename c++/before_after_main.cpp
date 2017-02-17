/*what to do before main() and after main()*/
#include <iostream>
using namespace std;

class A {
	public:
		A() { cout << "A::A() constructor" << endl;};
		~A() { cout << "A::~A() destructor" << endl;};
};

//A a;
int atexit(void (*function)(void));
void fun1(void);
void fun2(void);

int main(void)
{
    cout << "start of main()" << endl;
    //atexit(fun1);
    //atexit(fun2);
    static A a;
    cout << "end of main()" << endl;
}

void fun1(void)
{
    cout << "fun1()" << endl;
}

void fun2(void)
{
    cout << "fun2()" << endl;
}
