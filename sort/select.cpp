/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   select.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: select.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat 28 Oct 2017 11:26:20 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int *selectionSort(int *A, int n)
{
    if (n <= 0)
    {
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        int imax = i;

        for (int j = i + 1; j < n; j++)
        {
            if (A[imax] < A[j])
            {
                imax = j;
            }
        }

        int tmp = A[i];
        A[i] = A[imax];
        A[imax] = tmp;
    }

    return A;
}

int main()
{
    int arr[] = {1, 3, 5, 4, 8, 0, 9};
    selectionSort(arr, sizeof(arr) / sizeof(int));

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}

