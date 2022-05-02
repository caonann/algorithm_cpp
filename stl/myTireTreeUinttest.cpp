/*
 @filename   myTireTreeUinttest.cpp
 @author     caonan
 @date       2022-05-02 13:01:36
 @reference
 @url
 @brief
*/
#include <assert.h>
#include <stdio.h>

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

#include "myTireTree.h"
using namespace std;

int main()
{
    MyTireTree t;
    t.insert("hello");
    t.insert("hulk");
    assert(t.search("hello"));
    assert(t.search("hulk"));
    assert(!t.search("hel"));
    assert(t.prefix("hel"));
    return 0;
}
