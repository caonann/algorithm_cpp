/*
 @filename
 @author     caonan
 @date       2022-03-23 15:14:34
 @reference  转圈打印数组
 @url      https://leetcode.cn/problems/spiral-matrix/
 @brief
*/
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
// TODO: 未完成
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int height = matrix.size();
    int width = matrix[0].size();
    vector<vector<bool>> mark;
    mark.resize(height);

    for (auto& i : mark) {
      i.resize(width);
    }

    vector<int> ans;
    int n = height * width;
    int i = 0;
    int j = 0;
    while (n--) {
      while (j < width && !mark[i][j]) {
        ans.push_back(matrix[i][j]);
        mark[i][j] = true;
        j++;
      }
      --j;
      ++i;
      while (i < height && !mark[i][j]) {
        ans.push_back(matrix[i][j]);
        mark[i][j] = true;
        i++;
      }
      --i;
      --j;
      while (j >= 0 && !mark[i][j]) {
        ans.push_back(matrix[i][j]);
        mark[i][j] = true;
        j--;
      }
      ++j;
      --i;
      while (i >= 0 && !mark[i][j]) {
        ans.push_back(matrix[i][j]);
        mark[i][j] = true;
        i--;
      }
      i++;
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> arr_input = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  Solution s;
  s.spiralOrder(arr_input);
  return 0;
}
