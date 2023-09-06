/*
 @filename   iterator_erase_cases.cpp
 @author     caonan
 @date       2022-04-28 01:08:14
 @reference
 @url
 @brief
 常见迭代器在迭代的时候删除时要注意的问题
 vector,map,
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
using namespace std;
// todo

// string iterator in for loop ,and delete it
void uint_test_string()
{
    string s = "  hello world this is a test case for a delete in loop ";
    for (auto it = s.begin(); it != s.end();) {
        if (*it == ' ') {
            it = s.erase(it);
        } else {
            ++it;
        }
    }

    cout << "after operate the string: " << s << endl;
}

int main()
{
    uint_test_string();
    return 0;
}
