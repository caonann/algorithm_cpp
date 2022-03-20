/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   IsPopOrder.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: IsPopOrder.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sun 15 Apr 2018 12:03:23 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool IsPopOrder2(vector<int> pushV, vector<int> popV)
{
    if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
    {
        return false;
    }

    bool ret = false;
    std::stack<int> pushS;
    int iv = 0;
    int ip = 0;

    for (; ip < popV.size(); ip++)
    {
        int hopenum = popV[ip];

        // printf("hope %d\n", hopenum);
        while (pushS.empty() || pushS.top() != hopenum)
        {
            if (iv >= popV.size())
            {
                break;
            }

            // printf("iv %d\n", iv);
            pushS.push(pushV[iv++]);
        }

        if (iv >= popV.size() && pushS.top() != hopenum)
        {
            break;
        }

        pushS.pop();
    }

    // cout << "size" << pushS.size() << endl;
    if (pushS.empty() && ip == popV.size())
    {
        ret = true;
    }

    return ret;
}

bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
    if (pushV.empty())
    {
        return false;
    }

    std::stack<int> ostatck;

    for (int i = 0, j = 0; i < pushV.size(); i++)
    {
        ostatck.push(pushV[i]);

        while (j < popV.size() && ostatck.top() == popV[j])
        {
            ostatck.pop();
            j++;
        }
    }

    return ostatck.empty();
}
int main()
{
    vector<int> pushv = { 1, 2, 3, 4, 5 };
    // vector<int> popv = { 4,3,5,1,2 };
    vector<int> popv = { 4, 5, 3, 2, 1 };
    cout << IsPopOrder(pushv, popv) << endl;
    return 0;
}

