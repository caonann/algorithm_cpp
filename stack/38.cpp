/*
 @filename   38.cpp
 @author     caonan
 @date       2022-04-12 04:54:21
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/iIQa4I/
 @brief  请根据每日 气温 列表
 temperatures ，重新生成一个列表，要求其对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0
 来代替。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution
{
   public:
    //自己实现的还是不够简洁
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        assert(temperatures.size() > 0);
        struct Node {
            Node(int val, int index) : val(val), index(index) {}
            int val;
            int index;
        };
        vector<Node> nodes_stack{Node(temperatures[0], 0)};
        vector<int> ans(temperatures.size(), 0);
        for (int i = 1; i < temperatures.size(); i++) {
            Node node(temperatures[i], i);
            if (!nodes_stack.empty() && nodes_stack.back().val < node.val) {
                ans[nodes_stack.back().index] = node.index - nodes_stack.back().index;
                nodes_stack.pop_back();
                i--;
            } else {
                nodes_stack.emplace_back(node);
            }
        }
        return ans;
    }
};

class Solution1 : public Solution
{
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> stack_store;
        vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!stack_store.empty() && temperatures[stack_store.back()] < temperatures[i]) {
                ans[stack_store.back()] = i - stack_store.back();
                stack_store.pop_back();
            }
            stack_store.push_back(i);
        }
        return ans;
    }
};
int main()
{
    vector<int> in{73, 74, 75, 71, 69, 72, 76, 73};
    Solution1 s;
    auto ret = s.dailyTemperatures(in);
    for (auto v : ret) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
