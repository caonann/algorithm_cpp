/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   hanno.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
// section1.cpp: 定义控制台应用程序的入口点。
//
// #include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string hanno(int n, string from, string help, string to)
{
    if (n == 1)
    {
        // cout << "move from " << from << " to " << to << endl;
        string ret = "move from " + from + " to " + to;
        return ret
    }
    else
    {
        hanno(n - 1, from, to, help);
        hanno(1, from, help, to);
        hanno(n - 1, help, from, to);
    }
}

int main()
{
    hanno(30, "left", "mid", "right");
    return 0;
}

