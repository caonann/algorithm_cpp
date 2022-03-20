/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   Fibonacci.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: Fibonacci.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Tue 10 Apr 2018 11:00:48 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;
//0 1 1 2 3 5 8 13
int Fibonacci2(int n)
{
    int first = 0;
    int second = 1;

    if (n <= 1)
    {
        return n;
    }

    int it = n - 1;

    while (it--)
    {
        int tmpsecond = first + second;
        first = second;
        second = tmpsecond;
    }

    return second;
}

int Fibonacci3(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 0)
    {
        return 0;
    }

    return Fibonacci2(n - 1) + Fibonacci2(n - 2);
}

map<int, int> ohash;

int Fibonacci(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 0)
    {
        return 0;
    }

    int lhs, rhs;

    if (ohash.find(n - 1) == ohash.end())
    {
        ohash[n - 1] = Fibonacci(n - 1);
        lhs = ohash[n - 1];
    }
    else
    {
        lhs = ohash[n - 1];
    }

    if (ohash.find(n - 2) == ohash.end())
    {
        ohash[n - 2] = Fibonacci(n - 2);
        rhs = ohash[n - 2];
    }
    else
    {
        rhs = ohash[n - 2];
    }

    return lhs + rhs;
}

int main()
{
    cout << Fibonacci(0) << endl;
    cout << Fibonacci(1) << endl;
    cout << Fibonacci(2) << endl;
    cout << Fibonacci(3) << endl;
    cout << Fibonacci(4) << endl;
    cout << Fibonacci(5) << endl;
    cout << Fibonacci(6) << endl;
    cout << Fibonacci(36) << endl;
    return 0;
}

