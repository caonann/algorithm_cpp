/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   2.15_Merge.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
#include "common_define.h"
// https://www.nowcoder.com/study/vod/1/2/15
class Merge
{
public:
    int *mergeAB(int *A, int *B, int n, int m)
    {
        int length = n + m - 1;

        while (n - 1 >= 0 && m - 1 >= 0)
        {
            if (A[n - 1] < B[m - 1])
            {
                A[length] = B[m - 1];
                m--;
            }
            else
            {
                A[length] = A[n - 1];
                n--;
            }

            length--;
        }

        while (n - 1 >= 0)
        {
            A[length--] = A[n - 1];
            n--;
        }

        while (m - 1 >= 0)
        {
            A[length--] = B[m - 1];
            m--;
        }

        return A;
    }
};

int main()
{
    int A[100] {1, 3, 5, 8, 9};
    int B[] {2, 4, 7, 10};
    Merge m;
    int *Aret = m.mergeAB(A, B, 5, 4);

    for (int i = 0; i < 9; i++)
    {
        cout << Aret[i] << " ";
    }

    cout << endl;
    return 0;
}