/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   longestarr.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int GetLongestArr(vector<int> &arr, int k)
{
    if (arr.empty())
    {
        return 0;
    }

    int sum = 0;
    int len = 0;
    int i = 0;
    map<int, int> arrmap;
    arrmap.insert(make_pair(0, -1));

    for (auto &item : arr)
    {
        sum += item;

        if (arrmap.count(sum - k))
        {
            int curlen = i - arrmap[sum - k];
            len = curlen > len ? curlen : len;
        }

        if (!arrmap.count(sum))
        {
            arrmap.insert(make_pair(sum , i));
        }

        i++;
    }

    return len;
}

int main()
{
    vector<int> intarr = { 1, 2, 2, 2, 5 };
    cout << GetLongestArr(intarr, 7) << endl;
    return 0;
}