/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   jumpFloorII.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: jumpFloorII.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat 14 Apr 2018 02:58:50 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int jumpFloorII(int number)
{
    if (number == 0)
    {
        return 0;
    }

    if (number == 1)
    {
        return 1;
    }

    return 2 * jumpFloorII(number - 1);
}

int rectCover(int number)
{
    if (number == 0)
    {
        return 0;
    }

    if (number == 1)
    {
        return 1;
    }

    return number * rectCover(number - 1);
}


int main()
{
    /*cout << jumpFloorII(0) << endl;
    cout << jumpFloorII(1) << endl;
    cout << jumpFloorII(2) << endl;
    cout << jumpFloorII(3) << endl;
    cout << jumpFloorII(4) << endl;
    cout << jumpFloorII(5) << endl;
    cout << jumpFloorII(6) << endl;
    cout << jumpFloorII(7) << endl;
    cout << jumpFloorII(8) << endl;*/
    cout << rectCover(2) << endl;
    cout << rectCover(3) << endl;
    cout << rectCover(4) << endl;
    cout << rectCover(5) << endl;
    cout << rectCover(6) << endl;
    return 0;
}

