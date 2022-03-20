/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   retotate_arr.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: retotate_arr.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat 07 Apr 2018 11:37:19 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
// 34512 旋转数组最小数字
int retotate(const vector<int> &arr, int start, int end)
{
    printf("start %d,end %d\n", start, end);
    int mid = (start + end) / 2;

    if (start == mid || end == mid)
    {
        return arr[start] > arr[end] ? arr[end] : arr[start];
    }

    if (arr[mid] > arr[start])
    {
        return retotate(arr, mid, end);
    }
    else if (arr[mid] < arr[start])
    {
        return retotate(arr, start, mid);
    }
    else
    {
        while (mid++ != end)
        {
            if (arr[mid] != arr[start])
            {
                break;
            }
        }

        return retotate(arr, mid, end);
    }
}
int minNumberInRotateArray(vector<int> rotateArray)
{
    if (rotateArray.size() == 0)
    {
        return 0;
    }

    return retotate(rotateArray, 0, rotateArray.size() - 1);
}

int main()
{
    vector<int> arr = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 };
    int min = minNumberInRotateArray(arr);
    cout << min << endl;
    return 0;
}

