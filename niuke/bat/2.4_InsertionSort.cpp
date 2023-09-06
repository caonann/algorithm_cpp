/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   2.4_InsertionSort.cpp
 @author     root
 @version
 @date       2019/09/29 01:31
 @brief
 @details    2019/09/29 root create
*/

#include "common_define.h"
// https://www.nowcoder.com/study/vod/1/2/4

class InsertionSort
{
public:
    int *insertionSort(int *A, int n)
    {
        if (n <= 0)
        {
            return nullptr;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                int j = i + 1;

                while (j - 1 >= 0)
                {
                    if (A[j - 1] > A[j])
                    {
                        std::swap(A[j - 1], A[j]);
                        j--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        return A;
    }

    int *insertionSort1(int *A, int n)
    {
        // write code here
        for (int i = 1; i < n; i++)
        {
            int j = i - 1;
            int temp = A[ i];

            while (j >= 0 && A[ j] > temp)// 查找temp的位置
            {
                A[j + 1] = A[ j];
                j--;
            }

            // 找到位置了
            A[j + 1] = temp;
        }

        return A;
    }
};

TEST(NiuKeBatTests, InsertionSort)
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<unsigned> u(0, 100);
    InsertionSort h;
    vector<int> arr_comm;

    for (int i = 0; i < 1000; i++)
    {
        arr_comm.push_back(u(e));
    }

    auto arr_test = arr_comm;
    comm::bubbleSort(static_cast<int *>(&arr_comm[0]), static_cast<int>(arr_comm.size()));
    h.insertionSort(static_cast<int *>(&arr_test[0]), static_cast<int>(arr_test.size()));
    EXPECT_TRUE(arr_comm == arr_test) << "1234 is  2341 's rotate arr";
}
