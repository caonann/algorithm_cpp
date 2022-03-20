/*
 @filename   9.cpp
 @author     caonan
 @date       2022-03-19 12:06:59
 @reference  剑指offer专项   
 @url      https://leetcode-cn.com/problems/ZVAVXX/
 @brief     给定一个正整数数组 nums和整数 k ，请找出该数组内乘积小于 k 的连续的子数组的个数
*/
#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 已知ABC < target, 新增一位X变成ABCX, 若ABCX < target 则新增的subarray中必须满足 1.连续 2.包含X
    // 所以从X向左数: X, CX, BCX, ABCX
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int j = 0;
        long sum = 1;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            sum*=nums[i];
            while(j<=i && sum >=k){
                sum /= nums[j++];
            }
            count+=i>=j?i-j+1:0;
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> nums{10,5,2,6};
    assert(8 == s.numSubarrayProductLessThanK(nums,100));
    vector<int> nums1{1,2,3};
    assert(0==s.numSubarrayProductLessThanK(nums1,0));
    return 0;
}
