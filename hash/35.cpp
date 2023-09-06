/*
 @filename   35.cpp
 @author     caonan
 @date       2022-04-11 07:47:43
 @reference    剑指offer专项
 @url      https://leetcode-cn.com/problems/569nqc/
 @brief  给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution
{
   public:
    //鸽巢原理
    int findMinDifference(vector<string>& timePoints)
    {
        assert(timePoints.size() >= 2);
        const int minutes = 60 * 24;
        bitset<minutes> hash_bits;
        auto time_convert = [](const string& time) -> int {
            auto pos = time.find(':');
            return 60 * stoi(time.substr(0, pos)) + stoi(time.substr(pos + 1));
        };

        for (auto s : timePoints) {
            int index = time_convert(s);
            if (hash_bits[index]) return 0;
            hash_bits.flip(index);
        }
        int min = minutes;
        int first_index = -1;
        int front = hash_bits.size(), last = -1;

        for (int i = 0; i < hash_bits.size(); i++) {
            if (hash_bits[i]) {
                if (first_index != -1) {
                    min = std::min(i - first_index, min);
                }
                first_index = i;
                front = std::min(front, first_index);
                last = std::max(last, first_index);
            }
        }

        return std::min(min, front + minutes - last);
    }
};
int main()
{
    Solution s;
    vector<string> timpoints{"00:12", "23:59", "01:08"};
    int ans = s.findMinDifference(timpoints);
    cout << ans << endl;
    return 0;
}
