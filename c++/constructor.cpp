#include <iostream>
using namespace std;

/*
 * depending parameters, there are following constructor types:
 * 1. "default"    constructor function: compiler will provide a default constructor if no any constructor
 * 2. "overload"   constructor function: general constructor function, there may be serveral overload constructors
 * 3. "copy"       constructor function: compiler will provide a copy constructor if user not define copy constructor
 * 4. "convertion" constructor function: constructor a object depending on another type object
 * */

class Point
{
	public:
		Point() //default constructor function
		{
			x = 0.0;
			y = 0.0;
			cout << "Default constructor" << endl;
		}
		Point(const Point &pt) //copy constructor function
		{
			x = pt.x;
			y = pt.y;
			cout << "Copy constructor" << endl; 
		}
		Point(double xx, double yy) //general or overload constructor function
		{
			x = xx;
			y = yy;
			cout << "General/Overload constructor" << endl;
		}
		Point(double pos) //convertion constructor function
		{
			x = pos;
			y = pos;
			cout << "Convertion constructor" << endl;
		}

		Point & operator=(const Point &pt) //overload = operator
		{
		    if(this==&pt)
				return *this;
			
			this->x = pt.x;
			this->y = pt.y;
			cout << "Overload operator =" << endl;
			return *this;
		}

	private:
		double x;
		double y;
};

void fun1(Point pt)
{
}

Point fun2(void)
{
	Point pt;
	return pt;
}

int main()
{
	Point p1; //call default constructor function
	Point p2(1.1, 2.2); //call general/overload constructor function
	Point p3 = Point(2.0, 3.0); //call general/overload constructor function
	p1 = p3; //call operator+ function, being p1 and p3 are allready created 
	Point p4(2.0); //call convertion constructor function
	p2 = 3.0; //call convertion constructor function and then call operator+ function 
	Point p5(p1); //call copy constructor function
	Point p6 = p1; //call copy constructor function
    cout << "***************************" << endl;
    fun1(p1); //pass_by_value will call class Point copy constructor
	fun2();
	
}
