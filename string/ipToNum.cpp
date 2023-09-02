/*
 @filename   ipToNum.cpp
 @author     caonan
 @date       2022-04-28 12:21:18
 @reference   个人收集
 @url
 @brief  将字符串类型的点分十进制IPv4转换为无符号整数

*/
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

/*
首先需要理解IP地址可以用4个字节表示，每个字节代表一段
需要注意IP地址每段最大为255，故需要用无符号整数表示
遍历一次即可完成，每段转换为10进制数字，一次点分左移8位或乘以255；最后一段也需要加上
如果有IP地址合法性检查加分
*/

unsigned int ipToNum(string ip) {
  vector<int> ip_arr;
  int pos = 0;
  while (true) {
    int pre = pos;
    pos = ip.find('.', pos);
    if (pos == std::string::npos) {
      ip_arr.push_back(std::stoi(ip.substr(pre)));
      break;
    }
    pos++;
    ip_arr.push_back(std::stoi(ip.substr(pre, pos - pre)));
  }
  string number;
  for (auto n : ip_arr) {
    bitset<8> b(n);
    // 主机序
    number += b.to_string();
  }
  bitset<32> ans(number);
  return ans.to_ullong();
}

// 优化版本
unsigned int ipToNum2(string ip) {
  int num = 0;
  int left_offset = 3;
  unsigned int total_num = 0;
  ip += ".";
  for (int i = 0; i < ip.length(); i++) {
    if (ip[i] != '.') {
      int n = ip[i] - '0';
      num = num * 10 + n;
      continue;
    }
    total_num = total_num == 0 ? num : total_num + num;
    total_num = left_offset-- > 0 ? total_num << 8 : total_num;
    num = 0;
  }
  return total_num;
}

uint32_t check(string ip) {
  struct in_addr addr;
  inet_pton(AF_INET, ip.c_str(), &addr.s_addr);
  return ntohl(addr.s_addr);
}

void uinttest() {
  char buf[15];
  for (int r1 = 0; r1 <= 255; r1++) {
    for (int r2 = 0; r2 <= 255; r2++) {
      for (int r3 = 0; r3 <= 255; r3++) {
        for (int r4 = 0; r4 <= 255; r4++) {
          snprintf(buf, sizeof(buf), "%d.%d.%d.%d", r1, r2, r3, r4);
          string s(buf);
          // cout << s << endl;
          int ans1 = ipToNum2(s);
          int ans2 = check(s);
          assert(ans1 == ans2);
        }
      }
    }
  }
}

int main() {
  string ip = "192.168.1.1";
  auto ret = ipToNum(ip);
  // 3232235777
  cout << "iptonum: " << ret << endl;
  struct in_addr addr;
  inet_pton(AF_INET, ip.c_str(), &addr.s_addr);
  cout << "inet_pton: " << addr.s_addr << endl;
  uint32_t iaddr = ntohl(addr.s_addr);
  cout << "ntohl: " << iaddr << endl;

  uinttest();

  // ipToNum2("192.168.1.1");
  return 0;
}
