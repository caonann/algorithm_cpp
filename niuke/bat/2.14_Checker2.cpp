#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <strings.h>
using namespace std;
class Checker {
public:
    bool checkDuplicate(vector<int> a, int n) {
        // write code here
        int depth = sizeof(int)*8;
        int arr_len =depth*2;
        char buffer[arr_len];
        bzero(buffer,arr_len);
        for(auto& const number:a){
            int depth_tmp =0;
            do{
                char bit = static_cast<char>(number %2);
                
                2*depth_tmp;
                number >> 1;
            }while(number);
            
        }
    }
};

int main()
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<unsigned> u(3, 100);
    Checker c;
    vector<int> arr_comm;

    for (int i = 0; i < 100; i++)
    {
        arr_comm.push_back(u(e));
    }

    c.checkDuplicate(arr_comm, arr_comm.size());
    return 0;
}