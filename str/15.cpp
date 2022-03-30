/*
 @filename   15.cpp
 @author     caonan
 @date       2022-03-27 08:47:59
 @reference  剑指offer专项      
 @url        https://leetcode-cn.com/problems/VabMRr/
 @brief     给定两个字符串 s 和 p，找到 s 中所有 p 的 变位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
            变位词 指字母相同，但排列不同的字符串。
*/
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if(s.length()< p.length()){
            return ret;
        }
        int counts[26]{0};
        for(int i=0;i<p.length();i++){
            counts[p[i]-'a']++;
            counts[s[i]-'a']--;
        }
        auto isAllZero = [](int arr[])->bool{
            for(int i=0;i<26;i++){
                if(arr[i] !=0 ){
                    return false;
                }
            }
            return true;
        };

        if(isAllZero(counts)){
            ret.push_back(0);
        }
        for(int i=p.length();i<s.length();i++){
            counts[s[i]-'a']--;
            counts[s[i-p.length()]-'a']++;
            if(isAllZero(counts)){
                ret.push_back(i-p.length()+1);
            }
        }

        return ret;
    }

    // isAllZero函数实际上每次都遍历26次，可以针对这里做差值优化
    vector<int> findAnagrams(string s, string p) {
        
    }
};

int main(){
    Solution s;
    vector<int> ret{0,6};
    assert(s.findAnagrams("cbaebabacd","abc") == ret);
    vector<int> ret1{0,1,2};
    assert(s.findAnagrams("abab","ab") == ret1);
    return 0;
}
