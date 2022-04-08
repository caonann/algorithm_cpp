/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   merge.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: merge.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat 28 Oct 2017 12:29:51 PM CST
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

void merge(int *arr, int index_low, int index_high)
{
    int start_a = index_low;
    int end_a = (index_low + index_high) / 2;
    int start_b = end_a + 1;
    int end_b = index_high;
    int *parr = new int[index_high - index_low + 1];
    int index = 0;

    while (start_a <= end_a && start_b <= end_b)
    {
        if (arr[start_a] < arr[start_b])
        {
            parr[index++] = arr[start_a++];
        }
        else
        {
            parr[index++] = arr[start_b++];
        }
    }

    while (start_a <= end_a)
    {
        parr[index++] = arr[start_a++];
    }

    while (start_b <= end_b)
    {
        parr[index++] = arr[start_b++];
    }

    for (int i = 0; i < index_high - index_low + 1; i++)
    {
        arr[index_low + i] = parr[i];
    }

    for (int i = 0; i < index_high - index_low + 1; i++)
    {
        printf("%d ", parr[i]);
    }

    cout << endl;
    delete[] parr;
    parr = NULL;
}

void MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        merge(arr, low, high);
    }
}

int *mergeSort(int *A, int n)
{
    MergeSort(A, 0, n - 1);
    return A;
}
int main()
{
    int arr[] = { 1, 3, 5, 4, 8, 0, 9 , 6, 4, 3, 5, 6, 34, 2, 34, 554, 6};
    mergeSort(arr, sizeof(arr) / sizeof(int));
    // MergeSort(arr, 0, sizeof(arr) / sizeof(int)-1);
    return 0;
}

