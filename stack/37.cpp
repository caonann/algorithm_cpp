/*
 @filename   37.cpp
 @author     caonan
 @date       2022-04-12 00:58:45
 @reference
 @url      https://leetcode-cn.com/problems/XagZNi/
 @brief  给定一个整数数组 asteroids，表示在同一行的小行星。
对于数组中的每一个元素，其绝对值表示小行星的大小，正负表示小行星的移动方向（正表示向右移动，负表示向左移动）。每一颗小行星以相同的速度移动。
找出碰撞后剩下的所有小行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
   public:
    //这版实现太拉胯了，代码太长
    //压栈情况
    // a. 栈空；
    // b. 栈顶是负数（向左运动的行星）；
    // c. 栈顶与asteroids[i]符号相同（当前行星运动方向一致）
    //栈顶是正数
    // a.如果asteroids[i]的绝对值小于栈顶，++i；
    // b.如果相等，则弹出栈顶元素并 ++i；
    // c.如果大于，则弹出栈顶元素，asteroids[i]继续进行一轮判断
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        stack<int> stack_store;
        for (auto n : asteroids) {
            assert(n != 0);
            while (1) {
                if (stack_store.empty() || stack_store.top() < 0 || n > 0) {
                    stack_store.push(n);
                    break;
                }

                if (n + stack_store.top() == 0) {
                    stack_store.pop();
                    break;
                }

                if (n + stack_store.top() < 0) {
                    stack_store.pop();
                } else {
                    break;
                }
            }
        }

        vector<int> ans;
        while (!stack_store.empty()) {
            ans.push_back(stack_store.top());
            stack_store.pop();
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution1 : public Solution
{
   public:
    //只用数组
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        vector<int> stack_store;
        for (int i = 0; i < asteroids.size(); i++) {
            if (stack_store.empty() || stack_store.back() < 0 || asteroids[i] > 0) {
                stack_store.push_back(asteroids[i]);
            } else if (stack_store.back() + asteroids[i] <= 0) {
                if (stack_store.back() + asteroids[i] < 0) --i;
                stack_store.pop_back();
            }
        }
        return stack_store;
    }
};

int main()
{
    Solution s;
    vector<int> in{10, -10};
    auto ret = s.asteroidCollision(in);
    for (auto v : ret) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
