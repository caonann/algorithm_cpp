/*
 @filename   58.MyCalendar.cpp
 @author     caonan
 @date       2022-04-29 07:21:03
 @reference 剑指offer专项
 @url      https://leetcode-cn.com/problems/fi9suh/
 @brief  请实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内没有其他安排，则可以存储这个新的日程安排。

MyCalendar 有一个 book(int start, int end)方法。它意味着在 start 到 end
时间内增加一个日程安排，注意，这里的时间是半开区间，即 [start, end), 实数 x 的范围为，  start <= x < end。

当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生重复预订。

每次调用 MyCalendar.book方法时，如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 true。否则，返回
false 并且不要将该日程安排添加到日历中。

请按照以下步骤调用 MyCalendar 类: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
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
using namespace std;
//写的太罗嗦了
class MyCalendar
{
   public:
    MyCalendar() {}

    bool book(int start, int end)
    {
        if (map_time_.empty()) {
            map_time_[start] = end;
            return true;
        }
        auto it = map_time_.lower_bound(start);

        if (it != map_time_.end()) {
            if (end > it->first) return false;
            if (it != map_time_.begin()) {
                --it;
                if (it->second > start) return false;
            }
        } else {
            auto it2 = map_time_.rbegin();
            if (it2->second > start) return false;
        }

        map_time_[start] = end;
        return true;
    }
    map<int, int> map_time_;  // start,end
};

class MyCalendar1 : public MyCalendar
{
   public:
   //容器是空的时候begin和end相等
    MyCalendar1() {}
    bool book(int start, int end)
    {
        auto it = map_time_.lower_bound(start);
        if (it != map_time_.end() && end > it->first) return false;
        if (it != map_time_.begin() && (--it)->second > start) return false;
        map_time_[start] = end;
        return true;
    }
    map<int, int> map_time_;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
int main()
{
    MyCalendar1 s;
    s.book(10, 20);
    return 0;
}
