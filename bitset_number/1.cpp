//链接：整数除法:https://leetcode-cn.com/problems/xoh6Oh/
//来源：剑指offer专项进阶01

#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <climits>
using namespace std;
class Solution {
public:
    //复杂度logn
    int divide(int a, int b) {
        //assert(b);
        if(a == INT_MIN && b == -1){//考虑溢出情况
            return INT_MAX;
        }

        int negative = 2;
        if(a > 0){
            negative--;
            a=-a;
        }
        if(b>0){    
            negative--;
            b = -b;
        }

        int ret = 0;
        while(a <= b){
            int divide_count = 1;
            int value = b;
            while(INT_MIN/2 <= value && a<=value+value){
                if (divide_count > INT_MAX / 2) return INT_MIN; //-2147483648/1的case会溢出
                divide_count+=divide_count;
                value+=value;
            }
            a-=value;
            ret +=divide_count;
        }

        return negative == 1? -ret:ret;
    }
    //复杂度o1
    int divide2(int a,int b){
        if (a == INT_MIN && b == -1){
            return INT_MAX;
        }

        if(b == INT_MIN){//这种情况只有两种可能
            return a==INT_MIN?1:0;
        }
        
        int ret = 0;
        if(a == INT_MIN){//不减一下做完abs会溢出
            ret +=1;
            a-=-abs(b);
        }
        int sign = (a>0)^(b>0);

        int ua = abs(a);
        int ub = abs(b);
        
        for(int i=31;i>=0;i--){
            if ((ua>>i) >= ub){       
                if(ret > INT_MAX-(1<<i)){//-2147483648/1的情况，ret会溢出
                    return INT_MIN;
                }
                ret+=1<<i;
                ua-=(ub<<i);
            }
        }

        return sign == 1?-ret:ret;
    }
};

int main(){
    Solution s;
    assert(s.divide(17,5) ==  3);
    assert(s.divide(17,3) ==  5);
    assert(s.divide(1,1) ==  1);
    assert(s.divide(0,1) ==  0);
    assert(s.divide(0,10) ==  0);
    assert(s.divide(17,-3) == -5);
    //case 2147483647 + 1
    //case -2147483648/1
    //cout<<s.divide(-2147483648,1);
    int t = 5<<31;//左移越界的话就变为INT_MIN
    cout<<s.divide2(17,5);
    return 0;
}