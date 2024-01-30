/*
 @filename   stack/nifixToPostfix.cpp
 @author     caonan
 @date       2023-09-14 16:06:40
 @reference  面试收集
 @url
 @brief  中缀表达式转后缀表达式
*/
#include <cassert>
#include <climits>
#include <cstdio>

#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
中缀表达式转后缀表达式（逆波兰表示法）的过程通常使用一个栈来实现。在此过程中，我们需要遵循以下步骤：

1. 初始化一个空栈，用于存储操作符。
2. 从左到右扫描中缀表达式。
3. 遇到操作数时，直接将其添加到后缀表达式中。
4. 遇到操作符时，将其与栈顶的操作符进行优先级比较。
   a. 如果栈为空，或者栈顶操作符为左括号"("，则直接将操作符压入栈。
   b. 如果当前操作符的优先级高于栈顶操作符，也将其压入栈。
   c. 否则，将栈顶操作符弹出并添加到后缀表达式，然后回到步骤4，直到满足条件a或b。
5. 遇到左括号"("时，将其压入栈。
6. 遇到右括号")"时，将栈顶的操作符弹出并添加到后缀表达式，直到遇到左括号"("。然后弹出左括号，但不将其添加到后缀表达式。
7. 当中缀表达式扫描完成后，将栈中剩余的操作符依次弹出并添加到后缀表达式。

现在，我们来看几个具体的例子：

1. 中缀表达式：`a + b`
   后缀表达式：`a b +`

2. 中缀表达式：`a * b + c`
   后缀表达式：`a b * c +`

3. 中缀表达式：`(a + b) * c`
   后缀表达式：`a b + c *`

4. 中缀表达式：`a * (b + c)`
   后缀表达式：`a b c + *`

5. 中缀表达式：`a + b * c - d / e`
   后缀表达式：`a b c * + d e / -`
*/

class Solution {
 public:
  std::string nifix_to_postifix(const std::string& e) {
    auto tokens = string_to_tokens(e);
    std::stack<std::string> symbol;
    std::vector<std::string> express;
    std::unordered_map<std::string, int> p = {{"-", 0}, {"+", 0}, {"/", 1}, {"*", 1}, {"(", 2}};
    for (const auto& t : tokens) {
      if (t == "(" || t == ")" || t == "*" || t == "/" || t == "+" || t == "-") {
        if (t == ")") {
          while (symbol.top() != "(") {
            express.emplace_back(symbol.top());
            symbol.pop();
          }
          symbol.pop();
          continue;
        }

        if (symbol.empty() || p[symbol.top()] < p[t]) {
          symbol.emplace(t);
          continue;
        }

        while (!symbol.empty() && p[symbol.top()] > p[t] && symbol.top() != "(") {
          express.emplace_back(symbol.top());
          symbol.pop();
        }
        symbol.emplace(t);
      } else {
        express.emplace_back(t);
      }
    }

    while (!symbol.empty()) {
      express.emplace_back(symbol.top());
      symbol.pop();
    }

    std::string res;
    for (const auto& s : express) {
      res += s;
    }
    return res;
  }

  std::vector<std::string> string_to_tokens(const std::string& e) {
    std::vector<std::string> tokens;
    int i = 0;
    int j = 0;
    while (i < e.length()) {
      i = e.find_first_of("()+-*/", i);
      if (i == std::string::npos) {
        tokens.emplace_back(e.substr(j));
        break;
      }
      if (i > j) {
        tokens.emplace_back(e.substr(j, i - j));
      }
      tokens.emplace_back(1, e[i]);
      j = ++i;
    }
    return tokens;
  }
};

int main() {
  std::string input = "100+2*300+(2*3+4)/5";
  Solution s;
  auto sret = s.nifix_to_postifix(input);
  std::cout << sret << std::endl;
  return 0;
}
