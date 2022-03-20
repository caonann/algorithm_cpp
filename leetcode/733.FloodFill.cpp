/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   733.FloodFill.cpp
 @author     root
 @version
 @date       2019/09/27 01:02
 @brief
 @details    2019/09/27 root create
*/
/*************************************************************************
    > File Name: 733.FloodFill.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat Sep 14 00:14:07 2019
 ************************************************************************/

#include "common_define.h"

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] != newColor)
        {
            dfs(image, sr, sc, image[sr][sc], newColor);
        }

        return image;
    }
private:
    void dfs(vector<vector<int>> &image, int sr, int sc, int oldColor, int newColor)
    {
        std::string key = std::to_string(sr) + std::to_string(sc);

        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[sr].size() || image[sr][sc] != oldColor ||
            pos_map_.find(key) != pos_map_.end())
        {
            return;
        }

        pos_map_.insert(key);
        image[sr][sc] = newColor;
        dfs(image, sr - 1, sc, oldColor, newColor);
        dfs(image, sr + 1, sc, oldColor, newColor);
        dfs(image, sr, sc - 1, oldColor, newColor);
        dfs(image, sr, sc + 1, oldColor, newColor);
    }

    unordered_set<std::string> pos_map_;
};

int main()
{
    Solution s;
    vector<vector<int>> image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    s.floodFill(image, 1, 1, 2);

    for (auto v : image)
    {
        for (auto t : v)
        {
            cout << t << " ";
        }

        cout << endl;
    }

    return 0;
}

