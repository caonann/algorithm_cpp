/*
 @filename   std_string_uinttest.cpp
 @author     caonan
 @date       2022-04-15 11:42:13
 @reference
 @url
 @brief
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "util.h"
using namespace std;

class A
{
   public:
    ~A() { cout << "~A()" << endl; }
};

class B
{
   public:
    ~B() { cout << "~B()" << endl; }
};
class TestStringDestruct
{
   public:
    TestStringDestruct() { s_ = ""; }
    ~TestStringDestruct()
    {
        cout << " ~TestStringDestruct" << endl;
        set_string("123");
    }
    void set_string(string s) { s_ = s; }

   private:
    A a;
    B b;
    string s_;
};
int main()
{
    // std::string默认给申请多大内存空间？
    std::string s1;
    size_t capacity = s1.capacity();
    LOG("capacity %d", capacity);
    for (int i = 0; i < 10000; i++) {
        TestStringDestruct t;
    }
    return 0;
}
