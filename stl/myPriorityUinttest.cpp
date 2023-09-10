/*
 @filename   myPriorityUinttest.cpp
 @author     caonan
 @date       2022-05-01 12:46:35
 @reference
 @url
 @brief
*/
#include <cassert>
#include <cstdio>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "myPriority.h"
using namespace std;

void uinttest_myheap() {
  vector<int> in{1, 3, 2, 5, 4, 7, 9, 10};
  MyPriority heap(in);

  cout << "top is " << heap.top() << endl;
  heap.push(11);
  cout << "top is " << heap.top() << endl;
  heap.push(0);
  cout << "top is " << heap.top() << endl;
  heap.pop();
  cout << "top is " << heap.top() << endl;
  heap.pop();
  cout << "top is " << heap.top() << endl;
}

int main() {
  uinttest_myheap();
  return 0;
}
