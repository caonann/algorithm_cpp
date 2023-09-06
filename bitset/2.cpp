//https://leetcode-cn.com/problems/JFETK5/
#include <iostream>
#include <assert.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty()){
            return b;
        }
        if(b.empty()){
            return a;
        }
        string ret;
        //cout<<"default capacity is "<<ret.capacity()<<endl;
        int longer_len =0;
        int short_len = 0;
        const char *pshort = nullptr;
        const char *plonger = nullptr;
        if(a.length() > b.length()){
            pshort = b.data();
            plonger = a.data();
            longer_len = a.length();
            short_len = b.length();
        }else{
            pshort = a.data();
            plonger = b.data();
            longer_len = b.length();
            short_len = a.length();
        }

        ret.reserve(longer_len+1);
        //cout<<"capacity is "<<ret.capacity()<<endl;
        int isCarryBit = 0;
        int j = longer_len-1;
        for(int i=short_len-1;i>=0;i--,j--){
            int a = plonger[j]-'0';
            int b = pshort[i]-'0';
            //cout<<"a:"<<a<<endl;
            //cout<<"b:"<<b<<endl;
            int carry = (a+b+isCarryBit)%2;
            isCarryBit = (a+b+isCarryBit)/2;
            ret.insert(0,std::to_string(carry));
        }

        for(;j>=0;j--){
            int a = plonger[j]-'0';
            int carry = (a+isCarryBit)%2;
            isCarryBit = (a+isCarryBit)/2;
            ret.insert(0,std::to_string(carry));
        }

        if(isCarryBit){
            ret.insert(0,std::to_string(isCarryBit));
        }
        return ret;
    }
    
    string addBinary2(string a,string b){
        if(a.length()<b.length()) std::swap(a,b);
        
        for(int j = b.length()-1,i=a.length()-1;j>=0;j--,i--){
            a[i]+=b[j]-'0';
        }
        a.insert(0,"0");
        for(int i=a.length()-1;i>=1;i--){
            if(a[i]-'0'>=2){
                a[i]-=2;
                a[i-1]+=1;
            }
        }

        return a[0] == '0'? a.substr(1): a;
    }
};

int main(){
    Solution s;
    const auto &ret = s.addBinary("11011","101");
    assert(s.addBinary("11011","101") == "100000");
    assert(s.addBinary("11","10") == "101");
    assert(s.addBinary("1010","1011") == "10101");
    cout<<s.addBinary2("1010","1011");
    return 0;
}