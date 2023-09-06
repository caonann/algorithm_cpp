/*
 @filename   getLeastNumbersK.cpp
 @author     caonan
 @date       2022-04-20 06:32:10
 @reference    剑指offer
 @url      https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
 @brief 输入整数数组 arr ，找出其中最小的 k
 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
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
class Solution
{
   public:
    //时间复杂度 nlogk做法
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        vector<int> ans;
        if (!k) return ans;
        priority_queue<int> q;  // c++的实现默认是大根堆
        for (int i = 0; i < k && i < arr.size(); i++) {
            q.push(arr[i]);
        }

        for (int i = k; i < arr.size(); i++) {
            if (q.top() > arr[i]) {
                q.push(arr[i]);
                q.pop();
            }
        }

        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};

class Solution1 : public Solution
{
   public:
    // n+klogn做法，自己实现堆todo:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        
    }
};

class Solution2 : public Solution
{
   public:
    // n+klogn做法，用优先队列的小根堆
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        vector<int> ans;
        if (!k) return ans;
        auto cmp = [](int left, int right) { return left > right; };  //定义小根堆
        std::priority_queue<int, std::vector<int>, decltype(cmp)> q(cmp);
        for (auto n : arr) {
            q.push(n);
        }

        while (!q.empty() && k--) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};

void uinttest(vector<int> arr, int k)
{
    Solution2 s;
    auto ret = s.getLeastNumbers(arr, k);
    for (auto v : ret) {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    uinttest(vector<int>{1, 3, 6, 2, 88, 9}, 4);
    uinttest(vector<int>{1, 3, 6, 2, 88, 9}, 0);
    uinttest(vector<int>{1, 3}, 3);
    uinttest(vector<int>{3, 2, 1}, 2);
    return 0;
}
