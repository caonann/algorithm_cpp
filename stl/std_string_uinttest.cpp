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

class A {
 public:
  ~A() { cout << "~A()" << endl; }
};

class B {
 public:
  ~B() { cout << "~B()" << endl; }
};
class TestStringDestruct {
 public:
  TestStringDestruct() { s_ = ""; }
  ~TestStringDestruct() {
    cout << " ~TestStringDestruct" << endl;
    set_string("123");
  }
  void set_string(string s) { s_ = s; }

 private:
  A a;
  B b;
  string s_;
};
int main() {
  // std::string默认给申请多大内存空间？
  std::string s1;
  size_t capacity = s1.capacity();
  LOG("capacity %ld", capacity);
  for (int i = 0; i < 1; i++) {
    TestStringDestruct t;
  }

  string s2 = "hello world";
  auto substr = s2.substr(3, 4);  // copy semantic
  cout << "sub str s2 is :" << substr << endl;
  std::reverse(substr.begin(), substr.end());
  cout << "the whole str s2 is :" << s2 << endl;
  return 0;
}
