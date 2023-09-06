/*
 @filename   13.cpp
 @author     caonan
 @date       2022-03-22 06:52:16
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/O4NDxx/
 @brief
*/
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <map>
#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;

class NumMatrix {
public:
  // 这版复杂度o(n),不是最优解
  NumMatrix(vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
      unordered_map<int, int> row_map;
      int sum = 0;
      for (int i = 0; i < row.size(); i++) {
        sum += row[i];
        row_map[i] = sum;
      }
      store_.push_back(row_map);
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    // 如果是线上程序，都有对输出做合法性检查，此题没给出不合法返回什么
    // printf("%d,%d,%d,%d\n",row1,col1,row2,col2);
    if (store_.empty()) {
      return 0;
    }
    int sum = 0;
    for (int i = row1; i <= row2; i++) {
      auto &sub_arr = store_[i];
      // cout<<"subarr:"<<endl;
      // for(auto v:sub_arr){
      //     printf("(%d,%d) ",v.first,v.second);
      // }
      // cout<<endl;
      sum += col1 == 0 ? sub_arr[col2] : sub_arr[col2] - sub_arr[col1 - 1];
      // 这里要特殊考虑col为0的情况，减1会导致数组越界，需特殊判断
      // printf("sum+= col2:%d,col1:%d,
      // %d-%d\n",col2,col1,sub_arr[col2],sub_arr[col1]);
    }
    return sum;
  }

private:
  vector<unordered_map<int, int>> store_;
};

// 时间复杂度o(1)
class NumMatrix1 : public NumMatrix {
public:
  NumMatrix1(vector<vector<int>> &matrix) : NumMatrix(matrix) {
    if (!matrix.empty()) {
      sums_.resize(matrix.size() + 1);
      for (auto &v : sums_) {
        v.resize(matrix[0].size() + 1);
      }
    }

    for (int i = 0; i < matrix.size(); i++) {
      int sum = 0;
      for (int j = 0; j < matrix[i].size(); j++) {
        sum += matrix[i][j];
        sums_[i + 1][j + 1] = sums_[i][j + 1] + sum;
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return sums_[row2 + 1][col2 + 1] - sums_[row2 + 1][col1] -
           sums_[row1][col2 + 1] + sums_[row1][col1];
  }

private:
  vector<vector<int>> sums_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
  vector<vector<int>> matrix{{3, 0, 1, 4, 2},
                             {5, 6, 3, 2, 1},
                             {1, 2, 0, 1, 5},
                             {4, 1, 0, 1, 7},
                             {1, 0, 3, 0, 5}};
  NumMatrix s(matrix);
  vector<vector<int>> testcase{{2, 1, 4, 3}, {1, 1, 2, 2}, {1, 2, 2, 4}};
  NumMatrix1 s1(matrix);
  /*
  expect res is 8,11,12
   */
  for (const auto &v : testcase) {
    // cout<<s.sumRegion(v[0],v[1],v[2],v[3])<<endl;
    cout << s1.sumRegion(v[0], v[1], v[2], v[3]) << endl;
  }
  return 0;
}
