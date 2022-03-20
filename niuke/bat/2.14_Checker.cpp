/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   2.14_Checker.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
#include "common_define.h"
// https://www.nowcoder.com/study/vod/1/2/14
class Checker
{
public:
    bool checkDuplicate(vector<int> a, int n)
    {
        // write code here
        for (int i = a.size() - 1; i >= 0; i--)
        {
            adjust(a , i);
            std::swap(a[0], a[i]);
        }

        // for(auto v:a)cout<<v<<" ";cout<<endl;

        for (int i = 0; i < a.size() - 1; i++)
        {
            if (a[i] == a[i + 1])
            {
                return true;
            }
        }

        return false;
    }

    void adjust(vector<int> &arr, int len)
    {
        for (int ID = len / 2 - 1; ID >= 0; ID--)
        {
            int left_idx = 2 * ID + 1;
            int right_idx = 2 * ID + 2;
            int MAX = left_idx;
            int rootval = arr[ID];

            if (right_idx > len)
            {
                if (rootval < arr[left_idx])
                {
                    MAX = left_idx;
                }
            }
            else
            {
                if (arr[left_idx] < arr[right_idx])
                {
                    MAX = right_idx;
                }

                if (arr[MAX] < arr[ID])
                {
                    MAX = ID;
                }
            }

            std::swap(arr[ID], arr[MAX]);
        }
    }
};

int main()
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<unsigned> u(3, 100);
    Checker c;
    vector<int> arr_comm;

    for (int i = 0; i < 100; i++)
    {
        arr_comm.push_back(u(e));
    }

    c.checkDuplicate(arr_comm, arr_comm.size());
    return 0;
}