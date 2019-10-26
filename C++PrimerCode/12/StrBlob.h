
#ifndef STRBLOB_H
#define STRBLOB_H

#include "Version_test.h"

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

#ifdef LIST_INIT
#include <initializer_list>
#endif

// forward declaration needed for friend declaration in StrBlob
class StrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;

	// constructors分配一个空的vector
    StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
#ifdef LIST_INIT
   //通过拷贝列表中的值来初始化vector的元素
    StrBlob(std::initializer_list<std::string> il);
#else
	StrBlob(std::string *, std::string*);  
#endif

	// size operations
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

	//添加和删除元素
    // add and remove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

	//访问元素
    // element access
    std::string& front();
    std::string& back();

	// interface to StrBlobPtr
	StrBlobPtr begin();  // can't be defined until StrBlobPtr is
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data; 
    // throws msg if data[i] isn't valid
	//data[i]不合法，抛出异常
    void check(size_type i, const std::string &msg) const;
};

// constructor
#ifdef LIST_INIT
inline
StrBlob::StrBlob(std::initializer_list<std::string> il): 
              data(std::make_shared<std::vector<std::string>>(il)) { }
#else
inline
StrBlob::StrBlob(std::string *b, std::string *e):
              data(std::make_shared<std::vector<std::string>>(b,e)) { }
#endif

// StrBlobPtr throws an exception on attempts to access a nonexistent element 
class StrBlobPtr {
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }

    std::string& deref() const; //提领，取值的意思
    StrBlobPtr& incr();       // prefix version，返回值是类的引用
    StrBlobPtr& decr();       // prefix version
private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<std::string>> 
        check(std::size_t, const std::string&) const;

    // store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;  //定义为弱指针
    std::size_t curr;      // current position within the array，当前的指针值
};

//提领值
inline
std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end"); 
    return (*p)[curr];  // (*p) is the vector to which this object points
}

inline
std::shared_ptr<std::vector<std::string>> 
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();   // is the vector still around?
    if (!ret)//throw抛出异常
        throw std::runtime_error("unbound StrBlobPtr");

    if (i >= ret->size()) 
        throw std::out_of_range(msg);
    return ret; // otherwise, return a shared_ptr to the vector
}

// prefix: return a reference to the incremented object
inline
StrBlobPtr& StrBlobPtr::incr()
{
    // if curr already points past the end of the container, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    ++curr;       // advance the current state
    return *this; //返回当前对象
}

inline
StrBlobPtr& StrBlobPtr::decr()
{
    // if curr is zero, decrementing it will yield an invalid subscript
    --curr;       // move the current state back one element}
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

// begin and end members for StrBlob
inline
StrBlobPtr
StrBlob::begin() 
{
	return StrBlobPtr(*this);
}

inline
StrBlobPtr
StrBlob::end() 
{
	auto ret = StrBlobPtr(*this, data->size());
    return ret; 
}

// named equality operators for StrBlobPtr
//比较两个对象是否相等
inline
bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	// if the underlying vector is the same 
	if (l == r) 
		// then they're equal if they're both null or 
		// if they point to the same element
		return (!r || lhs.curr == rhs.curr);
	else
		return false; // if they point to difference vectors, they're not equal
}

//求补
inline
bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !eq(lhs, rhs); 
}
#endif
