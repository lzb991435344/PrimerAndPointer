

// reference counted version of HasPtr
#include <string>

#include <cstddef>

class HasPtr {
public:
	// constructor allocates a new string and a new counter, 
	// which it sets to 1
	//构造函数初始化
    HasPtr(const std::string &s = std::string()): 
	  ps(new std::string(s)), i(0), use(new std::size_t(1)) {}

	// copy constructor copies all three data members 
	// and increments the counter
	//拷贝构造函数，增加引用计数
    HasPtr(const HasPtr &p): 
		ps(p.ps), i(p.i), use(p.use) { ++*use; }

	//赋值构造函数	
	HasPtr& operator=(const HasPtr&);

	~HasPtr();

	// move constructor takes over the pointers from its argument
	// and makes the argument safe to delete
	HasPtr(HasPtr &&p): ps(p.ps), i(p.i), use(p.use) 
		{ p.ps = 0; p.use = 0; }

	HasPtr &operator=(HasPtr&&);

private:
    std::string *ps;
    int    i;
	std::size_t *use;  // member to track how many objects share *ps
};

//析构函数
HasPtr::~HasPtr()
{
	//引用计数为0时，释放成员指针
	if (--*use == 0) {   // if the reference count goes to 0
		delete ps;       // delete the string
		delete use;      // and the counter
	}
}

//赋值构造函数
HasPtr &
HasPtr::operator=(HasPtr &&rhs)
{
	//判断当前对象是否和参数相等
	if (this != &rhs) {
		if (--*use == 0) {   // do the work of the destructor
			delete ps;
			delete use;
		}
		//移动构造函数
		ps = rhs.ps;         // do the work of the move constructor
		i = rhs.i;
		use = rhs.use;
		ps = 0; use = 0;
	}
	return *this;//返回当前对象的引用
}

HasPtr& HasPtr::operator=(const HasPtr &rhs) 
{
	++*rhs.use;  // increment the use count of the right-hand operand
	if (--*use == 0) {   // then decrement this object's counter
		delete ps;       // if no other users 
		delete use;      // free this object's allocated members
	}
	//拷贝数据
	ps = rhs.ps;         // copy data from rhs into this object
	i = rhs.i;
	use = rhs.use; 
	return *this;        // return this object
}
//拷贝构造函数
HasPtr f(HasPtr hp) // HasPtr passed by value, so it is copied
{
	HasPtr ret;
	ret = hp;        // assignment copies the given HasPtr
	// proces ret
	return ret;      // ret and hp are destroyed，引用计数为0
}

int main()
{ 
	HasPtr h("hi mom!");//直接初始化
	//没分配内存，只是进行拷贝
	HasPtr h2 = h;  // no new memory is allocated, 
	                // h and h2 share the same underlying string
} 

