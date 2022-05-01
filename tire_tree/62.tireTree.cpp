/*
 @filename   62.tireTree.cpp
 @author     caonan
 @date       2022-05-01 15:24:43
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/QC3q1f
 @brief
 Trie（发音类似 "try"）或者说 前缀树
是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
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
using namespace std;
class Trie
{
   public:
    /** Initialize your data structure here. */
    Trie() : root_(new tire_node()) {}

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        auto it = root_;
        for (auto c : word) {
            if (!it->tire_nodes[c - 'a']) {
                it->tire_nodes[c - 'a'] = new tire_node();
            }
            it = it->tire_nodes[c - 'a'];
        }
        it->isTail = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        auto it = root_;
        for (auto c : word) {
            if (!it->tire_nodes[c - 'a']) return false;
            it = it->tire_nodes[c - 'a'];
        }
        return it->isTail;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        auto it = root_;
        for (auto c : prefix) {
            if (!it->tire_nodes[c - 'a']) return false;
            it = it->tire_nodes[c - 'a'];
        }
        return true;
    }

   private:
    struct tire_node {
        tire_node() : tire_nodes(26, nullptr), isTail(false) {}
        bool isTail;
        vector<tire_node*> tire_nodes;
    };
    tire_node* root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main()
{
    Trie* obj = new Trie();
    obj->insert("hello");
    assert(obj->search("hello"));
    assert(obj->startsWith("hel"));
    return 0;
}
