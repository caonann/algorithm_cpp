/*
 @filename   64.MagicDictionary.cpp
 @author     caonan
 @date       2022-05-02 14:05:29
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/US1pGT
 @brief  设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 互不相同 。
如果给出一个单词，请判定能否只将这个单词中一个字母换成另一个字母，使得所形成的新单词存在于已构建的神奇字典中。

实现 MagicDictionary 类：

MagicDictionary() 初始化对象
void buildDict(String[] dictionary) 使用字符串数组 dictionary 设定该数据结构，dictionary 中的字符串互不相同
bool search(String searchWord) 给定一个字符串 searchWord ，判定能否只将字符串中 一个
字母换成另一个字母，使得所形成的新字符串能够与字典中的任一字符串匹配。如果可以，返回 true ；否则，返回 false 。
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
#include "../stl/myTireTree.h"
using namespace std;
//todo:
class MagicDictionary
{
   public:
    /** Initialize your data structure here. */
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {}

    bool search(string searchWord) {}
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
int main() { return 0; }
