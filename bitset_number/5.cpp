//https://leetcode-cn.com/problems/aseY1I/
//给定一个字符串数组 words，请计算当两个字符串 words[i] 和 words[j] 不包含相同字符时，
//它们长度的乘积的最大值。假设字符串中只包含英语的小写字母。如果没有不包含相同字符的一对字符串，返回 0。

#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <assert.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<bool>> flags(words.size(),vector<bool>(26,false)); 
        for(int i=0;i<words.size();i++){
            for(auto& c:words[i]){
                flags[i][c-'a'] = true;
            }
        }

        int ret = 0;
        for(int i=0;i<flags.size();i++){
            for(int j = i+1;j<flags.size();j++){
                int sum = 0;
                for(int k=0;k<26;k++){
                    if(flags[i][k] && flags[j][k]){
                        break;
                    }
                    sum++;
                }

                if(sum == 26){
                    int t = words[i].length()*words[j].length();
                    ret = std::max(ret,t);
                }
            }
        }
        return ret;
    }

    //位运算的方法,时间复杂度同样是n2，但是会比上面优化一些
    int maxProduct2(vector<string>& words) {
        vector<int> flags(words.size(),0);
        for(int i=0;i<words.size();i++){
            for(auto& c:words[i]){
                flags[i]|= 1<<(c-'a');
            }
        }

        int ret = 0;
        for(int i=0;i<flags.size();i++){
            for(int j = i+1;j<flags.size();j++){
                if (flags[i] & flags[j]){
                    continue;
                }
                int t = words[i].length()*words[j].length();
                ret = std::max(ret,t);
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    vector<string> words{"abcw","baz","foo","bar","fxyz","abcdef"};
    assert(s.maxProduct(words)==16);
    assert(s.maxProduct2(words)==16);
    vector<string> words2{"eae","ea","aaf","bda","fcf","dc","ac","ce","cefde","dabae"};
    assert(s.maxProduct(words2)==15);
    assert(s.maxProduct2(words2)==15);
    return 0; 
}