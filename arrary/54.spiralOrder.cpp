/*
 @filename
 @author     caonan
 @date       2022-03-23 15:14:34
 @reference  转圈打印数组
 @url      https://leetcode.cn/problems/spiral-matrix/
 @brief
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 * @brief Given an m x n matrix, return all elements of the matrix in spiral order.
 *
 */
class Solution {
 public:
  /**
   * @brief Returns a vector containing all elements of the matrix in spiral order.
   * 使用了顺时针模拟打印的方法
   * @param matrix The input matrix.
   * @return vector<int> A vector containing all elements of the matrix in spiral order.
   */
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
      return {};
    }
    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;

    vector<int> ans;
    while (true) {
      for (int i = left; i <= right; ++i) {
        ans.emplace_back(matrix[top][i]);
      }
      if (++top > bottom) {
        break;
      }

      for (int i = top; i <= bottom; ++i) {
        ans.emplace_back(matrix[i][right]);
      }
      if (--right < left) {
        break;
      }

      for (int i = right; i >= left; --i) {
        ans.emplace_back(matrix[bottom][i]);
      }
      if (--bottom < top) {
        break;
      }

      for (int i = bottom; i >= top; --i) {
        ans.emplace_back(matrix[i][left]);
      }
      if (++left > right) {
        break;
      }
    }
    return ans;
  }
};

class Solution1 {
 public:
  /**
   * 使用去头的方法，每次逆时针旋转90度矩阵，把每一行打印后pop掉，很好理解，但时间复杂度更高
   */
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    while (!matrix.empty()) {
      ans.insert(ans.end(), matrix[0].begin(), matrix[0].end());
      matrix.erase(matrix.begin());
      left_rotate(matrix);
    }

    return ans;
  }

 private:
  void left_rotate(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
      return;
    }
    int h = matrix.size();
    int w = matrix[0].size();
    vector<vector<int>> tmp(w, vector<int>(h));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        tmp[j][i] = matrix[i][w - j - 1];
      }
    }
    matrix.swap(tmp);
  }
};

int main() {
  vector<vector<int>> arr_input = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  Solution1 s;
  auto ret = s.spiralOrder(arr_input);
  for (auto n : ret) {
    cout << n << " ";
  }
  return 0;
}
