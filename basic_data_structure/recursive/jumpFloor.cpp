/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   jumpFloor.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: jumpFloor.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat 14 Apr 2018 02:13:27 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int jumpFloor(int number)
{
    int i = 0;
    int j = 1;

    if (number == 0)
    {
        return 0;
    }

    if (number == 1)
    {
        return 1;
    }

    int sum = 1;

    for (int index = 2; index <= number; index++)
    {
        sum += j;
        int t = i;
        i = j;
        j = t + j;
    }

    return sum;
}

int main()
{
    cout << jumpFloor(0) << endl;
    cout << jumpFloor(1) << endl;
    cout << jumpFloor(2) << endl;
    cout << jumpFloor(3) << endl;
    cout << jumpFloor(4) << endl;
    cout << jumpFloor(5) << endl;
    cout << jumpFloor(6) << endl;
    cout << jumpFloor(7) << endl;
    cout << jumpFloor(8) << endl;
    return 0;
}

