/*
 @filename   myPriority.h
 @author     caonan
 @date       2022-05-01 12:44:32
 @reference
 @url
 @brief  自己实现的优先队列
*/
#include <cassert>
#include <cstdio>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#ifndef __MY_PRIORITY_H__
#  define __MY_PRIORITY_H__

class MyPriority {
 public:
  MyPriority() = default;
  explicit MyPriority(const std::vector<int>& arr) : queue_(arr) {
    for (int i = arr.size() / 2 - 1; i >= 0; i--) {
      adjust(i);
    }
  }

  void push(int val) {
    queue_.push_back(val);
    adjust_bottom();
  }

  int top() { return queue_.front(); }
  void pop() {
    queue_[0] = queue_.back();
    queue_.pop_back();
    adjust(0);
  }
  int size() { return queue_.size(); }

 private:
  void adjust(int begin) {
    for (int i = begin; i <= queue_.size() / 2 - 1;) {
      int left = 2 * i + 1;
      int right = 2 * i + 2;
      int min = left;
      if (right < queue_.size()) {
        min = queue_[left] < queue_[right] ? left : right;
      }
      min = queue_[min] < queue_[i] ? min : i;
      if (min == i) {
        break;
      }
      std::swap(queue_[min], queue_[i]);
      i = min;
    }
  }
  void adjust_bottom() {
    int min = queue_.size() - 1;
    for (int i = queue_.size() / 2 - 1; i >= 0;) {
      if (queue_[min] > queue_[i]) {
        break;
      }
      std::swap(queue_[min], queue_[i]);
      min = i;
      i = i / 2 - static_cast<int>(i % 2 == 0);
    }
  }
  std::vector<int> queue_;
};

#endif