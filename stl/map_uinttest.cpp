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
#include <set>
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

    it = map_test.lower_bound(-1);
    if (it == map_test.begin()) cout << "no element " << endl;
    map<int, int> map_test1;

    map_test1[1];
    auto it1 = map_test1.lower_bound(2);
    if (it1 == map_test1.end()) cout << " no such element 2" << endl;
    it1 = map_test1.lower_bound(0);
    if (it1 == map_test1.end()) cout << " no such element 0" << endl;
    set<int> set_test;
    set_test.insert(1);
    auto it2 = set_test.lower_bound(2);
    if (it2 == set_test.end()) cout << "set end" << endl;
    set_test.insert(2);
    set_test.insert(3);
    auto it3 = set_test.rbegin();
    cout << "rbegin is " << *it3 << endl;
    return 0;
}
