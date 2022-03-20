/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   stack2que.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: stack2que.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat 07 Apr 2018 10:54:31 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        if (stack2.empty())
        {
            if (stack1.empty())
            {
                cout << "que is null" << endl;
                return -1;
            }

            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int val = stack2.top();
        stack2.pop();
        return val;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    Solution s;

    for (int i = 0; i < 10; i++)
    {
        s.push(i);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << s.pop() << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        s.push(i);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << s.pop() << endl;
    }

    return 0;
}

