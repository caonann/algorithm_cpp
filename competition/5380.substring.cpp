/*************************************************************************
	> File Name: 5380.substring.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月12日 星期日 11时07分03秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;
//https://leetcode-cn.com/contest/weekly-contest-184/problems/string-matching-in-an-array/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
		vector<string> ret;
		set<string> string_set;
		for(auto& word :words)
		{
			for(auto& substring:words)
			{
				if(substring.find(word) != std::string::npos)
				{
					if(substring != word && string_set.find(word) == string_set.end()) {
						string_set.insert(word);
						ret.push_back(word);
					};
				}
			}
		}
		return ret;
    }
};

void test(vector<string> words)
{
	Solution s;
	auto ret = s.stringMatching(words);
	for(auto v:ret)
	{
		printf("%s ",v.c_str());
	}
	printf("\n");
}
int main()
{
	test({"mass","as","hero","superhero"});
	test({"leetcode","et","code"});
	test({"blue","green","bu"});
	test({"leetcoder","leetcode","od","hamlet","am"});
	test({"jak","yjakdn","tj","yyjakdn"});
    return 0;
}

