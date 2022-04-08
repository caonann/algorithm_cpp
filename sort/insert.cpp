/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   insert.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: insert.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat 28 Oct 2017 11:41:34 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int *insertionSort(int *A, int n)
{
    if (n <= 0)
    {
        return NULL;
    }

    for (int i = 1; i < n; i++)
    {
        int ipre = i - 1;
        int mark = A[i];

        while (ipre >= 0 && A[ipre] > mark)
        {
            A[ipre + 1] = A[ipre];
            ipre--;
        }

        A[ipre + 1] = mark;
    }

    return A;
}

int main()
{
    int arr[] = {1, 3, 5, 4, 8, 0, 9};
    insertionSort(arr, sizeof(arr) / sizeof(int));

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}

