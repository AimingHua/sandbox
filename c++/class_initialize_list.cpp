/*const and reference variables must initialized in intial list*/
#include <iostream>
using namespace std;
class Exam {
	public:
		Exam(int val);
		~Exam();
	private:
		const int a;
		int &b;
};

//const a and reference b must initialized in initial list
Exam::Exam(int val):a(1), b(val)
{
    //a = 1;
    //b = val;
}

Exam::~Exam()
{
    cout << a << endl;
    cout << b << endl;
}

int main(void)
{
    int x = 10;
    Exam ex(x);
    return 0;
}
