/*
 @filename   31.cpp
 @author     caonan
 @date       2022-04-08 15:40:09
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/OrIXps/
 @brief  运用所掌握的数据结构，设计和实现一个  LRU (Least Recently Used，最近最少使用) 缓存机制 。

实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int
value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    Node(int val, int key) : val(val), key(key) {}
    int val;
    int key;
    Node *next = nullptr;
    Node *pre = nullptr;
};
class LRUCache
{
   public:
    LRUCache(int capacity) : capacity_(capacity)
    {
        head_ = new Node(-1, -1);
        tail_ = new Node(-1, -1);
        head_->next = tail_;
        tail_->pre = head_;
    }

    ~LRUCache()
    {
        while (head_) {
            auto p = head_;
            head_ = head_->next;
            delete p;
            p = nullptr;
        }
    }

    int get(int key)
    {
        if (key_to_node_.find(key) != key_to_node_.end()) {
            Node *p = key_to_node_[key];
            move_node_to_tail(p);
            return p->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (key_to_node_.find(key) != key_to_node_.end()) {
            Node *p = key_to_node_[key];
            p->val = value;
            move_node_to_tail(p);
        } else {
            Node *p = new Node(value, key);
            move_node_to_tail(p);
            key_to_node_[key] = p;
            if (key_to_node_.size() > capacity_) {
                key_to_node_.erase(head_->next->key);
                pop_list_front();
            }
        }
    }

   private:
    void move_node_to_tail(Node *node)
    {
        if (node->pre && node->next) {
            node->pre->next = node->next;
            node->next->pre = node->pre;
        }
        node->pre = tail_->pre;
        tail_->pre->next = node;
        node->next = tail_;
        tail_->pre = node;
    }

    void pop_list_front()
    {
        auto next = head_->next;
        head_->next->next->pre = head_;
        head_->next = head_->next->next;
        delete next;
        next = nullptr;
    }
    // store key and val arr index
    unordered_map<int, Node *> key_to_node_;
    // std::unique_ptr<Node *> head_, tail;
    Node *head_, *tail_;
    // store val in data
    const int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//todo: 如果用智能指针实现链表？
void uinttest_lrucache(int capacity)
{
    LRUCache cache(capacity);
    cache.put(1, 1);
    assert(cache.get(2) == -1);
    capacity == 0 ? assert(cache.get(1) == -1) : assert(cache.get(1) == 1);
}
int main()
{
    uinttest_lrucache(0);
    uinttest_lrucache(1);
    uinttest_lrucache(2);
    uinttest_lrucache(5);
    return 0;
}
