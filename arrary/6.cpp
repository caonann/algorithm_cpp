//https://leetcode-cn.com/problems/kLl5u1/
#include<iostream>
#include <vector>
#include <assert.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int end_index = numbers.size()-1;
        int start_index = 0;
        while(start_index< end_index){
          if( numbers[start_index]+numbers[end_index] > target){
              end_index--;
          }else if(numbers[start_index]+numbers[end_index] < target){
              start_index++;
          }else{
              return vector<int>{start_index,end_index};
          }
        }
        return  vector<int>{-1,-1};
    }

    //思路同上，但是代码更简洁
    vector<int>twoSum1(vector<int>& numbers, int target) {
        int j = numbers.size()-1;
        int i = 0;
        while(i<j && numbers[i] + numbers[j] != target){
            if(numbers[i] + numbers[j] > target){
                j--;
            }else{
                i++;
            }
        }
        return vector<int>{i,j};
    }
};

int main(){
    Solution s;
    vector<int> nums{1,2,4,6,10};
    assert((s.twoSum(nums,8)==vector<int>{1,3}));
    assert((s.twoSum1(nums,8)==vector<int>{1,3}));
    vector<int> nums1{-1,0};
    assert((s.twoSum(nums1,-1)==vector<int>{0,1}));
    assert((s.twoSum1(nums1,-1)==vector<int>{0,1}));
    return 0;
}