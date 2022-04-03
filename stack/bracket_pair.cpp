/*
 @filename   bracket_pair.cpp
 @author     caonan
 @date       2022-04-02 09:45:56
 @reference     
 @url      
 @brief  给定一个只包含 "()[]{}" 六种字符的字符串。规定它们的优先级由外至内为："{}", "[]", "()"，
         同一级的可以嵌套，并列。要求判断给定的字符串是否是合法的括号字串？
         例："()", "{((()())())[()]}()" 是合法的。"())", "([])", "())(()" 都是不合法的。
*/
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

bool vailidBracketPair(string s){
    stack<char> t;
    map<char,char> diff{{']','['},{')','('},{'}','{'}};
    for(auto c:s){
        if(c == '{' or c == '(' or c == '['){
            //todo: 如果符号更多就没法搞了，得自定义个比较运算函数
            if(!t.empty() && (t.top() == '('&& c!='(' || t.top() == '[' && c=='{')){
                return false;
            }
            t.push(c);
        }else{
            if(t.empty() || diff[c] != t.top()){
                return false;
            }
            t.pop();
        }
    }
    return t.empty();
}

bool vailidBracketPair1(string s){
    struct bracketPair{
        bracketPair(char c){
            c_=c;
            switch(c_){
                case '{': w_=0;break;
                case '[': w_=1;break;
                case '(': w_=2;break;
            }
        }
        bool operator <(const bracketPair& oc){
            return w_ < oc.w_;
        }
        bool isLeftPair(){
            return c_ == '{' or c_ == '(' or c_ == '[';
        }
        bool isBracketPair(const bracketPair& left_pair){
            bool is;
            switch(left_pair.c_){
                case '{': return c_ == '}';
                case '[': return c_ ==']';
                case '(': return c_ == ')';
                default:return false;
            }
        }
        int w_{-1};
        char c_;
    };

    stack<bracketPair> t;
    for(auto c:s){
        bracketPair letter{c};
        if(letter.isLeftPair()){
            if(!t.empty() && letter < t.top()) return false;
            t.push(c);
        }else{
            if(t.empty() || !letter.isBracketPair(t.top())) return false;
            t.pop();
        }
    }
    return t.empty();
}

int main(){
    assert(vailidBracketPair("{((()())())[()]}()"));
    assert(vailidBracketPair("()"));
    assert(!vailidBracketPair("([])"));
    assert(!vailidBracketPair("())(()"));
    
    assert(vailidBracketPair1("{((()())())[()]}()"));
    assert(vailidBracketPair1("()"));
    assert(!vailidBracketPair1("([])"));
    assert(!vailidBracketPair1("())(()"));
    return 0;
}
