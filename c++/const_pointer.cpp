#include <iostream>
using namespace std;

int main()
{
	double f = 2.4;
	double e = 0.25;
	const double pi = 3.14;

	const double *p1 = &pi;
	double const *p2 = &pi; //"const double *p1" same with "double const *p1"
	//compile error: assignment of read-only location
	//*p1 = 3.2;
	
	//compile error: invalid conversion from 'const double*' to 'double*'
	//double *p3 = &pi;

	//compile error: invalid conversion from 'const double*' to 'double*'
	//double * const p4 = &pi;
	
	double * const p5 = &e;
	//compile error: assignment of read-only variable 'p5'
	//p5 = &f;

	cout << "*p1= " << *p1 << endl;
	cout << "*p5= " << *p5 << endl;

	return 0;
}
