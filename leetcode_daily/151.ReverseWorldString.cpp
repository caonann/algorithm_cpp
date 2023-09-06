/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   151.ReverseWorldString.cpp
 @author     root
 @version
 @date       2019/09/27 01:02
 @brief
 @details    2019/09/27 root create
*/

#include "common_define.h"
class Solution
{
public:
    // runtime o(n) memory o(n)
    string reverseWords(string s)
    {
        int len = s.size();
        bool isSplit = false;
        std::vector<std::string> total_string;
        std::string tmp_str;

        for (int i = 0; i < len; i++)
        {
            if (s[i] == ' ')
            {
                isSplit = false;

                if (!tmp_str.empty())
                {
                    total_string.push_back(tmp_str);
                    tmp_str.clear();
                }

                continue;
            }
            else
            {
                isSplit = true;
                tmp_str += s[i];
            }
        }

        if (!tmp_str.empty())
        {
            total_string.push_back(tmp_str);
            tmp_str.clear();
        }

        std::reverse(total_string.begin(), total_string.end());
        string ret_str;

        for (int i = 0; i < total_string.size(); i++)
        {
            if (i == total_string.size() - 1)
            {
                ret_str += total_string[i];
            }
            else
            {
                ret_str += total_string[i] + " ";
            }
        }

        return ret_str;
    }

    string reverseWords1(string s)
    {
        auto local_resvere =[](string & s, int begin, int end)->void
        {
            while (begin < end)
            {
                int tmp = s[begin];
                s[begin] = s[end];
                s[end] = tmp;
                begin++;
                end--;
            }
        };
        int i = 0;
        int j = 0;
        int len = s.length();
        int word = 0;

        while (true)
        {
            // trim left space
            while (i < len && s[i] == ' ')
            {
                i++;
            }

            if (i == len)
            {
                break;
            }

            if (word)
            {
                s[j++] = ' ';
            }

            int start = j;

            while (i < len && s[i] != ' ')
            {
                s[j++] = s[i++];
            }

            local_resvere(s, start, j - 1);
            word++;
        }

        s.resize(j);
        std::reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.reverseWords1(" ") << endl;
    cout << s.reverseWords1("hello world hulk") << endl;
    cout << s.reverseWords1("  hello world hulk  ") << endl;
    cout << s.reverseWords1("  hello   world hulk ") << endl;
    return 0;
}