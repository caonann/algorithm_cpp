/*
 @filename   40.cpp
 @author     caonan
 @date       2022-04-12 09:16:36
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/PLYXKQ/
 @brief  给定一个由 0 和 1 组成的矩阵 matrix ，找出只包含 1 的最大矩形，并返回其面积。
注意：此题 matrix 输入格式为一维 01 字符串数组。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution
{
   public:
    int maximalRectangle(vector<string>& matrix)
    {
        int max = 0;
        for (int row = 0; row < matrix.size(); row++) {
            auto line = getLine(matrix, row);
            max = std::max(max, getLineMax(line));
        }
        return max;
    }

   private:
    vector<int> getLine(const vector<string>& matrix, int row)
    {
        vector<int> line(matrix[row].length(), 0);
        for (int col = 0; col < matrix[row].length(); col++) {
            int cur_row = row;
            while (cur_row >= 0) {
                if (matrix[cur_row--][col] == '1') {
                    line[col]++;
                } else {
                    break;
                }
            }
        }
        return line;
    }
    int getLineMax(const vector<int>& line)
    {
        vector<int> stack_store{-1};
        int max = 0;
        for (int i = 0; i < line.size(); i++) {
            while (stack_store.back() != -1 && line[stack_store.back()] > line[i]) {
                int height = line[stack_store.back()];
                stack_store.pop_back();
                int width = i - stack_store.back() - 1;
                max = std::max(max, height * width);
            }
            stack_store.push_back(i);
        }
        while (stack_store.back() != -1) {
            int height = line[stack_store.back()];
            stack_store.pop_back();
            int width = line.size() - stack_store.back() - 1;
            max = std::max(max, height * width);
        }
        return max;
    }
};

void uinttest(vector<string> arr, int except_val)
{
    Solution s;
    int ret = s.maximalRectangle(arr);
    printf("except_val:%d,ret:%d\n", except_val, ret);
}
int main()
{
    uinttest(vector<string>{"10100", "10111", "11111", "10010"}, 6);
    return 0;
}
