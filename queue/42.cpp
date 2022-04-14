/*
 @filename   42.cpp
 @author     caonan
 @date       2022-04-13 07:20:41
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/H8086Q/
 @brief  写一个 RecentCounter 类来计算特定时间范围内最近的请求。

请实现 RecentCounter 类：
RecentCounter() 初始化计数器，请求数为 0 。
int ping(int t) 在时间 t 添加一个新请求，其中 t 表示以毫秒为单位的某个时间，并返回过去 3000
毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 [t-3000, t] 内发生的请求数。 保证 每次对 ping
的调用都使用比之前更大的 t 值。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
class RecentCounter
{
   public:
    RecentCounter() {}

    int ping(int t)
    {
        time_queue_.push(t);
        while (!time_queue_.empty() && time_queue_.front() < t - window_size) {
            time_queue_.pop();
        }
        return time_queue_.size();
    }

   private:
    queue<int> time_queue_;
    const int window_size = 3000;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
int main()
{
    RecentCounter s;
    cout << s.ping(1) << endl;
    cout << s.ping(100) << endl;
    cout << s.ping(3001) << endl;
    cout << s.ping(3002) << endl;
    return 0;
}
