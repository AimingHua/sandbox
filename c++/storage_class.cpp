#include <iostream>
using namespace std;
/*
Storage class of a variable defines the "lifetime" and "visibility" of a variable
1. lifetime:  the duration till which the variable remains active
2. visibility: defines in which module of the program the variable is accessible
There are five types of storage classes in C++
1. automactic, default storage class
2. external 
3. static 
4. register
5. mutable
----------------------------------------------------------------------------
|Storage Class | Keyword   | Lifetime	      | Visibility  | Initial Value |
----------------------------------------------------------------------------
|Automatic     | auto	   | Function Block   | Local	    | Garbage       |
|Register      | register  | Function Block   | Local	    | Garbage       |
|External      | extern	   | Whole Program    | Global	    | Zero          |
|Static	       | static	   | Whole Program    | Local	    | Zero          |
|Mutable       | mutable   | Class	      | Local	    | Garbage       |
----------------------------------------------------------------------------
*/
void fun_auto()
{
    auto int a;
    int b=2;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl; 
}

int main()
{
    fun_auto();
}
