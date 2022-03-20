/*************************************************************************
	> File Name: 11.ContainerWithMostWater.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月07日 星期二 00时13分31秒
 ************************************************************************/
//https://leetcode.com/problems/container-with-most-water/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int end = height.size()-1;
		int start = 0;
		int max_container = (end-start)*std::min(height[end],height[start]);
		while(end >= start)
		{
			int tmp_max_container = (end-start)*std::min(height[end],height[start]);
			if(tmp_max_container > max_container) max_container = tmp_max_container;
			height[end] > height[start]?++start:--end;
		}
		return max_container;
    }
};


int main()
{
	Solution s;
	std::vector<int> arr{1,8,6,2,5,4,8,3,7};
	int val = s.maxArea(arr);
	cout<<val<<endl;
    return 0;
}

