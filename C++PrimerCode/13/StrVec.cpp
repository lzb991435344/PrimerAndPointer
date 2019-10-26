
#include "StrVec.h"

#include <string>
using std::string;

#include <memory>
using std::allocator;//使用的内存分配器

// errata fixed in second printing -- 
// StrVec's allocator should be a static member not an ordinary member

// definition for static data member
//定义静态数据
allocator<string> StrVec::alloc;  

// all other StrVec members are inline and defined inside StrVec.h
