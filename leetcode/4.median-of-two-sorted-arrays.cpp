/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   4.median-of-two-sorted-arrays.cpp
 @author     root
 @version
 @date       2019/09/27 01:02
 @brief
 @details    2019/09/27 root create
*/
#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.65%)
 * Total Accepted:    393.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 *
 * Example 1:
 *
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 *
 * Example 2:
 *
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 *
 *
 */


class Solution
{
public:
    // be O(n+m) storage O(n+m)
    /*
      √ Accepted
      √ 2084/2084 cases passed (44 ms)
      √ Your runtime beats 71.73 % of cpp submissions
      √ Your memory usage beats 16.64 % of cpp submissions (22.3 MB)
    */
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> newtmp;
        auto iter1 = nums1.begin();
        auto iter2 = nums2.begin();

        while (iter1 != nums1.end() && iter2 != nums2.end())
        {
            if (*iter1 < *iter2)
            {
                newtmp.push_back(*iter1++);
            }
            else
            {
                newtmp.push_back(*iter2++);
            }
        }

        while (iter1 != nums1.end())
        {
            newtmp.push_back(*iter1++);
        }

        while (iter2 != nums2.end())
        {
            newtmp.push_back(*iter2++);
        }

        double median = 0;
        int vectorsize = newtmp.size();

        if ((vectorsize % 2) == 0)
        {
            median = (newtmp[vectorsize / 2] + newtmp[vectorsize / 2 - 1]) / 2.0;
        }
        else
        {
            median = newtmp[vectorsize / 2];
        }

        return median;
    }
};

void test_solution_1()
{
    Solution test;
    vector<int> num1 = { 1, 2, 5, 8, 10 };
    vector<int> num2 = { 1, 3, 6, 7, 8, 9 };
    cout << test.findMedianSortedArrays(num1, num2) << endl;
}

int main()
{
    return 0;
}