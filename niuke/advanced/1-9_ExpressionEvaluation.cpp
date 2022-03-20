/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   1-9_ExpressionEvaluation.cpp
 @author     caonan
 @version
 @date       2019/10/04 13:22
 @brief
 @details    2019/10/04 root create
*/
#include "common_define.h"
// https://www.nowcoder.com/questionTerminal/9566499a2e1546c0a257e885dfdbf30d

/*
给定一个字符串描述的算术表达式，计算出结果值。
输入字符串长度不超过100，合法的字符包括”+, -, *, /, (, )”，”0-9”，
字符串内容的合法性及表达式语法的合法性由做题者检查。本题目只涉及整型计算
*/

// keyword 逆波兰表达式
// str="48*((70-65)-43)+8*1" return -1816
// todo:对于除法 float，还未能精确计算
// 常规方法 遍历+递归
class ExpressionCompute
{
public:
    float calculateExpression(std::string expression)
    {
        return value(expression, 0)[0];
    }
    // private:
    // return value {calc sum,index}
    vector<float> value(std::string &expression, int index)
    {
        auto addNum =[](std::deque<string> &que, float num)->void
        {
            if (!que.empty())
            {
                std::string symbol = que.back();

                if (symbol == "*" || symbol == "/")
                {
                    que.pop_back();
                    float pre_num = std::stof(que.back());
                    num = symbol == "*" ? pre_num * num : pre_num / num;
                    que.pop_back();
                }
            }

            que.push_back(std::to_string(num));
        };
        float pre = 0;
        std::deque<string> que;

        while (index < expression.length() && expression[index] != ')')
        {
            if (expression[index] >= '0' && expression[index] <= '9')
            {
                pre = pre * 10 + expression[index++] - '0';
            }
            else if (expression[index] != '(')
            {
                addNum(que, pre);
                // 插入符号
                que.push_back(std::string(1, expression[index++]));
                pre = 0;
            }
            else// ()
            {
                auto ret = value(expression, index + 1);
                index = static_cast<int>(ret[1]) + 1;
                pre = ret[0];
            }
        }

        addNum(que, pre);
        return vector<float> {getNum(que), static_cast<float>(index)};
    }

    // 只有+ -组成的计算式 a+b-c...
    float getNum(std::deque<std::string> &que)
    {
        float cur = 0;
        float sum = 0;
        bool addsum = true;

        while (!que.empty())
        {
            std::string front = que.front();
            que.pop_front();

            if (front == "+")
            {
                addsum = true;
            }
            else if (front == "-")
            {
                addsum = false;
            }
            else
            {
                cur = std::stof(front);
                sum += addsum ? cur : -cur;
            }
        }

        return sum;
    }
};


TEST(NiuKeAdvanced, ExpressionComputeAddSubtract)
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<unsigned> u(30, 1000);
    ExpressionCompute ex;
    std::deque<std::string> que;
    std::string expression;
    float ret = 0;
    bool add = true;

    for (int i = 1; i < 100; i++)
    {
        if (i % 2 == 0)
        {
            if (u(e) % 2 == 0)
            {
                expression += "+";
                add = true;
            }
            else
            {
                expression += "-";
                add = false;
            }
        }
        else
        {
            int num = u(e);
            expression += std::to_string(num);
            ret += add ? num : -num;
        }
    }

    int pre = 0;

    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            pre = pre * 10 + static_cast<int>(expression[i] - '0');
        }
        else
        {
            que.push_back(std::to_string(pre));
            pre = 0;
            que.push_back(std::string(1, expression[i]));
        }
    }

    que.push_back(std::to_string(pre));
    EXPECT_EQ(ret, ex.getNum(que));
    EXPECT_EQ(ret, ex.calculateExpression(expression));
}


TEST(NiuKeAdvanced, ExpressionComputeMultiplicationDivision)
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<unsigned> u(30, 1000);
    ExpressionCompute ex;
    std::string expression;
    float ret = 0;
    int seed = 0;

    for (int i = 1; i < 100; i++)
    {
        int num = u(e);
        expression += std::to_string(num);
        seed = num%4;
        switch (seed)
        {
            case 0:
                expression += "+";
                ret += num;
                break;

            case 1:
                expression += "-";
                ret -= num;
                break;

            case 2:
                expression += "*";
                ret *= num;
                break;

            case 3:
                expression += "*";
                ret /= num;
                break;
        }
    }
    expression = expression.substr(0 ,expression.length()-1);
    //EXPECT_EQ(static_cast<int>(ret), static_cast<int>(ex.calculateExpression(expression)));
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    ExpressionCompute ex;
    cout << ex.calculateExpression("1+2+3-4*(5-4*(2+8)+(3-4))+6-7*8*9+(5-4*(2+8)+(3-4))") << endl;
    int ret = 1 + 2 + 3 - 4 * (5 - 4 * (2 + 8) + (3 - 4)) + 6 - 7 * 8 * 9 + (5 - 4 * (2 + 8) + (3 - 4));
    cout << ret << endl;
    cout << ex.calculateExpression("1/2") << endl;
    cout << ex.calculateExpression("1*2") << endl;

    /*
    string str;
    while(getline(cin,str))
    {
        cout<<ex.calculateExpression(str)<<endl;
    }
    */
    return RUN_ALL_TESTS();
}