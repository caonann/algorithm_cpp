#include "common_define.h"

class Solution {
public:
    void push(int value) {
        stack_.push(value);
        if(minStack_.empty())
        {
            minStack_.push(value);
        }
        else
        {
            if(minStack_.top() > value)
            {
                minStack_.push(value);
            }
            else{
                minStack_.push(minStack_.top());
            }
        }
    }
    void pop() {
        stack_.pop();
        minStack_.pop();
    }
    int top() {
        return stack_.top();
    }
    int min() {
        return minStack_.top();
    }

private:
    std::stack<int> stack_;
    std::stack<int> minStack_;
};


TEST(NiuKeBatTests, GetMinStack)
{
    Solution s;
    for(int i=0;i<10;i++)
    {
        s.push(i);
    }

    EXPECT_EQ(s.min(),0);
    EXPECT_EQ(s.top(),9);
    s.pop();
    EXPECT_EQ(s.min(),0);
    EXPECT_EQ(s.top(),8);
}