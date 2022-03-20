/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   1-2_hannota.cpp
 @author     root
 @version
 @date       2019/09/29 01:31
 @brief
 @details    2019/09/29 root create
*/
#include <iostream>
#include <vector>
#include <stdint.h>
using namespace std;
// 给定一个数n，表示n层汉诺塔问题，请打印最优步数的所有过 程

void hannota(int n, const string &src, const string &mid, const string &dst)
{
    if (n <= 0)
    {
        return;
    }

    if (1 ==  n)
    {
        printf("from %s to %s\n", src.c_str(), dst.c_str());
    }
    else
    {
        hannota(n - 1, src, dst, mid);
        hannota(1, src, mid, dst);
        hannota(n - 1, mid, src, dst);
    }
}


/*
进阶：给定一个汉诺塔的状况用数组arr表示（arr中只有1，2， 3三种数字），请返回这是汉诺塔最优步数的第几步？
举例： arr = {3,2,1} arr长度为3，表示这是一个3层汉诺塔问题；
    arr[0] == 3表示上面的汉诺塔在右边；
    arr[1] == 2表示中间的汉诺塔在中间；
    arr[2] == 1表示底下的汉诺塔在左间；
    这种状况是3层汉诺塔最优步数的第2步，所以返回2。
*/

// 笨办法，顺序遍历查找o 2^n

int main()
{
    hannota(10, "a", "b", "c");
    return 0;
}
