/*************************************************************************
	> File Name: 5381.querys_key.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月12日 星期日 11时39分20秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
//https://leetcode-cn.com/contest/weekly-contest-184/problems/queries-on-a-permutation-with-key/

/*
给你一个待查数组 queries ，数组中的元素为 1 到 m 之间的正整数。
请你根据以下规则处理所有待查项 queries[i]（从 i=0 到 i=queries.length-1）：

一开始，排列 P=[1,2,3,...,m]。
对于当前的 i ，请你找出待查项 queries[i] 在排列 P 中的位置（下标从 0 开始），然后将其从原位置移动到排列 P 的起始位置（即下标为 0 处）。
注意， queries[i] 在 P 中的位置就是 queries[i] 的查询结果。
请你以数组形式返回待查数组  queries 的查询结果。
*/

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
		vector<int> p;
		for(int i=1;i<=m;i++) p.push_back(i);
		vector<int> ret;
		for(int i=0;i<queries.size();i++)
		{
			int queries_i = queries[i];
			int p_val = get_and_op_index(queries_i,p);
			ret.push_back(p_val);
		}
		return ret;
    }
private:
	int get_and_op_index(int val,vector<int>& p)
	{
		int ret = 0;
		for(int i=0;i<p.size();i++)
		{
			if(val == p[i])
			{
				ret = i;
				break;
			}
		}
		for(int end=ret;end>=1;end--)
		{
			p[end] = p[end-1];
		}
		p[0] = val;
		return ret;
	}
};

void test(vector<int> queries, int m)
{
	Solution s;
	auto arr = s.processQueries(queries,m);
	for(auto& v:arr){
		printf("%d ",v);
	}
	printf("\n");
}
int main()
{
	test({4,1,2,2},4);
	test({7,5,5,8,3},8);
	test({0,0,1},1);
    return 0;
}

