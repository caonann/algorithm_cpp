/*
 @filename   7.cpp
 @author     caonan
 @date       2022-03-17 15:14:28
 @reference  剑指offer专项
 @url   https://leetcode-cn.com/problems/1fGaJU/
 @brief 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a ，b ，c ，使得 a + b + c = 0 ？请找出所有和为 0 且 不重复 的三元组。

*/
#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int length = nums.size();
        if(length < 3){
            return ret;
        }

        std::sort(nums.begin(),nums.end());

        int i = 0;
        while(i<length -2){
            addTwoSum(i,nums,ret);
            int tmp = nums[i];
            while(tmp==nums[i] && i<length -2){
                i++;
            }
        }
        return ret;
    }
private:
    void addTwoSum(int i,vector<int>& nums,vector<vector<int>>& ret){
        int j = i+1;
        int k = nums.size()-1;
        while(j<k){
            if(nums[i]+nums[j]+nums[k] == 0){
                ret.push_back(vector<int>{nums[i],nums[j],nums[k]});
                int tmp = nums[j];
                while(tmp == nums[j] && j<k){
                    j++;
                }
            }else if(nums[i]+nums[j]+nums[k] > 0){
                k--;
            }else{
                j++;
            }
        }
    }
};

void print_vec(const vector<vector<int>>& arrs){
    for(auto& v:arrs){
        for(auto& vv:v){
            printf("%d ",vv);
        }
        printf("\n");
    }
}

int main(){
    Solution s;
    vector<int> nums{-1,0,1,2,-1,-4};
    vector<vector<int>> ret{{-1,-1,2},{-1,0,1}};
    //auto tmp = s.threeSum(nums);
    //print_vec(tmp);
    assert(s.threeSum(nums) == ret);

    vector<vector<int>> ret1;
    vector<int> nums1{};
    assert(s.threeSum(nums1) == ret1);

    vector<vector<int>> ret2{{0,0,0}};
    vector<int> nums2{0,0,0,0};
    assert(s.threeSum(nums2) == ret2);
    return 0;
}
