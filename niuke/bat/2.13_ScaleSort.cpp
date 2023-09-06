/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   2.13_ScaleSort.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
#include "common_define.h"
// https://www.nowcoder.com/study/vod/1/2/13

class ScaleSort
{
public:
    vector<int> sortElement(vector<int> A, int n, int k)
    {
        // write code here
        if (k < 0 || n < 0)
        {
            return A;
        }

        for (int i = 0; i < n; i++)
        {
            adjust(A, i, k);
        }

        return A;
    }

    void adjust(vector<int> &arr, int start, int k)
    {
        //k means len
        int offset_len = k;

        if (arr.size() - start <= 1)
        {
            return;
        }

        if (arr.size() - start < offset_len)
        {
            offset_len = arr.size() - start;
        }

        for (int rootID = offset_len / 2 - 1; rootID >= 0; rootID--)
        {
            int left_index = 2 * rootID + 1;
            int right_index = 2 * rootID + 2;
            int MIN = left_index;
            int rootval = arr[rootID + start];

            if (right_index > offset_len - 1)
            {
                if (rootval < arr[left_index + start])
                {
                    MIN = rootID;
                }
            }
            else
            {
                if (arr[left_index + start] > arr[right_index + start])
                {
                    MIN = right_index;
                }

                if (rootval < arr[MIN + start])
                {
                    MIN = rootID;
                }
            }

            std::swap(arr[rootID + start], arr[MIN + start]);
        }
    }
};

int main()
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<unsigned> u(30, 1000);
    vector<int> arr_comm;

    for (int i = 0; i < 1000; i++)
    {
        arr_comm.push_back(u(e));
    }

    ScaleSort s;
    vector<int> arr{2, 1, 4, 3, 6, 5, 8, 7, 10, 9};
    // vector<int> arr{2,1,4,3,1,5,8,7,10,9};
    // s.heapSortTest(arr_comm);
    // printItemList(arr_comm);
    auto ret = s.sortElement(arr, arr.size(), 2);
    printItemList(ret);
    return 0;
}