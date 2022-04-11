//https://leetcode-cn.com/problems/WGki4K/
#include<iostream>
#include <vector>
#include <map>
#include <assert.h>
using namespace std;

//给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

class Solution {
public:
    //空间占用高
    int singleNumber(vector<int>& nums) {
        map<int,int> tmp;
        for(auto& v:nums){
            tmp[v]++;
        }

        for(auto&v:tmp){
            if(v.second == 1){
                return v.first;
            }
        }
        return -1;
    }

    //空间复杂度o1,时间复杂度nk
    //简称仅有一次出现的元素为“答案”，那么答案的每一位和所有其他元素相加有：总和%3 == 答案对应的值
    int singleNumber2(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<32;i++){
            int tmp=0;
            for(auto &v:nums){
                tmp+=v>>i&1;
            }
            ans |= tmp%3<<i;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> t{0,1,0,1,0,1,100};
    assert(s.singleNumber(t) == 100);
    assert(s.singleNumber2(t) == 100);
    return 0;
}