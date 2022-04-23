/*
 @filename   subtractTwoNumbers.cpp
 @author     caonan
 @date       2022-04-19 11:07:41
 @reference
 @url
 @brief  一个数组a[n]，数组中都是正整数， 求max(a[i]-a[j])，0 <= i < j < n; 要求时间复杂度O(n)
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

int subtractTwoNumbers(vector<int>& arr)
{
    int max = 0;
    for (int i = 0, j = 0; j < arr.size(); j++) {
        if (arr[j] > arr[i]) {
            i = j;
        } else {
            max = std::max(max, arr[i] - arr[j]);
        }
    }
    return max;
}

void uinttest(vector<int> arr)
{
    int max = subtractTwoNumbers(arr);
    cout << "max is:" << max << endl;
}
int main()
{
    uinttest(vector<int>{10, 6, 8, 1, 20, 19, 18, 30});
    uinttest(vector<int>{10, 30, 8, 1, 20, 19, 2, 30});
    return 0;
}
