/*
 @filename   LongestPalindromicSubstring.cpp
 @author     caonan
 @date       2022-04-04 14:50:06
 @reference   leetcode  
 @url    https://leetcode-cn.com/problems/longest-palindromic-substring/
 @brief  给你一个字符串 s，找到 s 中最长的回文子串。
*/
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>
using namespace std;


class Solution {
public:
    //中心扩展法
    string longestPalindrome(string s) {
        string t="#";
        for(const auto& c:s){
            t+=c;
            t+="#";
        }
        string longest_str;
        for(int i=1;i<t.length()-1;i++){
            int left = i;
            int right= i;
            while(left>=0 && right<t.length()){
                if(t[left] == t[right]){
                    if(longest_str.length() < right-left+1)
                        longest_str = t.substr(left,right-left+1);//每次都有拷贝，是否记住下标索引更好点？
                }else{
                    break;
                }
                left--;
                right++;
            }
        }

        auto noSpaceEnd = std::remove(longest_str.begin(),longest_str.end(),'#');
        longest_str.erase(noSpaceEnd,longest_str.end());
        return longest_str;
    }

    //用左右下标记录最大回文子串，减少字符串拷贝
    string longestPalindrome1(string s) {
        string t="#";
        for(const auto& c:s){
            t+=c;
            t+="#";
        }
        
        int max_len = INT_MIN;
        int left_max = 0;
        int right_max = 0;
        for(int i=1;i<t.length()-1;i++){
            int left = i;
            int right= i;
            while(left>=0 && right<t.length()){
                if(t[left] == t[right]){
                    if(max_len < right-left+1){
                        max_len = right-left+1;
                        left_max = left;
                        right_max = right;
                    }
                }else{
                    break;
                }
                left--;
                right++;
            }
        }
        string longest_str = t.substr(left_max,right_max-left_max+1);
        auto noSpaceEnd = std::remove(longest_str.begin(),longest_str.end(),'#');
        longest_str.erase(noSpaceEnd,longest_str.end());
        return longest_str;
    }

    //空间复杂度o(1),不借助额外字符串修改
    string longestPalindrome2(string s) {
        int max_len = INT_MIN;
        int left_max=0;
        int right_max=0;
        for(int i=0;i<s.length();i++){
            int left = i;
            int right = i;
            auto calc = [&](){
                while(left>=0&&right<s.length()){
                    if(s[left] == s[right]){
                        if(right-left+1 > max_len){
                            max_len = right-left+1;
                            left_max = left;
                            right_max = right;
                        }
                    }else{
                        break;
                    }
                    left--;
                    right++;
                }
            };
            calc();
            left=i;
            right = i+1;
            calc();
        }
        string longest_str = s.substr(left_max,right_max-left_max+1);
        return longest_str;
    }
    //todo:进阶，Manacher
};

int main(){
    Solution s;
    cout<<s.longestPalindrome("babad")<<endl;
    cout<<s.longestPalindrome("a")<<endl;
    cout<<s.longestPalindrome("")<<endl;
    cout<<s.longestPalindrome("cbbd")<<endl;
    cout<<"-----------------"<<endl;
    cout<<s.longestPalindrome1("babad")<<endl;
    cout<<s.longestPalindrome1("a")<<endl;
    cout<<s.longestPalindrome1("")<<endl;
    cout<<s.longestPalindrome1("cbbd")<<endl;
    cout<<"-----------------"<<endl;
    cout<<s.longestPalindrome2("babad")<<endl;
    cout<<s.longestPalindrome2("a")<<endl;
    cout<<s.longestPalindrome2("")<<endl;
    cout<<s.longestPalindrome2("cbbd")<<endl;   
    return 0;
}
