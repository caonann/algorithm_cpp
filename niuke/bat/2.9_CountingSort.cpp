/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   2.9_CountingSort.cpp
 @author     root
 @version
 @date       2019/09/29 01:31
 @brief
 @details    2019/09/29 root create
*/
/*************************************************************************
    > File Name: 2.9_CountingSort.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sun Sep 22 18:27:02 2019
 ************************************************************************/

#include "common_define.h"
// https://www.nowcoder.com/study/vod/1/2/10

class CountingSort
{
public:
    int *countingSort(int *A, int n)
    {
        if (A == nullptr || n <= 0)
        {
            return A;
        }

        int max = A[0];
        int min = max;

        for (int i = 0; i < n; i++)
        {
            if (max < A[i])
            {
                max = A[i];
            }

            if (min > A[i])
            {
                min = A[i];
            }
        }

        int bucket_size = max - min + 1;

        if (!bucket_size)
        {
            return A;
        }

        vector<int> bucket;
        bucket.resize(bucket_size);

        for (int i = 0; i < n; i++)
        {
            bucket[A[i] - min]++;
        }

        int index = 0;

        for (int i = 0; i < bucket_size; i++)
        {
            for (int j = 0; j < bucket[i]; j++)
            {
                A[index++] = i + min;
            }
        }

        return A;
    }
};

TEST(NiuKeBatTests, CountingSort)
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<unsigned> u(30, 100);
    CountingSort cs;
    vector<int> arr_comm;

    for (int i = 0; i < 1000; i++)
    {
        arr_comm.push_back(u(e));
    }

    auto arr_test = arr_comm;
    comm::bubbleSort(static_cast<int *>(&arr_comm[0]), static_cast<int>(arr_comm.size()));
    cs.countingSort(static_cast<int *>(&arr_test[0]), static_cast<int>(arr_test.size()));
    // printItemList<vector<int>>(arr_comm);
    // printItemList<vector<int>>(arr_test);
    EXPECT_TRUE(arr_comm == arr_test) << "1234 is  2341 's rotate arr";
}


