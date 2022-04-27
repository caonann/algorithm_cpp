/*
 @filename   map_uinttest.cpp
 @author     caonan
 @date       2022-04-25 16:27:40
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
using namespace std;

int main()
{
    map<int, string> map_test{{0, "zero"}, {1, "one"}, {3, "three"}, {4, "four"}};
    auto pair = map_test.equal_range(1);
    // pair.first是{1，"two"},pair.second 是{2，"three"};
    for (auto it = pair.first; it != pair.second; ++it) {
        cout << "key " << it->first << " val " << it->second << endl;
    }

    auto it = map_test.lower_bound(2);
    cout << "lower_bound 2 is " << it->first << " val " << it->second << endl;
    it = map_test.upper_bound(2);
    cout << "upper_bound 2 is " << it->first << " val " << it->second << endl;


    return 0;
}
