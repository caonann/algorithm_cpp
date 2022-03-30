/*
 @filename   17.cpp
 @author     caonan
 @date       2022-03-29 15:09:16
 @reference  https://leetcode-cn.com/problems/M1oyTv/   
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
    //O(s.len*t.len)
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
};

int main(){
    Solution s;
    assert(s.minWindow("ADOBECODEBANC","ABC") == "BANC");
    assert(s.minWindow("a","a") == "a");
    assert(s.minWindow("a","aa") == "");
    return 0;
}
