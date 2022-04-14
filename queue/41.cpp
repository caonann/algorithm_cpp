/*
 @filename   41.cpp
 @author     caonan
 @date       2022-04-13 06:55:11
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/qIsx9U/
 @brief  给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。

实现 MovingAverage 类：
MovingAverage(int size) 用窗口大小 size 初始化对象。
double next(int val) 成员函数 next 每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 size
个值的移动平均值，即滑动窗口里所有数字的平均值。  
*/

#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class MovingAverage
{
   public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : capacity_(size) {}

    double next(int val)
    {
        total_sum_ += val;
        queue_.push(val);
        if (queue_.size() > capacity_) {
            total_sum_ -= queue_.front();
            queue_.pop();
        }
        return static_cast<double>(total_sum_) / queue_.size();
    }

   private:
    queue<int> queue_;
    int total_sum_{0};
    int capacity_{0};
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main()
{
    MovingAverage m(3);
    cout << m.next(1) << endl;
    cout << m.next(10) << endl;
    cout << m.next(3) << endl;
    cout << m.next(5) << endl;
    return 0;
}
