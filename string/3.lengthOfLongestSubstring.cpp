//https://leetcode.cn/problems/longest-substring-without-repeating-characters/solutions/3982/hua-dong-chuang-kou-by-powcai/
#include<iostream>
#include <unordered_map>
using namespace std;
//TODO: abba wrong answer
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int max_len = 0;
        for(int left = 0,right=0;right<s.size();right++){
            if(window.find(s[right])!=window.end()){
                left = window[s[right]]+1;
            }
            window[s[right]]=right;
            max_len = std::max(max_len,right-left+1);
        }
        return max_len;
    }
};

int main(){
    string str= "abba";
    Solution s;
    s.lengthOfLongestSubstring(str);
    return 0;
}