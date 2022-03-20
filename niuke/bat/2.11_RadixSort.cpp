/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   2.11_RadixSort.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
#include "common_define.h"

class RadixSort
{
public:
    int *radixSort(int *A, int n)
    {
        // write code here
        vector<vector<int>> bucket_arr;
        bucket_arr.resize(10);
        int decimal = 0;

        while (1)
        {
            bool loop = false;

            for (int i = 0; i < n; i++)
            {
                int num = A[i];
                int divisor = 1;

                for (int in = 0; in < decimal; in++)
                {
                    divisor *= 10;
                }

                int tmp = A[i] / divisor;

                if (tmp > 0)
                {
                    loop = true;
                }

                int mod = tmp % 10;
                bucket_arr[mod].push_back(num);
            }

            if (!loop)
            {
                break;
            }

            decimal++;
            int arr_index = 0;

            for (auto &bucket : bucket_arr)
            {
                for (auto &digit : bucket)
                {
                    A[arr_index++] = digit;
                }
            }

            bucket_arr.clear();
            bucket_arr.resize(10);
        }

        return A;
    }
};

TEST(NiuKeBatTests, CountingSort)
{
    RadixSort rs;
    vector<int> arr_comm;

    for (int i = 0; i < 1000; i++)
    {
        arr_comm.push_back(RandomUtils::getInt());
    }

    auto arr_test = arr_comm;
    comm::bubbleSort(static_cast<int *>(&arr_comm[0]), static_cast<int>(arr_comm.size()));
    rs.radixSort(static_cast<int *>(&arr_test[0]), static_cast<int>(arr_test.size()));
    // printItemList<vector<int>>(arr_comm);
    // printItemList<vector<int>>(arr_test);
    EXPECT_TRUE(arr_comm == arr_test) << "1234 is  2341 's rotate arr";
}