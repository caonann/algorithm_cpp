/*
 @filename   63.replaceWords.cpp
 @author     caonan
 @date       2022-05-02 12:11:59
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/UhWRSj
 @brief  在英语中，有一个叫做 词根(root)
的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。

现在，给定一个由许多词根组成的词典和一个句子，需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。

需要输出替换之后的句子。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../stl/myTireTree.h"
using namespace std;

class GetRootTireTree : public MyTireTree
{
   public:
    string replaceRoot(const string& world)
    {
        MyTireTree* it = this;
        for (int i = 0; i < world.length(); ++i) {
            if (it->flag) return world.substr(0, i);
            if (it->tire_tree_nodes_.find(world[i]) == it->tire_tree_nodes_.end()) break;
            it = it->tire_tree_nodes_[world[i]];
        }
        return world;
    }
};

class Solution
{
   public:
    string replaceWords(vector<string>& dictionary, string sentence)
    {
        for (const auto& s : dictionary) {
            tree_node_.insert(s);
        }
        auto worlds = split(sentence);
        string ans;
        for (auto& world : worlds) {
            world = tree_node_.replaceRoot(world);
            ans += world + " ";
        }
        ans.pop_back();
        return ans;
    }

   private:
    vector<string> split(const string& s)
    {
        vector<string> ans;
        for (int start = 0; start < s.length(); start++) {
            if (s[start] != ' ') {
                int end = start;
                while (end < s.length() && s[end] != ' ') ++end;
                ans.emplace_back(s.substr(start, end - start));
                start = end;
            }
        }
        return ans;
    }
    GetRootTireTree tree_node_;
};

void uinttest(vector<string> dictionary, string sentence)
{
    Solution s;
    string ret = s.replaceWords(dictionary, sentence);
    cout << "ret is :" << ret << endl;
}

int main()
{
    uinttest(vector<string>{"cat", "bat", "rat"}, " the   cattle was  rattled by the battery");
    uinttest(vector<string>{"a", "b", "c"}, " aadsfasf absbs bbab cadsfafs");
    uinttest(vector<string>{"a", "aa", "aaa", "aaaa"}, "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa");
    return 0;
}
