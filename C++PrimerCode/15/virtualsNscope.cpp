//1
#include <iostream>
using std::cout; using std::endl;

class Base {
public:
    virtual int fcn();//虚函数，希望子类中进行override
};

int Base::fcn() { cout << "Base::fcn()" << endl; return 0; }

class D1 : public Base {
public:
    // hides fcn in the base; this fcn is not virtual
    // D1 inherits the definition of Base::fcn() 
    int fcn(int);      // parameter list differs from fcn in Base
	virtual void f2(); // new virtual function that does not exist in Base
};

int D1::fcn(int) { cout << "D1::fcn(int)" << endl; return 0; }
void D1::f2() { cout << "D1::f2()" << endl; }

class D2 final : public D1 {
public:
    int fcn(int); // nonvirtual function hides D1::fcn(int)
    int fcn();    // overrides virtual fcn from Base
	void f2();    // overrides virtual f2 from D1
};

int D2::fcn(int) { cout << "D2::fcn(int)" << endl; return 0; }
int D2::fcn() { cout << "D2::fcn()" << endl; return 0; }
void D2::f2() { cout << "D2::f2()" << endl; }

int main()
{
    D1 dobj, *dp = &dobj;
    dp->fcn(42); // ok: static call to D1::fcn(int)

    Base bobj; 
	D1 d1obj;
	D2 d2obj;

	//父类的指针指向子类的对象
    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;//分别指向D1,D1,D2
	//以下都是无参构造函数
    bp1->fcn(); // virtual call, will call Base::fcn at run time
    bp2->fcn(); // virtual call, will call Base::fcn at run time
    bp3->fcn(); // virtual call, will call D2::fcn at run time

	D1 *d1p = &d1obj;//指向D1
	D2 *d2p = &d2obj;//指向D2
	d1p->f2(); // virtual call, will call D1::f2() at run time
	d2p->f2(); // virtual call, will call D2::f2() at run time

	Base *p1 = &d2obj; //指向D2
	D1 *p2 = &d2obj;//指向D2
	D2 *p3 =  &d2obj;//指向D2
	p2->fcn(42);  // statically bound, calls D1::fcn(int)
	p3->fcn(42);  // statically bound, calls D2::fcn(int)

    Base* bp = &d1obj;//指向D1
	D1 *dp1 = &d2obj; //指向D2
	D2 *dp2 = &d2obj;//指向D2
    dp1->fcn(10); // static call to D1::fcn(int)
    dp2->fcn(10); // static call to D2::fcn(int)
}

