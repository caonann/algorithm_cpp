/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   124.BinaryTreeMaximumPathSum.cpp
 @author     root
 @version
 @date       2019/09/27 01:02
 @brief
 @details    2019/09/27 root create
*/
/*************************************************************************
    > File Name: 124.BinaryTreeMaximumPathSum.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat 15 Jun 2019 05:54:14 AM UTC
 ************************************************************************/

#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
    bool isprint = false;
    int maxPathSum(TreeNode *root)
    {
        m_max = -100000;
        maxPathSumCompute(root);
        return m_max;
    }
    void maxPathSumCompute(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        int sum = maxPath(root);
        isprint = false;
        cout << "maxpath:" << sum << ":rootval:" << root->val << endl;

        if (sum > m_max)
        {
            m_max = sum;
        }

        maxPathSumCompute(root->left);
        maxPathSumCompute(root->right);
    }

    int maxPath(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        TreeNode *max_node_start = nullptr;
        int mid_max_left = -100000;

        if (root->val == 830)
        {
            isprint = true;
        }

        int left_max = maxSubArrSum(root->left, &max_node_start);

        if (root->val == 830)
        {
            cout << "left max " << left_max << endl;
        }

        // 左子树最大序列的根结点到root节点的和是否大于0

        if (max_node_start)
        {
            int root_2_find_sum = 0;
            bool ret = findMaxNodeRoot(root->left, max_node_start, root_2_find_sum);

            if (ret)
            {
                mid_max_left = left_max + root_2_find_sum;
            }
            else
            {
                cout << "error left " << endl;
            }
        }

        if (root->val == 830)
        {
            cout << "mid_max_left " << mid_max_left << endl;
        }

        max_node_start = nullptr;
        int mid_max_right = -100000;
        int right_max = maxSubArrSum(root->right, &max_node_start);

        if (root->val == 830)
        {
            cout << "right max " << right_max << endl;
        }

        if (max_node_start)
        {
            int root_2_find_sum = 0;
            bool ret = findMaxNodeRoot(root->right, max_node_start, root_2_find_sum);

            // cout<<"root_2_find_sum "<<root_2_find_sum<<endl;
            if (ret)
            {
                mid_max_right = right_max + root_2_find_sum;
            }
            else
            {
                cout << "error right " << endl;
            }
        }

        if (root->val == 830)
        {
            cout << "mid_max_right:" << mid_max_right << endl;
        }

        if ((mid_max_left <= 0 || mid_max_right <= 0))
        {
            if (mid_max_left == mid_max_right && mid_max_left == -100000)
            {
                return root->val;
            }
            else
            {
                if (mid_max_left > 0)
                {
                    return root->val + mid_max_left > left_max ? root->val + mid_max_left : left_max;
                }

                if (mid_max_right > 0)
                {
                    return root->val + mid_max_right > right_max ? root->val + mid_max_right : right_max;
                }

                int sum = left_max > right_max ? left_max : right_max;

                if (root->val > sum)
                {
                    sum = root->val;
                }

                return sum;
            }
        }
        else
        {
            int max = mid_max_left + root->val + mid_max_right;

            if (max < left_max)
            {
                max = left_max;
            }

            if (max < right_max)
            {
                max = right_max;
            }

            return max;
        }
    }
public:
    void front_traval(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        stack_node_list.push_back(node);

        if (node->left == nullptr && node->right == nullptr)
        {
            CompluteMaxSubArrSum(stack_node_list);
        }

        front_traval(node->left);
        front_traval(node->right);

        if (!stack_node_list.empty())
        {
            stack_node_list.pop_back();
        }
    }

    void CompluteMaxSubArrSum(const std::vector<TreeNode *> &stack_node_list)
    {
        if (stack_node_list.empty())
        {
            return;
        }

        // max_node_kv[]
        int sum = 0;
        int maxsum = 0;
        int index = -1;
        std::map<int, int> kv_node; // sum,index

        if (isprint)
        {
            cout << "CompluteMaxSubArrSum begin  ";

            for (auto v : stack_node_list)
            {
                cout << v->val << " ";
            }

            cout << endl;
        }

        for (int i = 0; i < stack_node_list.size(); i++)
        {
            TreeNode *node = stack_node_list[i];
            int val = node->val;

            if (val > 0 && index == -1)
            {
                sum += val;
                index = i;

                if (sum > maxsum)
                {
                    maxsum = sum;
                    kv_node[maxsum] = index;
                }
            }
            else
            {
                sum += val;

                if (sum > maxsum)
                {
                    maxsum = sum;
                    kv_node[maxsum] = index;
                }
                else if (sum < 0)
                {
                    index = -1;
                    sum = 0;
                }
            }
        }

        if (kv_node.empty())
        {
            sum = stack_node_list[0]->val;
            index = 0;

            for (int i = 0; i < stack_node_list.size(); i++)
            {
                TreeNode *node = stack_node_list[i];
                int val = node->val;

                if (val > sum)
                {
                    sum = val;
                    index = i;
                }
            }

            // cout<<"para sum "<<sum<<"index "<<index<<endl;
            kv_node[sum] = index;
        }

        std::map<int, int>::iterator it = kv_node.end();
        it--;
        int totalindex = it->second;
        int totalmax = it->first;

        if (isprint)
        {
            cout << "totalmax: " << totalmax << " index:" << totalindex << endl;
        }

        TreeNode *finalnode = stack_node_list[totalindex];
        max_node_kv[totalmax] = finalnode;
    }

    // 找到最大子路径的根节点，找到单一子树的最大和
    int maxSubArrSum(TreeNode *node, TreeNode **max_node)
    {
        front_traval(node);

        if (max_node_kv.empty())
        {
            *max_node = nullptr;
            return -1000000;
        }

        std::map<int, TreeNode *>::iterator it = max_node_kv.end();
        it--;
        int totalsum = it->first;
        *max_node = it->second;
        max_node_kv.clear();
        return totalsum;
    }

    bool findMaxNodeRoot(TreeNode *node , TreeNode *find_node, int &finalsum, int sum = 0)
    {
        if (find_node == nullptr)
        {
            return false;
        }

        if (node == nullptr)
        {
            return false;
        }

        sum += node->val;

        // cout<<"findMaxNodeRoot begin sum"<<sum<<endl;
        if (node == find_node)
        {
            finalsum = sum - node->val;
            return true;
        }
        else
        {
            return  findMaxNodeRoot(node->left, find_node, finalsum, sum) || findMaxNodeRoot(node->right, find_node, finalsum, sum);
        }
    }

private:
    std::map<int, TreeNode *> max_node_kv;
    std::vector<TreeNode *> stack_node_list;
    int m_max;
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
    {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
    {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode *stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);

    if (!input.size())
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);
    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);

        if (item != "null")
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);

        if (item != "null")
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }

    return root;
}


int main()
{
    Solution s;
    // init(init,create_treenode());
    // cout<<"tree_node_list size "<<tree_node_list.size()<<endl;
    // for(auto&v:tree_node_list)
    // {
    //  cout<<v->val<<" "<<endl;
    // }
    // s.CompluteMaxSubArrSum(tree_node_list);
    // cout<<"max:"<<s.maxPathSum(create_treenode())<<endl;
    string line =
        "[-790,-726,970,696,-266,-545,830,-866,669,-488,-122,260,116,521,-866,-480,-573,-926,88,733,null,null,483,-935,-285,-258,892,180,279,-935,675,2,596,5,50,830,-607,-212,663,25,-840,null,null,-333,754,null,817,842,-220,-269,9,-862,-78,-473,643,536,-142,773,485,262,360,702,-661,244,-96,null,519,566,-893,-599,126,-314,160,358,159,null,null,-237,-522,-327,310,-506,462,-705,868,-782,300,-945,-3,139,-193,-205,-92,795,-99,-983,-658,-114,-706,987,292,null,234,-406,-993,-863,859,875,383,-729,-748,-258,329,431,-188,-375,-696,-856,825,-154,-398,-917,-70,105,819,-264,993,207,21,-102,50,569,-824,-604,895,-564,-361,110,-965,-11,557,null,202,213,-141,759,214,207,135,329,15,null,null,244,null,334,628,509,627,-737,-33,-339,-985,349,267,-505,-527,882,-352,-357,-630,782,-215,-555,132,-835,-421,751,0,-792,-575,-615,-690,718,248,882,-606,-53,157,750,862,null,940,160,47,-347,-101,-947,739,894,null,-658,-90,-277,-925,997,862,-481,-83,708,706,686,-542,485,517,-922,978,-464,-923,710,-691,168,-607,-888,-439,499,794,-601,435,-114,-337,422,null,-855,-859,163,-224,902,null,577,null,-386,272,-971,-137,671,-410,-529,733,-956,-371,-676,-292,null,null,-606,617,431,-609,-429,-509,null,138,363,null,null,null,548,-672,324,-161,-463,-217,644,-480,535,-324,-32,-386,799,652,102,-339,294,null,null,null,948,733,null,118,388,-195,-144,424,447,-563,null,null,null,null,591,32,438,260,-826,-463,-201,-944,-195,3,617,257,-252,-865,552,304,-445,-416,886,-665,-417,527,105,-373,520,-379,844,403,300,-450,981,400,-633,858,-69,314,133,-764,-263,-624,-758,-685,-799,-860,859,-659,-616,129,-788,362,-209,559,246,-27,-193,null,null,114,872,622,34,766,null,333,677,null,-104,-429,923,-563,null,630,754,735,815,931,364,306,933,786,-156,-265,453,-738,837,-983,-357,818,9,-243,921,-411,-813,-901,677,-544,866,-816,819,379,217,null,null,-97,null,30,-765,null,null,null,null,null,null,484,-815,-416,-260,-704,-774,-369,-875,null,null,null,null,82,-546,-565,23,null,-156,null,816,168,-398,-264,null,161,-83,-422,-499,-215,-689,-887,-495,2,-281,-2,null,881,null,null,-897,-194,-852,297,-879,569,-501,982,725,850,null,161,-530,-417,-252,-147,-215,-561,-373,-356,344,-883,274,308,-261,-271,-520,-48,null,484,null,null,null,421,151,870,-979,660,-65,962,null,-338,182,655,736,-340,-122,201,-424,-473,null,401,-887,282,null,null,-290,814,-874,337,-834,675,-495,506,-739,-427,null,null,913,887,604,null,808,658,null,null,-677,758,-591,-805,361,null,163,-308,276,-946,null,981,-949,318,392,-876,-173,-739,698,-968,null,858,-666,983,-600,-701,-337,null,-884,885,-737,-843,-62,-694,null,null,null,null,null,145,354,-116,-711,-116,587,589,269,null,-422,null,224,-520,null,null,237,-779,890,-82,null,null,-524,-532,null,-685,144,-672,452,-134,930,330,null,null,295,-997,7,787,373,-236,476,880,-661,-601,null,null,-618,null,null,81,-703,-109,-643,705,-62,-30,-765,466,664,-120,46,440,122,766,-336,-542,-420,-349,111,null,null,-445,-619,-903,120,364,-139,null,-708,759,-82,232,639,-500,582,942,335,-863,null,956,944,-383,-219,257,-276,-199,231,790,113,null,43,null,-840,null,902,-445,876,956,-357,-599,51,null,841,-465,-568,712,-724,886,null,64,840,-184,-783,567,-908,954,null,16,592,-396,-666,-150,366,143,-493,null,-298,-476,495,null,-454,292,895,9,379,null,null,290,-890,-165,-722,949,-720,810,879,-343,-683,-84,343,-38,-163,101,null,506,null,null,null,null,null,null,null,150,null,-433,null,-367,907,-311,-379,-829,-845,616,-871,null,null,null,null,null,null,null,-886,null,null,-494,301,263,-795,null,976,581,-850,850,-882,159,188,76,null,null,-426,-573,529,-149,941,-999,-774,null,-987,null,null,925,null,null,407,-666,-620,430,841,null,-152,900,-67,-704,749,226,869,-580,595,-732,null,58,65,-322,-312,-133,168,104,114,-846,368,-307,-669,null,-670,-949,262,47,null,175,841,null,-241,-49,797,-300,-967,-514,90,79,-558,-933,660,null,-883,47,-532,-962,null,-630,545,274,-295,-137,null,null,-91,633,null,-248,null,27,null,null,-223,-262,979,-931,null,null,null,-261,null,915,-468,null,-565,463,236,null,788,-522,496,-542,223,473,348,-952,null,620,915,593,null,null,null,918,319,null,446,868,-636,325,-781,-667,578,-462,614,null,-260,null,116,null,562,-510,-244,-905,131,350,null,null,840,-158,536,null,34,-701,-281,56,174,-605,752,868,-71,-327,-792,-511,null,-194,267,-454,-280,836,null,973,null,513,677,null,182,93,-985,73,-279,617,null,906,-173,null,21,844,null,-383,-833,761,216,-172,null,346,304,null,-703,null,-195,928,893,-588,-1,-504,272,-335,-233,null,null,null,518,-653,817,null,797,493,718,null,null,-913,-36,null,-833,null,606,null,-914,-996,null,null,-132,null,93,null,null,null,null,null,null,438,null,null,196,null,null,-745,null,890,null,null,403,null,null,134,null,null,682,-728,null,null,-808,null,-829,-124,253,934,647,-780,460,600,631,-429,-136,994,847,null,-50,388,null,null,null,null,null,881,901,null,null,-691,347,-435,-204,-274,237,568,null,-689,-84,942,-411,725,-475,315,-688,-405,-815,-644,926,-990,-470,-354,781,517,-831,-152,-335,397,282,-289,83,-981,null,null,738,0,300,null,209,null,313,797,212,146,590,-430,804,null,null,395,590,23,null,null,null,null,-604,null,null,null,559,656,null,null,974,-561,null,4,80,-935,null,284,-353,null,null,-367,-714,null,-915,-402,null,691,48,-836,null,754,2,-99,86,-385,-662,70,172,-889,-370,null,932,273,465,196,null,813,-327,-64,349,531,983,919,-27,-196,637,-384,-594,-796,null,null,-617,null,161,654,63,565,660,233,-33,null,-637,null,null,null,null,null,757,-65,400,267,-561,null,219,-927,-143,-813,-417,-637,-22,101,-809,938,null,177,null,null,233,null,63,null,-665,53,808,-803,-397,null,-309,-446,-384,731,-85,null,-74,-133,-282,-489,-581,null,null,-950,291,-942,77,null,373,170,-849,261,null,-583,-339,707,null,58,null,null,null,null,-994,null,-519,null,-858,null,null,null,-348,-229,738,713,null,null,null,null,null,-585,null,-206,null,null,770,null,null,-292,null,886,-109,null,null,null,748,-328,-146,-329,-299,-927,-381,-77,74,441,null,null,881,-37,null,930,null,null,null,null,null,-155,-717,-595,null,442,null,-891,241,-978,-503,213,668,null,773,null,null,null,-48,-291,-587,318,954,-972,461,825,390,-618,984,-988,null,null,-91,808,664,-451,-911,-343,-421,-131,653,null,478,791,420,848,383,null,null,null,-583,444,-512,509,436,-284,500,175,540,837,null,null,null,null,-695,-337,null,50,null,null,null,null,-173,null,null,null,null,null,null,null,-826,-734,-731,612,-396,null,null,545,-631,618,-713,413,-239,-191,164,-595,null,null,-845,364,727,-689,922,909,null,null,-445,9,532,-502,null,null,-37,388,null,130,null,164,-836,null,null,-798,null,null,-610,145,-360,-683,491,-857,null,-834,null,664,-918,-369,null,-556,263,-85,674,null,null,null,782,-886,-430,-362,-630,null,-408,108,647,-985,949,-82,-182,null,-119,-72,null,-322,null,125,null,null,null,null,null,null,-656,-125,675,671,null,620,-124,297,-912,null,null,null,null,null,597,265,null,606,-262,-298,-324,null,null,null,-910,-534,null,null,-604,-584,-775,180,-840,495,null,null,537,-372,306,77,553,603,null,null,472,362,null,307,272,null,-75,760,null,null,-961,-540,536,null,-1,null,518,-869,null,null,null,885,-971,-936,-320,174,291,259,-918,null,null,null,-144,-786,962,-105,939,null,null,null,-313,789,null,-304,null,null,null,-799,null,null,null,null,292,-910,null,null,null,null,857,-128,-128,90,422,896,726,null,null,null,null,null,null,null,902,null,null,-457,-958,null,-324,-364,null,-801,78,null,null,null,473,null,null,50,-224,-314,-137,652,338,null,null,-184,969,null,null,null,null,null,-413,-147,null,null,null,null,null,338,-274,null,-265,null,-421,null,89,-344,null,null,null,null,null,null,-102,843,null,null,-60,824,-584,null,null,null,167,-776,545,147,-353,-68,188,832,-394,535,907,null,914,-165,-621,null,null,null,793,null,null,-523,-493,null,-15,20,425,-320,-63,67,null,null,-887,458,-906,null,617,null,null,null,-722,null,null,-332,191,501,713,-862,null,null,-400,-88,105,535,723,-545,null,405,null,null,-301,-832,-379,445,-990,911,-433,-438,-808,-98,631,532,null,-417,-179,302,-605,308,680,-493,-22,764,815,-443,193,-542,247,12,-104,509,-993,-110,null,569,null,null,-726,null,null,null,null,-998,258,null,914,341,-858,null,null,null,87,-586,null,null,-567,44,263,862,null,null,831,121,null,null,null,596,873,null,-689,null,-80,917,null,-299,810,null,636,-917,414,-501,801,448,null,null,977,null,268,null,-704,null,null,696,-568,-234,null,-559,446,909,-101,608,null,null,null,57,null,689,706,-524,174,856,null,null,-768,290,395,-845,null,null,null,null,-189,-526,null,-734,null,860,750,-579,251,-969,544,null,725,-18,null,-56,null,null,511,-646,431,612,null,-174,471,-903,null,995,null,758,767,907,-516,-264,-672,-94,null,null,460,-376,null,null,-301,-910,928,-281,null,null,-466,null,-74,154,null,599,null,null,346,null,-522,-458,-644,306,-505,null,-672,746,511,null,-627,null,772,null,null,-924,-805,-182,921,256,169,-970,-911,-301,null,736,null,null,null,-616,-923,-104,395,-252,583,382,179,-336,-956,-249,null,263,160,null,null,null,null,null,-442,-340,-118,888,null,-840,-597,-202,675,727,27,-530,146,null,null,null,670,619,null,null,98,987,163,null,339,null,null,208,null,null,769,-998,null,403,null,null,null,null,null,-444,null,null,null,234,-642,null,null,null,null,468,null,null,null,null,null,-972,null,null,null,null,null,null,null,360,-101,-243,null,null,748,null,415,-853,-81,-480,608,-689,816,353,572,-596,671,-108,null,null,-239,null,null,null,-67,301,311,null,-727,null,-70,null,-657,null,null,null,266,-998,-725,973,371,262,null,null,null,380,-583,null,null,-609,259,-704,-117,null,-996,-131,null,-737,111,null,777,398,637,538,656,714,null,773,null,461,392,null,null,null,-88,null,977,943,-335,-587,-702,848,391,968,null,-514,null,null,null,null,null,null,null,-174,-308,-765,null,null,null,null,395,-307,-404,null,366,null,null,null,null,139,2,679,-264,null,-355,684,380,null,-234,-453,872,749,-223,null,null,86,null,786,710,-284,-19,51,-553,null,null,null,393,477,-341,null,null,null,-157,159,-959,656,-335,323,-976,-704,-996,null,-772,34,null,null,-929,327,-532,54,439,114,717,null,null,245,null,null,null,null,1,-118,-814,null,-911,-17,246,-537,-88,298,-135,null,null,null,null,null,null,null,-707,-651,452,null,-836,991,-950,848,923,null,null,null,null,-297,-620,447,-885,null,97,null,null,null,null,null,null,null,null,635,null,null,-781,-982,-366,-100,null,412,null,-56,null,null,null,null,null,-300,-186,null,0,-926,-977,168,null,null,370,null,-612,null,null,null,-677,-453,-947,null,null,322,118,-264,205,-295,null,286,null,null,null,null,897,null,-69,null,null,null,20,-100,-62,null,null,-623,-840,-443,-163,-972,-406,null,-112,null,237,null,null,null,null,null,null,null,252,24,937,null,null,-61,null,null,189,-177,25,-542,null,null,827,null,772,-681,null,null,362,684,130,null,474,315,153,-251,null,null,-919,null,null,null,267,-276,315,-679,null,null,null,null,null,-972,98,546,37,-449,-364,null,20,-206,392,null,522,-906,388,175,-455,65,394,null,-638,680,null,null,-592,-897,-133,493,null,-9,-637,null,-571,367,-70,-811,-771,-575,-929,652,-752,531,-78,-891,329,642,null,-802,null,null,null,null,null,null,null,null,null,null,null,null,null,645,762,null,null,-148,-916,309,null,null,771,-611,null,293,null,313,null,null,807,null,null,null,null,-715,null,null,null,null,null,null,null,-593,-869,905,null,null,null,null,-969,null,612,null,null,null,-576,780,null,-45,691,-927,57,775,-570,892,855,-581,null,-558,-164,-643,-168,597,-945,154,-804,556,null,null,null,-627,null,null,null,null,null,null,null,936,960,null,null,12,22,944,650,-358,null,-163,null,null,null,null,null,null,null,null,null,null,null,-51,null,496,-760,619,-747,406,null,null,997,586,-300,-79,181,null,-763,-435,null,-929,-478,null,-114,456,653,null,-713,651,756,null,-778,-595,null,-548,-411,569,238,null,486,957,null,844,-105,-453,-784,418,725,451,334,874,-238,null,-957,789,-666,-953,-530,507,-579,-170,-586,929,496,-493,33,550,-708,-323,482,-225,null,375,null,null,710,883,null,null,-305,-774,-50,631,null,null,-825,null,-876,899,null,48,null,648,null,308,null,null,null,null,null,null,null,null,null,-166,-947,null,null,null,-971,-918,683,-976,-52,null,646,545,399,-57,null,null,316,null,-535,684,null,null,null,null,-993,483,null,null,null,null,828,null,-310,-645,536,285,562,566,-736,-651,null,null,null,null,null,null,null,null,null,43,291,-952,null,-159,757,837,-306,768,null,null,null,null,null,null,null,null,null,-33,null,null,-703,521,-606,null,-383,-108,933,-555,null,-42,-577,232,895,-340,null,null,852,426,-894,null,-238,103,276,76,null,492,null,null,-766,10,-477,null,-260,null,-543,-580,936,31,-888,-749,984,-188,613,-19,443,null,468,124,6,-688,-546,576,-719,715,-454,-26,-795,180,-742,826,null,733,null,null,null,null,635,null,-940,null,null,638,-829,null,-161,null,null,-682,null,null,122,-377,-528,-813,-223,null,null,null,158,-991,-726,13,-953,null,625,-662,771,null,129,631,-95,825,null,238,null,null,null,null,null,-214,null,-499,-278,-292,-419,null,793,null,null,795,-52,195,-376,-92,888,16,628,-809,null,-831,759,null,826,-367,-75,null,null,null,154,-599,-689,null,942,-925,765,478,328,null,-958,787,null,867,-296,null,null,null,-576,null,817,null,null,640,null,null,799,682,480,-671,-771,656,null,-603,-502,-204,null,773,881,null,931,823,369,null,469,748,null,222,-42,null,null,null,81,null,-775,-258,-743,null,-286,null,-121,-374,-872,-87,null,273,-476,null,null,null,null,null,null,null,-408,null,null,null,-411,587,799,-255,null,-898,962,-403,-108,-648,172,-889,300,-748,-791,-200,627,null,null,null,null,-784,null,-31,null,null,377,-542,146,-763,-951,152,null,-335,null,null,null,null,null,null,null,null,934,-390,-261,-548,837,952,967,null,null,-555,742,-21,null,null,null,null,null,null,-818,910,59,null,null,581,null,-111,null,-406,-956,null,745,-520,967,null,794,875,530,null,332,null,-347,563,647,-505,null,null,null,null,null,null,427,null,-527,930,300,-186,-399,-318,null,null,null,null,null,749,124,862,-104,458,null,null,null,null,null,null,null,null,-979,-572,-916,-329,null,null,-819,-992,-436,null,null,null,872,-555,null,null,null,null,null,937,null,807,571,-984,null,-825,null,null,-465,null,null,null,-904,null,463,-2,-233,729,-118,155,null,null,null,null,3,null,null,null,852,385,null,null,null,-44,-106,null,576,-264,581,null,885,544,-186,null,null,null,358,-666,-403,-516,-716,62,null,null,468,-809,-991,997,-169,null,763,null,-721,null,null,null,null,null,null,null,596,434,null,null,null,null,null,null,null,730,null,-43,923,-187,null,null,-399,266,null,null,55,190,null,-247,null,null,null,null,null,null,null,null,null,-558,243,null,906,929,null,null,-423,null,null,null,null,-102,null,-12,null,null,-689,null,460,530,null,null,null,null,331,-228,null,null,268,-373,-727,-594,null,null,-720,null,null,null,785,-471,917,null,-621,null,832,-135,null,-297,null,433,-292,null,-757,422,197,-931,null,54,null,null,null,null,63,770,-395,105,-421,null,835,-699,null,-530,-210,null,-40,-519,null,null,null,null,-350,-825,-86,null,907,-267,null,null,null,892,827,954,null,null,null,714,-216,-595,null,null,null,null,-18,null,null,null,null,null,145,-533,18,-889,-126,621,805,null,null,-26,null,null,null,null,-6,-544,-126,null,null,null,-506,null,-728,null,373,-742,-571,982,-647,794,null,85,null,120,null,null,754,741,-282,547,null,738,398,219,-425,-935,null,336,-880,-14,null,null,869,-919,null,158,null,null,266,null,null,-433,-869,null,null,null,null,null,null,null,null,361,null,708,null,null,358,-313,345,622,797,-752,null,516,null,null,632,759,-801,867,null,-650,-698,-735,-220,null,-711,-982,null,null,null,null,941,null,-158,122,-391,-2,null,658,-472,938,null,null,null,null,null,null,null,null,null,-888,null,null,483,691,null,null,-685,-712,-669,958,null,200,null,-192,-925,260,-588,-658,-733,990,null,-384,821,557,640,313,null,-154,null,null,null,null,null,null,-850,-591,null,null,318,-438,821,-868,null,394,334,-667,null,-598,null,null,null,301,-955,-570,null,null,-46,828,null,null,292,null,null,null,729,438,null,null,null,118,null,743,null,-924,null,-494,-726,-673,null,-445,null,-695,-475,646,802,null,null,null,732,86,242,789,985,38,null,null,722,null,496,268,null,null,null,null,null,null,null,null,217,null,354,825,null,null,null,836,752,null,-595,-964,-210,-504,279,-299,611,520,107,116,236,-943,179,841,-961,365,-282,-754,null,null,null,326,null,-306,372,-368,337,-728,372,null,null,594,-183,-901,null,537,null,146,null,803,null,-305,247,-619,584,-604,760,199,null,-928,null,-838,60,167,null,null,null,null,null,239,31,null,null,null,-682,52,-294,-607,null,null,-723,null,null,333,519,685,-559,null,210,-440,-599,248,null,null,null,null,null,null,-957,null,null,null,-632,null,976,null,null,-611,null,null,-237,null,null,null,-331,-22,959,null,null,null,null,null,-464,null,null,null,162,206,null,null,42,null,956,null,970,-753,null,null,null,135,179,-643,915,-344,null,null,-758,null,null,-390,null,651,-559,-667,null,-761,-180,33,-491,112,-622,818,null,-909,null,null,null,-592,-66,933,null,null,421,null,null,null,383,null,-611,null,823,711,-270,922,569,-909,333,null,-81,-316,324,-593,-947,null,null,null,224,null,838,null,null,null,null,296,412,null,null,null,436,409,null,null,-151,292,84,325,null,null,null,-772,574,null,978,692,173,-299,null,null,-558,-376,null,null,215,null,459,null,-477,-482,null,null,-320,916,null,null,null,null,null,null,898,null,null,993,-690,547,-623,225,869,527,null,222,814,-221,-237,null,-55,-951,48,null,null,null,null,-285,null,423,null,-64,968,58,676,517,null,868,null,-467,135,-39,null,null,null,-565,734,-995,369,-62,-756,null,null,null,195,189,822,994,null,209,-487,-874,-758,895,147,50,194,null,null,null,null,-897,null,88,-337,-610,866,446,null,-197,-130,-860,476,51,null,-338,-317,351,746,751,null,624,737,865,345,-200,null,null,null,null,898,null,null,null,726,-948,711,null,null,null,475,-729,null,null,899,-375,-639,null,null,-540,197,null,-948,523,null,null,-657,null,151,104,null,-283,null,null,null,260,null,-691,-715,828,null,746,null,-871,null,427,-687,null,939,-893,null,null,711,-551,null,null,-299,null,null,-630,null,null,-394,null,188,null,79,null,-673,11,814,null,-792,-34,null,null,null,-889,null,null,null,null,862,null,239,410,872,493,null,null,null,null,-261,-816,null,null,null,null,null,null,886,344,-907,901,400,-945,750,209,45,646,-194,-952,null,null,584,-945,258,696,null,-281,-98,428,679,696,-745,-690,472,901,407,423,919,null,140,-305,null,885,-666,-91,null,131,null,515,null,429,null,-169,-775,666,null,null,-751,-597,-242,846,499,null,611,611,null,-853,null,null,174,681,190,700,-373,null,411,null,null,null,-428,945,null,null,163,777,null,null,null,null,null,null,null,null,null,null,263,-293,null,null,null,null,null,null,-370,null,null,null,null,34,-407,-545,-268,-497,null,null,null,-700,439,null,-832,null,null,-75,714,-367,-864,null,879,71,852,-781,null,-748,-849,-110,-643,null,654,778,-673,null,null,null,-662,-667,317,null,806,null,null,-605,null,null,null,-380,null,742,null,null,-48,790,991,null,null,null,null,null,885,881,-168,397,null,null,-763,759,-351,-103,null,-867,null,null,null,null,-902,null,null,null,-42,45,829,-781,null,null,null,826,148,-164,null,173,null,null,null,996,-641,336,168,983,123,73,-725,-338,null,890,531,496,-838,-561,null,null,null,null,-193,264,747,-885,null,null,null,null,866,122,null,null,null,null,367,null,382,998,396,702,null,-381,null,null,21,821,null,null,null,null,null,381,null,null,-606,-38,null,null,-280,87,null,472,null,null,null,109,196,253,null,null,959,512,89,503,-902,845,null,null,null,null,null,null,null,-975,null,null,629,114,127,772,-518,682,null,null,-137,null,-519,108,759,211,70,663,86,23,null,-979,950,729,-807,629,null,null,-937,null,-109,-253,-404,null,null,343,null,null,null,null,-586,null,null,-171,null,null,-402,-558,990,768,null,null,null,551,null,-47,847,null,null,null,null,null,38,null,null,null,null,null,502,-895,null,null,-697,null,null,null,null,null,47,904,612,-499,926,-479,-744,-545,null,null,null,null,null,null,198,567,-890,null,null,null,null,null,null,null,null,null,null,null,-113,353,146,-630,719,null,778,null,null,null,null,-971,null,null,null,null,-490,-382,null,-644,null,null,null,449,null,23,null,28,-201,405,null,null,null,-807,null,-917,-604,231,null,null,null,275,null,null,null,null,525,null,null,808,-918,-354,-961,null,793,null,null,null,null,null,null,null,-757,979,null,-464,null,null,null,null,null,null,263,655,206,null,-784,509,null,957,-170,null,null,null,null,null,null,null,null,null,854,920,-968,-629,null,null,null,null,795,-147,null,null,null,null,null,null,null,null,null,null,-439,700,-245,null,null,null,-124,397,-498,null,-646,729,-954,623,-413,-800,null,517,null,-618,994,-137,904,-752,-325,-235,null,-66,null,null,602,938,-915,-154,null,-368,-8,766,-449,-105,null,-376,null,null,820,700,null,null,null,771,null,null,null,null,null,null,null,-202,null,null,null,null,null,564,null,null,null,null,null,null,null,null,null,-517,-892,520,75,-154,null,20,null,null,995,500,-447,-135,null,836,null,null,-627,249,-280,158,-239,628,-55,null,null,null,null,null,374,null,665,null,null,-781,-489,113,null,-506,152,-724,105,-482,null,null,889,null,837,889,null,633,-182,null,229,null,null,null,-69,108,null,777,185,-608,772,990,177,-92,664,968,null,-871,-817,null,-974,-974,601,-790,null,null,-519,null,-155,-859,-719,null,null,null,null,null,0,94,-607,-277,-610,-110,null,null,null,null,null,null,null,null,null,null,286,null,715,null,null,-683,null,null,-194,271,454,null,null,null,null,-262,-524,-218,null,null,null,589,null,null,null,null,null,null,null,900,-418,null,null,null,null,null,-146,null,-802,928,null,834,null,945,null,null,null,-308,null,672,901,482,48,486,null,null,null,null,-933,-122,null,null,null,458,null,-833,null,-780,-841,null,null,null,null,null,null,null,-96,null,null,null,-326,null,null,null,870,null,886,-593,462,null,-46,null,null,null,null,null,null,null,null,null,null,null,null,null,-975,null,null,null,null,-924,511,850,473,null,null,795,-677,null,null,null,-928,null,null,null,578,360,735,null,null,null,null,null,null,404,null,998,-899,null,-253,null,-139,652,703,439,null,null,null,172,null,null,null,null,null,null,null,null,null,947,651,null,-824,645,null,null,null,null,null,null,243,-753,-668,null,745,507,null,null,-394,15,993,null,985,-111,-220,-769,52,554,null,8,898,null,null,711,null,null,null,null,null,586,316,-98,202,-402,377,80,null,608,null,null,-299,177,-767,-193,353,624,null,726,null,null,-879,735,48,null,null,null,812,-482,-920,-942,null,null,null,null,null,null,null,235,null,null,null,null,-177,-685,-567,-961,433,-732,-140,720,415,-230,-355,null,400,null,-657,-871,837,-416,null,-619,752,198,null,null,-847,null,null,null,15,-800,null,null,null,null,-84,713,null,null,null,122,null,null,66,-461,191,-940,-125,-582,-632,165,null,null,null,-186,null,null,-945,null,-122,667,null,865,-190,942,-378,null,892,-945,-256,null,-905,null,null,null,223,null,null,null,null,-768,null,81,null,null,null,-275,103,837,null,-349,501,null,null,null,null,null,null,null,null,null,-501,-100,null,null,null,null,-714,null,null,522,null,null,null,null,null,48,-548,-704,null,null,-430,-55,null,null,-763,null,null,null,null,null,577,null,null,null,-834,981,null,null,31,259,835,728,854,131,75,-681,null,null,863,-827,797,885,755,null,926,null,null,null,null,700,null,null,null,-45,288,770,419,-60,-111,13,-310,null,null,null,null,null,null,34,null,-91,null,null,null,433,null,496,null,-787,858,null,null,-250,null,null,623,-761,null,-560,null,null,null,158,null,-633,null,null,160,null,840,null,-685,null,-540,-310,-279,null,517,111,-11,-923,57,null,null,null,null,null,-686,683,263,null,-56,10,921,384,-923,959,null,652,-332,-588,149,596,null,null,null,663,707,null,null,null,null,-332,-838,-992,null,null,null,null,null,null,-671,-700,null,447,-365,182,-187,-624,-694,-206,654,-214,-234,-210,754,891,null,-607,null,366,null,null,null,null,784,null,null,null,null,null,null,null,null,null,238,null,-909,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,-347,244,null,null,null,null,null,null,null,-715,null,null,null,null,-857,-680,113,688,-107,-977,null,-676,-695,-796,737,152,-581,-571,-935,928,968,null,924,null,null,null,null,981,null,null,59,null,null,null,null,null,725,-786,-288,543,null,null,null,-338,null,null,-910,-957,378,null,350,-143,null,null,-531,-981,null,null,699,null,-584,null,-552,-98,null,-887,-214,null,null,null,null,null,null,null,245,-292,null,897,557,527,-964,null,null,null,-196,null,-616,692,-778,null,207,null,null,155,null,null,null,null,-172,null,8,-585,-982,null,937,-306,-136,null,null,350,172,454,null,null,null,null,null,241,null,-975,-986,null,-114,null,null,143,null,819,null,560,-27,null,null,258,null,-501,null,319,null,null,null,null,911,null,null,null,482,null,-514,822,null,null,-533,null,null,null,null,null,null,null,null,null,null,null,null,847,136,559,null,790,null,null,null,null,null,null,249,null,-215,-614,-990,null,null,null,47,-26,-265,null,-869,null,null,121,245,-872,null,null,null,-210,null,948,null,null,-635,346,null,null,374,null,250,-909,null,-470,-997,null,null,null,null,600,null,null,null,null,null,null,null,null,-309,969,290,-774,545,null,-575,null,null,null,null,null,null,null,null,null,null,-124,null,null,null,null,-977,null,567,null,null,null,null,null,null,null,-953,-980,null,null,null,468,-481,250,null,null,null,null,null,115,null,null,null,null,null,null,504,-135,null,670,null,null,null,null,194,null,null,null,-229,null,null,null,null,null,-598,null,null,null,209,166,null,604,null,906,null,373,null,null,null,null,null,null,null,null,null,null,-250,null,null,527,null,-557,164,74,-151,null,null,null,null,null,-613,null,-536,469,null,null,-378,-86,-602,321,null,302,null,null,808,-607,null,null,779,458,null,null,null,230,null,null,-273,-95,null,null,null,null,null,-239,612,-975,-160,null,null,108,null,null,-416,732,-995,-309,223,624,-3,-63,841,872,null,null,-944,null,354,-685,null,null,289,667,614,143,186,-429,-907,null,null,-989,189,null,null,-615,null,null,743,null,-43,null,null,null,null,-112,null,-922,null,null,-960,null,null,null,-146,null,null,null,null,null,-130,null,null,-857,-824,null,null,-426,null,615,null,null,810,481,null,null,null,null,null,null,-705,null,null,428,697,null,-268,null,null,null,833,220,null,null,null,-10,-419,-872,627,null,null,null,null,842,-246,null,null,-394,143,-179,null,669,null,null,null,null,null,null,573,null,null,563,null,-772,null,null,-807,408,null,null,null,663,null,null,993,-798,816,659,null,null,-983,-524,754,113,-526,-866,null,684,null,null,677,677,577,-184,875,803,-194,null,-290,556,null,-105,-375,null,-751,-593,null,655,null,922,null,-327,-94,-903,null,null,-464,314,-817,2,null,null,251,null,null,null,-248,null,574,null,null,null,null,null,-747,null,-183,null,null,null,230,-663,null,828,274,329,249,null,null,null,-250,null,-254,-907,535,null,null,null,215,null,null,null,471,-994,224,966,null,null,-216,-779,null,null,null,null,-913,null,null,null,null,null,124,null,null,null,null,null,-406,-880,-108,-953,null,null,-171,null,null,null,null,null,-683,195,null,636,null,null,null,null,-2,-374,493,786,null,-369,962,null,588,null,null,null,null,null,null,null,null,-365,null,null,null,null,-52,890,null,null,null,-289,null,null,null,-111,null,null,null,null,null,935,-665,-799,null,123,792,-871,893,282,802,415,-571,-439,null,null,-279,-596,-56,928,68,859,33,-82,678,null,275,649,-399,-133,null,null,null,null,-566,null,-307,-43,null,null,329,null,851,662,-97,513,-615,-138,null,null,null,null,-602,282,242,530,-675,-938,null,null,null,null,null,null,43,625,959,null,null,null,351,-364,null,null,null,null,null,null,null,840,null,null,null,null,-579,-293,null,null,-982,351,null,377,-610,326,-811,null,-168,581,-845,-502,912,null,null,null,792,-688,425,null,null,-974,261,317,-127,null,502,905,null,-475,null,-520,null,null,null,null,null,null,null,262,null,null,null,-356,12,829,null,-569,-943,40,null,909,815,-153,null,925,-699,-215,null,null,null,null,842,81,null,null,345,null,null,null,null,355,null,null,null,null,null,null,null,686,22,-192,null,null,null,null,null,7,-663,null,null,null,null,null,null,null,null,null,null,null,654,null,null,226,-150,null,null,null,null,null,null,-951,null,null,null,null,null,null,null,151,-694,null,-159,null,null,-385,-880,null,null,311,null,null,137,115,null,null,null,null,-359,null,611,691,null,null,-477,null,587,null,null,null,null,null,null,824,null,-106,null,171,null,null,null,970,null,-827,-712,84,-83,-815,-70,623,null,541,-301,null,null,null,null,null,null,669,null,null,20,-215,-546,-730,-923,932,-209,540,null,-596,402,-613,null,null,513,718,-43,null,86,0,-450,-973,475,818,251,null,null,null,-705,null,426,130,-762,null,null,-814,360,110,576,366,888,null,472,236,-767,790,298,-931,14,null,364,888,null,null,414,289,-486,480,null,755,-736,-581,344,null,-276,262,null,null,null,null,-142,null,-372,null,null,-7,null,null,-795,625,null,null,337,-28,597,null,-276,-242,null,495,null,-438,150,-402,null,-550,-272,-604,null,null,null,null,null,-541,null,null,-718,null,null,null,null,null,null,null,-487,null,null,-200,null,null,-741,-767,-415,null,704,-513,-345,822,688,484,-352,-130,null,null,-375,null,317,null,-723,164,null,null,null,-246,null,null,-827,-300,null,null,null,null,null,null,null,null,54,null,null,null,316,null,null,null,null,null,-163,null,null,null,null,null,null,null,null,null,null,null,-173,980,null,-766,null,-194,null,-510,null,null,null,-174,null,148,null,null,null,null,null,null,null,null,null,null,null,null,null,-765,null,82,379,null,null,null,439,-177,767,-376,null,-61,8,362,null,678,null,735,556,null,176,86,null,-223,-452,null,-578,null,null,null,null,null,-112,681,null,776,null,null,null,null,null,null,null,null,null,-180,null,null,-140,null,null,222,null,null,null,null,null,null,null,-456,107,-828,null,301,null,null,-213,null,184,753,null,null,642,null,526,null,null,230,null,null,-901,null,null,471,457,-69,-263,null,null,null,null,-964,null,null,-493,null,-416,226,-89,-545,928,-481,-200,-870,null,null,null,null,895,null,null,null,null,null,null,null,-398,12,-29,247,null,null,null,null,null,null,738,-965,null,null,null,null,723,null,-586,-783,null,null,null,null,null,null,null,-417,null,null,null,684,null,-97,null,null,null,null,null,324,54,-610,null,402,null,null,null,null,null,237,null,null,null,-601,null,993,null,null,null,null,null,null,-858,-349,null,null,null,486,785,184,103,null,-546,269,null,null,902,null,null,-82,null,-634,null,null,185,null,-133,348,-277,-810,null,null,null,292,null,241,null,null,null,-553,-351,null,214,877,null,-102,-243,459,-167,-434,68,-758,null,null,-969,null,null,null,-85,-414,19,null,null,null,103,-992,null,-543,679,null,null,null,846,null,324,null,null,null,null,73,622,-740,374,null,-275,-38,null,null,-534,-756,-295,null,270,-618,null,null,null,834,null,null,null,null,null,null,null,88,null,null,635,null,null,null,null,null,437,null,-188,null,null,null,null,-910,null,807,650,-501,null,-577,null,null,-156,470,null,null,null,-824,null,null,293,-29,null,958,-65,-836,null,null,null,null,null,null,null,null,null,689,null,-888,null,-353,813,-842,-333,null,-605,551,null,null,-372,688,null,null,null,968,-185,null,null,null,null,null,-563,-807,-633,-257,null,null,null,-649,null,-2,null,null,416,951,-691,null,90,-765,851,-849,null,null,763,null,null,null,null,null,null,null,null,null,null,-694,null,212,-668,-965,939,null,-392,null,null,null,null,null,-695,null,null,null,null,null,null,null,null,null,null,459,null,-547,615,null,null,null,null,null,null,null,null,null,null,115,238,null,null,null,-880,537,null,null,-227,-372,null,-192,null,989,null,null,-819,null,null,null,-565,null,355,null,null,null,870,null,null,null,null,841,null,null,null,null,null,-994,498,-528,null,null,null,-527,null,null,null,null,null,null,null,null,null,null,-174,null,null,575,null,null,null,236,null,96,null,null,277,-933,395,-630,null,null,null,null,null,364,193,-88,-270,null,null,null,-161,317,765,null,509,null,142,-538,null,245,null,null,-557,140,null,null,null,844,-947,null,null,-96,-902,801,null,-905,595,-636,null,null,546,145,null,null,null,null,null,null,null,null,null,null,830,825,null,null,null,null,947,null,-819,null,283,486,null,null,null,null,null,null,null,null,null,668,null,null,null,null,181,945,null,null,226,391,null,-702,null,null,null,-595,null,null,-985,null,-499,242,-697,490,-5,null,134,null,811,null,-159,null,null,null,879,-97,565,null,null,null,null,-296,null,null,null,485,null,null,-85,null,-410,803,null,398,161,555,null,22,null,null,null,null,null,null,-144,909,148,-789,555,978,null,null,null,-670,925,null,null,594,null,-559,null,64,null,84,null,-372,-874,null,null,null,null,null,null,null,723,933,null,null,971,null,null,null,null,null,null,null,null,null,null,-951,null,null,null,-802,-979,null,566,601,null,null,-633,-719,null,226,null,null,null,null,null,null,null,null,null,509,null,463,-234,null,null,null,214,null,774,null,-971,-961,247,126,null,null,-329,-937,115,118,-990,-531,705,null,128,-325,null,255,null,null,null,null,null,-56,666,null,null,-60,null,null,null,null,-816,-969,null,-666,null,-435,null,-48,261,null,916,null,null,-36,null,null,null,462,null,-802,null,null,null,null,-671,363,null,null,null,null,-960,-583,98,726,null,null,null,null,null,null,-963,-340,null,null,348,null,null,460,null,318,-542,-367,-568,-653,-416,915,586,-249,191,null,null,null,null,null,561,538,482,160,944,-492,80,457,-831,733,600,-668,-371,-334,null,null,null,null,null,null,null,null,null,null,null,null,null,837,-103,820,736,null,219,386,-535,-69,740,85,514,-918,null,880,951,null,396,null,null,299,233,-374,117,587,-936,372,-463,892,null,null,null,null,null,null,224,null,60,55,492,741,275,null,null,-463,null,null,null,658,642,476,-953,null,651,-435,null,null,null,null,null,null,-4,null,null,null,-434,911,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,68,301,null,null,-38,null,null,404,null,null,617,979,null,null,63,-806,639,null,-233,null,-856,-106,null,null,-223,null,-76,84,null,null,null,null,-465,221,728,-48,-517,267,null,null,327,null,null,null,null,null,-599,null,null,null,null,null,null,null,null,null,null,460,null,null,null,-742,null,null,null,null,null,null,null,null,-646,-245,-171,271,null,null,-734,null,null,null,null,null,751,null,-848,-910,-447,null,-590,null,null,null,213,-857,320,-173,227,null,null,null,null,null,null,null,null,null,null,null,901,743,446,null,null,null,null,null,null,null,null,null,328,null,-917,null,null,null,282,null,null,null,null,null,null,628,null,-691,null,null,null,null,829,-933,null,-808,null,null,null,null,null,null,null,613,null,null,-271,-902,227,null,null,null,null,null,null,-564,-338,null,null,null,null,-405,null,null,967,-866,-550,null,null,null,null,null,null,null,null,null,null,-52,null,550,null,null,-398,732,-420,null,-761,966,379,null,438,-672,null,588,null,null,null,851,null,637,675,null,null,-986,null,null,null,null,null,null,null,null,-628,65,null,null,82,982,null,null,45,null,null,null,null,null,null,null,null,null,-78,null,null,null,null,null,null,null,null,null,845,null,null,null,-555,null,null,-438,null,null,-418,null,null,null,null,null,null,null,null,null,null,-103,-928,null,null,-951,null,-459,null,null,676,null,480,null,null,null,null,null,-791,262,-137,null,null,null,null,null,null,414,464,null,-420,null,null,null,null,null,null,null,null,null,null,null,null,null,256,27,-953,-638,872,-420,null,null,null,null,465,127,-29,null,344,null,-545,175,-539,62,null,null,null,573,null,null,-16,-444,335,null,null,null,null,null,-233,null,null,null,null,null,null,null,null,null,null,null,-303,-47,815,null,59,null,null,null,-479,652,-619,null,null,null,null,49,559,null,null,-705,null,null,750,null,-695,684,-659,-317,-358,null,null,-483,null,null,null,null,null,-210,null,null,null,-982,null,null,null,-540,null,null,-14,176,null,null,541,706,null,null,null,null,null,null,191,39,null,372,null,824,null,null,-856,-279,null,-310,null,-496,null,null,-194,null,-27,242,null,null,null,-486,null,null,416,null,414,-333,-219,null,-356,null,null,null,null,null,null,null,null,null,null,null,920,-352,null,null,null,null,null,null,null,-742,null,574,null,null,null,-428,null,null,-990,null,null,null,null,null,null,-178,47,-353,null,null,null,null,null,null,null,null,null,205,null,null,-795,-721,null,null,-463,-182,-100,-763,null,null,null,null,null,null,88,-225,null,-232,null,null,null,null,776,null,337,-572,null,-142,null,989,112,null,null,731,-51,569,null,231,null,null,-712,null,null,null,null,-37,210,null,null,null,-88,null,null,-567,null,-334,null,null,null,null,null,null,542,397,null,null,null,null,null,null,280,null,null,null,null,null,87,745,324,-549,-807,232,979,null,578,null,118,null,-109,null,-787,159,758,-45,-110,-43,null,null,404,null,-723,-23,546,null,null,268,-33,null,null,null,-183,null,null,474,null,null,null,null,null,258,null,null,null,null,-101,67,null,null,null,101,null,-532,null,null,642,589,-240,389,null,null,-684,null,-499,-943,-433,673,205,713,null,165,-679,null,null,null,null,null,-69,-761,null,-427,224,-298,null,-9,191,400,222,null,376,847,269,-604,null,571,696,417,null,null,null,-833,809,null,-564,null,68,433,747,235,296,-869,null,null,null,-283,null,96,null,-859,null,null,null,-269,null,null,82,287,221,564,49,-840,302,null,641,-953,628,905,631,882,294,625,null,null,359,null,null,null,-92,-582,387,null,990,-725,null,-541,null,null,null,null,null,null,-661,844,179,965,-622,-70,null,-83,186,null,-742,-1,null,null,-198,80,null,null,null,null,null,265,-349,-683,null,null,920,null,null,-758,null,null,null,null,-69,630,null,-539,223,-872,556,null,null,683,null,-181,300,null,null,747,-166,679,-50,736,-953,-632,null,949,null,406,-426,696,null,-28,-676,null,252,-362,479,-627,-562,-826,null,-862,null,-38,7,919,-20,null,-397,null,null,null,null,null,null,null,null,null,null,678,null,null,-18,null,null,-587,null,null,null,null,null,-420,null,null,-619,null,null,-819,-181,null,null,null,518,null,null,null,655,-924,959,410,null,-274,null,null,null,null,null,null,null,null,-779,null,null,null,null,-297,null,null,-428,null,439,null,-698,null,null,-528,null,258,null,null,null,null,null,-79,null,null,-630,null,null,null,null,-481,null,null,null,null,null,null,-139,493,908,555,null,null,null,-980,-757,-568,null,null,null,null,280,-492,null,null,null,null,null,-448,null,null,null,null,null,-533,null,76,null,null,null,null,null,null,null,-494,null,null,null,null,null,null,null,904,8,526,-405,null,358,912,null,121,-59,143,null,-525,null,null,null,null,null,-311,-220,null,null,-224,null,-622,null,-968,192,null,null,null,null,-718,-162,null,null,null,null,-40,null,null,-893,null,null,-734,null,null,null,null,-976,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,-784,-523,null,null,null,null,788,42,null,741,305,null,180,null,739,null,-99,426,null,null,591,null,null,-917,null,null,null,-23,-110,950,null,null,-590,null,null,-576,null,374,null,-401,null,null,null,null,620,710,null,null,null,674,851,null,null,-977,null,null,null,-900,933,-561,-896,null,728,310,-175,454,null,null,null,null,null,null,null,-49,null,-978,765,-390,null,-127,null,null,null,null,null,null,null,null,879,975,null,null,null,null,null,null,null,null,-990,-591,null,-938,null,null,null,null,null,null,-24,null,439,-855,null,null,244,null,-809,19,null,null,null,null,null,null,null,-366,null,null,null,null,-655,null,null,null,-19,null,-452,null,null,null,null,309,null,null,null,190,-430,484,129,null,666,-854,897,null,492,223,-409,null,null,-344,null,null,null,null,null,null,576,-117,769,-913,509,null,null,331,null,null,null,-4,null,null,null,-251,null,-594,null,null,null,null,null,null,null,null,null,914,null,-787,-837,null,730,null,null,null,-68,null,431,-70,null,-804,null,null,null,null,null,null,null,null,null,249,411,626,null,null,null,null,-385,3,null,937,null,470,-885,null,null,-721,-591,-881,786,891,543,null,574,70,null,-728,-735,-693,null,370,-360,-316,-817,-233,-865,0,-771,-242,null,null,null,null,null,null,-157,null,null,null,null,420,-103,-932,766,13,null,null,null,-738,null,-786,-154,712,-782,null,null,null,null,null,null,null,null,null,null,null,null,727,-705,-715,-997,-831,-458,null,null,null,null,null,416,-142,null,652,null,null,897,821,474,577,309,-489,-889,-436,-483,695,-804,null,null,-965,null,-488,null,276,72,null,null,-365,null,null,822,-756,null,null,null,null,null,-963,73,879,953,872,-82,923,860,null,-876,null,null,null,null,-14,null,null,-688,-870,null,863,null,-432,641,null,null,315,null,null,656,null,null,null,null,-835,null,null,null,613,null,null,-107,-233,null,null,955,null,null,-784,-410,null,-833,3,null,null,null,676,null,null,null,null,null,41,null,null,null,null,null,null,null,null,null,841,null,15,116,-633,null,-834,null,null,null,null,965,null,null,null,null,null,127,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,994,null,null,-613,null,null,null,null,-506,911,null,-306,null,null,null,null,null,null,-737,null,null,null,null,null,null,null,null,null,null,null,null,null,null,-510,null,null,-514,null,659,-875,null,null,null,null,983,null,null,-275,735,-350,null,null,null,518,null,null,null,null,null,null,null,-379,null,null,null,-796,null,null,null,null,-465,null,null,null,null,null,null,335,null,null,193,null,565,357,null,null,null,113,null,null,-918,null,null,null,null,-809,null,null,-850,null,-379,null,null,616,null,null,null,null,null,null,null,null,null,null,null,null,null,null,-84,-686,-485,null,null,null,-722,-591,-798,-453,null,-416,null,null,null,null,872,-957,null,null,null,null,null,null,null,null,434,null,null,null,null,-918,null,675,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,982,null,null,null,null,null,null,null,-260,null,null,null,null,null,null,null,null,879,null,null,null,null,null,null,546,null,null,-676,-5,993,null,null,null,null,null,null,null,null,-951,531,968,null,null,387,null,null,-889,null,null,-275,null,null,-915,-779,-706,null,-730,null,null,null,null,869,null,473,58,null,null,null,-621,null,null,682,631,682,null,null,null,null,null,968,169,null,null,null,null,null,null,null,null,-358,null,null,null,null,null,null,null,-78,null,null,null,null,null,null,null,null,-949,-190,null,-385,null,-409,644,null,null,null,-101,194,null,840,null,-862,436,739,258,null,-465,-265,361,749,600,543,null,null,null,null,null,-278,-934,-413,925,null,670,-374,-575,193,null,null,382,-240,null,-398,null,691,458,-31,null,-367,null,null,-198,-924,null,113,null,-662,null,null,null,-222,null,122,422,-385,-120,899,503,105,null,null,null,null,-579,null,null,-780,557,null,-327,-701,-810,null,null,null,-787,-982,null,869,null,null,-541,-84,-414,574,-331,-78,109,null,445,null,-877,null,null,575,null,-447,528,-900,null,null,35,508,null,null,618,null,null,null,null,null,null,-347,null,null,748,200,401,143,null,-143,-694,213,null,953,null,null,null,null,null,-160,null,410,-41,911,null,-742,null,null,null,279,null,null,null,null,null,null,null,null,-67,588,null,null,746,null,null,null,null,null,null,null,540,null,-569,null,null,null,null,-366,null,null,null,null,22,null,-727,-473,null,null,null,-933,null,-542,-77,null,null,null,-225,null,null,-863,null,null,null,null,null,null,null,215,null,null,739,-396,null,null,null,null,-42,-937,null,-104,null,-752,null,null,null,-580,null,255,null,null,null,null,null,null,null,null,191,null,null,null,null,null,-282,null,null,null,null,784,-606,null,null,null,231,null,null,null,null,null,858,null,880,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,211,null,-313,null,null,null,-264,null,null,null,null,null,null,null,null,665,866,null,null,null,null,null,389,70,null,null,null,null,-865,-404,-747,null,null,null,null,null,null,null,null,null,null,null,null,null,null,822,null,-141,null,null,null,null,-579,44,null,null,168,null,-735,null,849,513,-33,null,null,984,null,null,null,-790,null,null,null,null,null,null,null,null,236,null,-3,null,58,null,null,-824,null,-165,862,-822,44,null,512,null,887,707,374,375,null,null,null,null,null,null,-931,null,-957,-174,-204,-98,902,340,null,null,-220,null,null,null,883,638,null,null,null,null,null,null,null,null,null,null,null,-91,null,null,null,null,44,null,null,null,null,null,448,null,358,null,null,null,null,null,null,-695,null,205,-557,-279,null,null,-710,null,null,220,620,-471,977,null,-968,906,503,null,null,null,227,591,144,null,-70,null,null,926,null,null,null,null,null,null,null,null,null,null,null,null,-677,null,-678,162,-636,485,316,-883,null,null,null,263,null,-589,null,null,null,null,null,null,-22,null,-644,121,-42,null,null,null,null,null,null,null,896,null,null,null,null,null,null,840,null,null,792,null,null,null,-389,null,-305,853,null,null,null,null,null,199,null,946,654,null,908,null,null,-827,27,null,null,null,null,null,null,null,null,null,null,null,-508,null,null,null,null,null,null,null,null,754,null,null,null,null,40,null,null,-38,null,634,-347,null,null,-260,null,null,null,90,null,-701,null,-295,null,-176,null,null,null,-568,-38,null,null,-838,null,null,659,null,-136,-793,null,null,null,null,-981,-356,-986,null,null,-947,381,null,null,-580,null,null,null,null,null,null,null,540,null,394,-289,null,null,-502,null,null,null,null,-231,-648,-282,null,null,null,297,913,777,-999,null,null,461,null,null,-901,-169,null,-942,null,null,null,null,null,null,null,null,null,-350,null,null,956,null,-720,null,null,292,-879,null,null,134,158,null,-144,568,null,null,null,null,null,null,-741,962,null,-872,-215,null,null,null,null,null,null,null,null,-185,228,null,241,214,null,null,985,822,947,null,828,587,null,-838,null,null,349,null,767,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,55,null,864,null,null,-279,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,-823,266,-413,-392,null,-17,null,null,null,-414,null,-897,590,null,-757,null,764,null,null,-290,-931,null,null,10,null,null,-762,null,null,null,498,497,null,null,null,null,null,null,20,547,376,null,null,null,415,-406,null,null,null,-728,387,null,-153,-83,null,-105,-347,null,null,null,null,null,null,296,-632,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,451,null,null,null,null,983,null,-646,-941,-359,null,-13,null,null,214,-282,884,223,null,null,null,null,null,-91,null,null,-50,null,null,null,null,null,84,null,null,null,null,null,null,null,null,535,null,null,null,null,null,null,null,null,null,-390,-469,null,null,956,null,null,310,-146,null,149,null,-145,null,372,null,766,-208,null,null,-909,null,null,190,null,588,792,null,null,null,null,940,null,null,null,-818,840,null,-511,null,-669,-8,null,null,null,null,637,961,292,null,null,null,null,null,-689,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,650,-331,null,null,null,-258,null,-438,null,null,null,null,null,null,null,null,null,null,-240,438,null,null,666,null,null,null,null,null,-704,null,null,null,null,305,-510,-136,null,null,null,null,null,null,null,null,null,178,null,null,null,null,null,-589,null,960,null,192,null,908,null,null,null,null,-124]";
    TreeNode *root = stringToTreeNode(line);
    /*
    cout<<"max:"<<s.maxPathSum(create_treenode1())<<endl;
    cout<<"max:"<<s.maxPathSum(create_treenode2())<<endl;
    cout<<"max:"<<s.maxPathSum(create_treenode3())<<endl;
    cout<<"max:"<<s.maxPathSum(create_treenode4())<<endl;
    cout<<"max:"<<s.maxPathSum(create_treenode5())<<endl;
    cout<<"max:"<<s.maxPathSum(create_treenode6())<<endl;
    cout<<"max:"<<s.maxPathSum(create_treenode7())<<endl;
    cout<<"max:"<<s.maxPathSum(create_treenode8())<<endl;
    */
    cout << "max:" << s.maxPathSum(root) << endl;
    return 0;
}

