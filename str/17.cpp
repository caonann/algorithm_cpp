/*
 @filename   17.cpp
 @author     caonan
 @date       2022-03-29 15:09:16
 @reference  剑指offer专项   
 @url      https://leetcode-cn.com/problems/M1oyTv/
 @brief     给定两个字符串 s 和 t 。返回 s 中包含 t 的所有字符的最短子字符串。如果 s 中不存在符合条件的子字符串，则返回空字符串 "" 。
            如果 s 中存在多个符合条件的子字符串，返回任意一个。
            注意： 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
*/
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> map_store;
        for(auto c:t){
            map_store[c]++;
        }
        auto isAllLessEqZero = [](const unordered_map<char,int>& counts)->bool{
            for(auto&v :counts){
                if(v.second > 0 ){
                    return false;
                }
            }
            return true;
        };
        int left = 0;
        string shortest_str="";
        int min_len = 0x80000000-1;
        for(int right = 0;right<s.size();right++){
            if(map_store.find(s[right]) == map_store.end()) continue;
            map_store[s[right]]--;
            while(isAllLessEqZero(map_store)){
                if(min_len>right-left+1){
                    min_len = right-left+1;
                    shortest_str = s.substr(left,min_len);
                }

                if(map_store.find(s[left]) != map_store.end()){
                    map_store[s[left]]++;
                }
                left++;
            }
        }
        return shortest_str;
    }

    string minWindow1(string s, string t) {
        unordered_map<char,int> hs,ht;
        for(const auto& c:t) ht[c]++;
        int left=0,cnt=0;
        string ans;
        for(int right=0;right<s.size();right++){
            hs[s[right]]++;
            if(hs[s[right]] <= ht[s[right]]) cnt++; //统计有效字符窗口长度
            while(hs[s[left]] > ht[s[left]]){       //右移左边界
                hs[s[left]]--;
                left++;
            }         

            if(cnt == t.length()){
                if(ans.empty()||ans.length()> right-left+1){
                    ans = s.substr(left,right-left+1);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    assert(s.minWindow("ADOBECODEBANC","ABC") == "BANC");
    assert(s.minWindow("a","a") == "a");
    assert(s.minWindow("a","aa") == "");

    assert(s.minWindow1("ADOBECODEBANC","ABC") == "BANC");
    assert(s.minWindow1("a","a") == "a");
    assert(s.minWindow1("a","aa") == "");
    return 0;
}
