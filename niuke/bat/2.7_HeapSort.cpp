/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   2.7_heapSort.cpp
 @author     root
 @version
 @date       2019/09/29 01:31
 @brief
 @details    2019/09/29 root create
*/
#include "common_define.h"
// https://www.nowcoder.com/study/vod/1/2/7
// 堆排序没有用到递归，是一种改进的选择排序，通过树这种结构减少了比较的次数，是一种不稳定的排序
#define right_idx  2*nRootID+2
#define left_idx   2*nRootID+1

class HeapSort
{
public:
    int *heapSort(int *A, int n)
    {
        // write code here
        if (A == nullptr || n <= 0)
        {
            return A;
        }

        // 构建初始堆
        for (int rootid = n / 2 - 1; rootid >= 0; rootid--)
        {
            adjust(A , n, rootid);
        }

        // 交换最后一个节点和根节点的值
        for (int length = n - 1; length > 0; length--)
        {
            // 调整
            std::swap(A[length], A[0]);
            adjust(A , length, 0);
        }

        return A;
    }

    // 调整函数
    void adjust(int data[], int Length, int nRootID)
    {
        for (int MAX = left_idx; MAX <= Length - 1; MAX = left_idx)
        {
            if (MAX == Length - 1)
            {
                if (data[MAX] > data[nRootID])
                {
                    std::swap(data[MAX], data[nRootID]);
                    return;
                }
            }
            else if (data[right_idx] > data[left_idx])
            {
                MAX = right_idx;
            }

            // 用最大节点和根节点比较
            if (data[MAX] > data[nRootID])
            {
                std::swap(data[MAX], data[nRootID ]);
                nRootID = MAX;
                continue;
            }

            return;
        }
    }
};

namespace
{

TEST(NiuKeBatTests, HeapSortTest)
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<unsigned> u(0, 100);
    HeapSort h;
    vector<int> arr_comm;

    for (int i = 0; i < 1000; i++)
    {
        arr_comm.push_back(u(e));
    }

    auto arr_test = arr_comm;
    comm::bubbleSort(static_cast<int *>(&arr_comm[0]), static_cast<int>(arr_comm.size()));
    h.heapSort(static_cast<int *>(&arr_test[0]), static_cast<int>(arr_test.size()));
    EXPECT_TRUE(arr_comm == arr_test) << "1234 is  2341 's rotate arr";
}

}// end namespace
