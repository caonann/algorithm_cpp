/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   VerifySquenceOfBST.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: VerifySquenceOfBST.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat 14 Apr 2018 11:02:39 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool isavltree(vector<int> &que, int left, int rend)
{
    if (left >= rend)
    {
        return true;
    }

    int rootnode = que[rend];
    int mid = 0;

    for (int i = left; i <= rend; i++)
    {
        if (rootnode <= que[i])
        {
            mid = i;
            break;
        }
    }

    printf("left %d,right %d,mid %d\n", left, rend, mid);

    for (int i = mid + 1; i <= rend; i++)
    {
        if (que[i] < rootnode)
        {
            printf("que i %d return false root %d\n", que[i], rootnode);
            return false;
        }
    }

    bool isleft = true;

    if (mid > 0)
    {
        isleft = isavltree(que, left, mid - 1);
    }

    bool isright = true;

    if (rend - mid > 0)
    {
        isright = isavltree(que, mid, rend - 1);
    }

    return (isleft && isright);
}

bool VerifySquenceOfBST(vector<int> sequence)
{
    if (sequence.empty())
    {
        return true;
    }

    return isavltree(sequence, 0, sequence.size() - 1);
}

int main()
{
    // vector<int> seq = { 1,3,2,6,7,5,4 };
    // vector<int> seq = { 1,3,2,5,7,6,4 };
    vector<int> seq = { 4, 8, 6, 12, 16, 14, 10 };
    cout << VerifySquenceOfBST(seq) << endl;
    return 0;
}

