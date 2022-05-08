/*************************************************************************
	> File Name: 56.MergeIntervals.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月07日 星期二 23时50分07秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://leetcode.com/problems/merge-intervals/
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        for(auto& arr:intervals) {
            if(arr[0]>arr[1]) std::swap(arr[0],arr[1]);
        }
        std::sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b) {
            return a[0]<b[0];
        });

        vector<vector<int>> result;
        for(int i=0; i<intervals.size();)
        {
            vector<int> tupe = intervals[i];
            if(i+1>=intervals.size()) {
                result.push_back(tupe);
                break;
            }
            vector<int> next_tupe = intervals[i+1];
            while(1)
            {
                if(tupe[1]<next_tupe[0]) {
                    result.push_back(tupe);
                    i++;
                    break;
                }
                else {
                    if(tupe[1]<next_tupe[1]) tupe = vector<int> {tupe[0],next_tupe[1]};
                    else tupe = vector<int> {tupe[0],tupe[1]};
                    i++;
                    if(i+1 >=intervals.size()) {
                        result.push_back(tupe);
                        return result;
                    }
                    next_tupe = intervals[i+1];
                }
            }
        }
        return result;
    }
};

void test(vector<vector<int>> arr)
{
    Solution s;
    auto intervals =s.merge(arr);
    for(auto& arr:intervals) {
        printf("[%d,%d] ",arr[0],arr[1]);
    }
    printf("\n");
}
int main()
{
    test({{1,3},{4,6},{8,10},{3,9}});
    test({{1,3},{2,6},{8,10},{15,18}});
    test({{1,4},{4,5}});
    test({{1,100}});
    test({});
    return 0;
}

