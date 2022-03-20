/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   2.8_shellSort.cpp
 @author     root
 @version
 @date       2019/09/29 01:31
 @brief
 @details    2019/09/29 root create
*/
#include "common_define.h"
// https://www.nowcoder.com/study/vod/1/2/8

class ShellSort
{
public:
    int *shellSort(int *A, int n)
    {
        // choose step size 3 just for test
        if (n <= 0)
        {
            return nullptr;
        }

        int init_step_size = 3;

        for (int k = init_step_size; k > 0; k--)
        {
            for (int i = 0; i < n - k; i++)
            {
                if (A[i] > A[i + k])
                {
                    int j = i + k;

                    while (j - k >= 0)
                    {
                        if (A[j - k] > A[j])
                        {
                            std::swap(A[j - k], A[j]);
                            j -= k;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }

        return A;
    }
};

namespace
{

TEST(NiuKeBatTests, ShellSort)
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<unsigned> u(0, 100);
    ShellSort h;
    vector<int> arr_comm;

    for (int i = 0; i < 1000; i++)
    {
        arr_comm.push_back(u(e));
    }

    auto arr_test = arr_comm;
    comm::bubbleSort(static_cast<int *>(&arr_comm[0]), static_cast<int>(arr_comm.size()));
    h.shellSort(static_cast<int *>(&arr_test[0]), static_cast<int>(arr_test.size()));
    EXPECT_TRUE(arr_comm == arr_test) << "1234 is  2341 's rotate arr";
}

}// end namespace
