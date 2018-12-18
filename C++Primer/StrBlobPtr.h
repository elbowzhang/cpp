#ifndef STRBLOBPTR_H_
#define STRBLOBPTR_H_

#include <iostream>
#include <memory>
#include <vector>
#include "StrBlob.h"

using namespace std;

//对于访问一个不存在元素的测试，StrBlobPtr会抛出一个异常
class StrBlobPtr{
  public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string &deref() const;
    StrBlobPtr &incr();     //前缀递增

  private:
    //若检查成功，check返回一个指向vector的shared_ptr
    shared_ptr<vector<string>> check(size_t, const string &) const;
    //保存一个weak_ptr意味着底层vector可能会被销毁
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if(!ret)
        throw runtime_error("unbound StrBlobPtr");
    if(i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr & StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

#endif