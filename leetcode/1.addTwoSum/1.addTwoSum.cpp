/*************************************************************************
	> File Name: 1.addTwoSum.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月12日 星期日 22时06分06秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
//https://leetcode-cn.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> ret_map;
		for(int i=0;i<nums.size();i++)
		{
			ret_map[nums[i]] = i;
		}

		for(int i=0;i<nums.size();i++)
		{
			int other = target-nums[i];
			if(ret_map.find(other) != ret_map.end() && ret_map[other] != i) return vector<int>{i,ret_map[other]};
		}
		return vector<int>{};
    }
};

void test(vector<int> nums,int target)
{
	Solution s;
	auto arr = s.twoSum(nums,target);
	for(auto&v:arr)
	{
		printf("%d ",v);
	}
	printf("\n");
}
int main()
{
	test({2, 7, 11, 15},9);
	test({1,5,6,9,7},16);
	test({3,2,4},6);
    return 0;
}

