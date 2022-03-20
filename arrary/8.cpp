/*
 @filename   8.cpp
 @author     caonan
 @date       2022-03-18 07:43:10
 @reference  剑指offer专项   
 @url      https://leetcode-cn.com/problems/2VG8Kg/
 @brief  给定一个含有 n 个正整数的数组和一个正整数 target,
 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
 并返回其长度。如果不存在符合条件的子数组，返回 0 。
*/
#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    //代码还是不够简洁
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = i;
        int sum = 0;
        int min = 0x80000000-1;
        while(i<=j && j<nums.size()){
            sum += nums[j];
            while(sum >= target && i<=j){
                min = std::min(j-i+1,min);
                sum -=nums[i++];
            }
            j++;
        }
       
        return min == 0x80000000-1?0:min;
    }

    //改用for循环更加简洁一点点
    int minSubArrayLen1(int target, vector<int>& nums){
        int j = 0;
        int sum = 0;
        int min = 0x80000000-1;
        for(int i=0 ;i<nums.size();i++){
            sum += nums[i];
            while(sum >= target){
                min = std::min(i-j+1,min);
                sum -=nums[j++];
            }
        }
        return min == 0x80000000-1?0:min;
    }
};

int main(){
    Solution s;
    vector<int> nums{2,3,1,2,4,3};
    assert(s.minSubArrayLen(7,nums)==2);
    assert(s.minSubArrayLen1(7,nums)==2);
    vector<int> nums1{1,4,4};
    assert(s.minSubArrayLen(4,nums1)==1);
    assert(s.minSubArrayLen1(4,nums1)==1);
    vector<int> nums2{1,1,1,1,1,1,1,1};
    assert(s.minSubArrayLen(11,nums2)==0);
    assert(s.minSubArrayLen1(11,nums2)==0);
    return 0;
}
