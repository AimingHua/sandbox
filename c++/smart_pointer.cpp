#include <iostream>
using namespace std;

class smartPtr {
	friend HasPtr;
    private:
	    int *p;
	    size_t use;
    public:
	    smartPtr(int *ptr):p(ptr),use(1) {};
	    ~smartPtr() { delete p;};
};

class HasPtr {
    private:
	    smartPtr *ptr;
	    int val;
    public:
	    HasPtr():ptr(NULL),val(0) {};
	    HasPtr(int *p, int v):ptr(p),val(v) {};
	    HasPtr(const HasPtr &h):ptr(h.ptr),val(h.val) {};

	    HasPtr & operator=(const HasPtr &);
	    ~HasPtr();
	    int get_int() const;
	    void set_int(int v);
	    int * get_ptr() const;
	    void set_ptr(int *p);
};

HasPtr & HasPtr::operator=(const HasPtr &a)
{
	val = a.val;
	ptr = a.ptr;
	return *this;
}

HasPtr::~HasPtr()
{
    if(0==--ptr->use) 
        delete ptr;
}

int HasPtr::get_int() const
{
    return val;
}

void HasPtr::set_int(int v)
{
    val = v;
}

void HasPtr::set_ptr(int *p)
{
    ptr->p = p;
}

int *HasPtr::get_ptr() const
{
    return ptr->p;
}

