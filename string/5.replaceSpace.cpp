// https://leetcode.cn/problems/ti-huan-kong-ge-lcof/submissions/?envType=study-plan-v2&envId=coding-interviews

#include <iostream>
using namespace std;

class Solution {
 public:
  string replaceSpace(string s) {
    string new_s;
    for (auto& c : s) {
      if (c != ' ') {
        new_s += c;
      } else {
        new_s += "%20";
      }
    }
    return new_s;
  }
};

class Solution2 {
 public:
  string replaceSpace(string s) {
    int count = 0;
    int len = s.size();
    for (const auto& c : s) {
      if (c == ' ') {
        count += 2;
      }
    }

    s.resize(len + count);
    for (int i = len - 1, j = s.size() - 1; i < j; --i, --j) {
      if (s[i] != ' ') {
        s[j] = s[i];
      } else {
        s[j] = '0';
        s[j - 1] = '2';
        s[j - 2] = '%';
        j -= 2;
      }
    }
    return s;
  }
};

int main() {
  Solution2 sol;
  string s = "We are happy.";
  cout << sol.replaceSpace(s) << endl;
  string ss = "aaa";
  printf("size %lu ,length %lu \n", ss.size(), ss.length());
  ss.resize(5);
  printf("size %lu ,length %lu \n", ss.size(), ss.length());
  ss.resize(2);
  printf("size %lu ,length %lu ,%s\n", ss.size(), ss.length(), ss.c_str());
  return 0;
}
