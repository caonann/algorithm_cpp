/*
 @filename   36.cpp
 @author     caonan
 @date       2022-04-11 13:19:32
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/8Zf90G/
 @brief  根据 逆波兰表示法，求该后缀表达式的计算结果。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0
的情况。

*/
#include <cassert>
#include <cstdio>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int evalRPN(vector<string> &tokens) {
    stack<int> stack_store;
    for (const auto &str : tokens) {
      if (str == "+" || str == "-" || str == "*" || str == "/") {
        int num2 = stack_store.top();
        stack_store.pop();
        int num1 = stack_store.top();
        stack_store.pop();
        switch (str[0]) {
          case '+':
            stack_store.emplace(num1 + num2);
            break;
          case '-':
            stack_store.emplace(num1 - num2);
            break;
          case '*':
            stack_store.emplace(num1 * num2);
            break;
          case '/':
            assert(num2 != 0);
            stack_store.emplace(num1 / num2);
            break;
          default:
            break;
        }
      } else {
        stack_store.emplace(stoi(str));
      }
    }
    return stack_store.top();
  }
};
int main() {
  vector<string> in{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  Solution s;
  int ret = s.evalRPN(in);
  cout << ret << endl;
  return 0;
}
