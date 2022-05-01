/*
 @filename   59.KthLargest.cpp
 @author     caonan
 @date       2022-04-30 13:05:29
 @reference   剑指offer专项
 @url      https://leetcode-cn.com/problems/jBjn9C/
 @brief  设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。

请实现 KthLargest 类：

KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。

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
#include "../stl/myPriority.h"
using namespace std;

class KthLargest
{
   public:
    KthLargest(int k, vector<int>& nums) : k_(k), heap_(cmp())
    {
        //构建小根堆
        for (auto n : nums) {
            add(n);
        }
    }

    int add(int val)
    {
        if (heap_.empty() || heap_.size() < k_ || val > heap_.top()) {  //这一行判断其实较为多余
            heap_.push(val);
            if (heap_.size() > k_) {
                heap_.pop();
            }
        }
        return heap_.top();
    }

   private:
    struct cmp {
        int operator()(int left, int right) { return left > right; }
    };

    priority_queue<int, vector<int>, cmp> heap_;
    const int k_;
};

class KthLargest1 : public KthLargest
{
   public:
    // using KthLargest::KthLargest;
    KthLargest1(int k, vector<int>& nums) : k_(k), KthLargest(k, nums)
    {
        for (auto n : nums) add(n);
    }

    int add(int val)
    {
        heap_.push(val);
        if (heap_.size() > k_) {
            heap_.pop();
        }
        return heap_.top();
    }

   private:
    const int k_;
    priority_queue<int, vector<int>, greater<int>> heap_;
};

class KthLargest2 : public KthLargest
{
   public:
    // using KthLargest::KthLargest;
    KthLargest2(int k, vector<int>& nums) : k_(k), KthLargest(k, nums)
    {
        for (auto n : nums) add(n);
    }

    int add(int val)
    {
        heap_.push(val);
        if (heap_.size() > k_) {
            heap_.pop();
        }
        return heap_.top();
    }

   private:
    const int k_;
    MyPriority heap_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

void uinttest_myheap()
{
    vector<int> in{1, 3, 2, 5, 4, 7, 9, 10};
    MyPriority heap(in);

    cout << "top is " << heap.top() << endl;
    heap.push(11);
    cout << "top is " << heap.top() << endl;
    heap.push(0);
    cout << "top is " << heap.top() << endl;
    heap.pop();
    cout << "top is " << heap.top() << endl;
    heap.pop();
    cout << "top is " << heap.top() << endl;
}
int main()
{
    vector<int> in{1, 3, 2, 5, 4, 7, 9, 10};
    KthLargest2 s(3, in);
    assert(7 == s.add(3));
    assert(9 == s.add(11));

    // uinttest_myheap();
    return 0;
}
