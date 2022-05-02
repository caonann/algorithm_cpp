/*
 @filename   myTireTree.h
 @author     caonan
 @date       2022-05-02 13:00:17
 @reference
 @url
 @brief
*/
#ifndef __MY_TIRE_TREE__
#define __MY_TIRE_TREE__
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

//只支持小写字母的前缀树
class MyTireTree
{
   public:
    MyTireTree() : flag(false) {}
    bool search(const std::string& s)
    {
        auto it = this;
        for (auto c : s) {
            if (it->tire_tree_nodes_.find(c) == it->tire_tree_nodes_.end()) return false;
            it = it->tire_tree_nodes_[c];
        }
        return it->flag;
    }
    bool prefix(const std::string& s)
    {
        auto it = this;
        for (auto c : s) {
            if (it->tire_tree_nodes_.find(c) == it->tire_tree_nodes_.end()) return false;
            it = it->tire_tree_nodes_[c];
        }
        return true;
    }
    void insert(const std::string& s)
    {
        auto it = this;
        for (auto c : s) {
            if (it->tire_tree_nodes_.find(c) == it->tire_tree_nodes_.end()) {
                it->tire_tree_nodes_[c] = new MyTireTree();
            }
            it = it->tire_tree_nodes_[c];
        }
        it->flag = true;
    }

    bool flag;  // mark this char is the end
    std::unordered_map<char, MyTireTree*> tire_tree_nodes_;
};

#endif