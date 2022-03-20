//https://leetcode-cn.com/problems/w3tCBm/
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1,0);
        for(int i=1;i<=n;i++){
            int j = i;
            while(j!=0){
                j = j&(j-1);
                ret[i]++;
            }
        }
        return ret;
    }

    vector<int> countBits2(int n) {
        vector<int> ret(n+1,0);
        for(int i=1;i<=n;i++){
            ret[i] = ret[i&(i-1)]+1;
        }
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> ret = s.countBits(5);
    vector<int> tmp{0,1,1,2,1,2};
    assert(ret == tmp);
    assert(s.countBits2(5) == tmp);
    return 0;
}