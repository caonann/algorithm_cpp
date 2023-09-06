/*
 @filename   30.cpp
 @author     caonan
 @date       2022-04-08 06:51:03
 @reference    剑指offer专项
 @url      https://leetcode-cn.com/problems/FortPu/
 @brief  设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构：
insert(val)：当元素 val 不存在时返回 true ，并向集合中插入该项，否则返回 false 。
remove(val)：当元素 val 存在时返回 true ，并从集合中移除该项，否则返回 false 。
getRandom：随机返回现有集合中的一项。每个元素应该有 相同的概率 被返回。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet
{
   public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (map_key_.find(val) != map_key_.end()) {
            return false;
        }
        arr_.push_back(val);
        map_key_[val] = arr_.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (map_key_.find(val) == map_key_.end()) {
            return false;
        }

        map_key_[arr_.back()] = map_key_[val];
        std::swap(arr_[map_key_[val]], arr_.back());
        map_key_.erase(val);
        arr_.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        assert(!arr_.empty());
        // std::random_device rd;
        // std::default_random_engine e(rd());
        // std::uniform_int_distribution<int> u(0, arr_.size() - 1);
        return arr_[rand() % arr_.size()];
    }

   private:
    unordered_map<int, int> map_key_;
    vector<int> arr_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    RandomizedSet* obj = new RandomizedSet();
    assert(obj->insert(1));
    assert(obj->insert(2));
    assert(obj->insert(3));
    assert(!obj->insert(3));
    assert(obj->remove(3));
    assert(!obj->remove(3));

    int n = 10;
    while (n--) {
        int param_4 = obj->getRandom();
        cout << param_4 << endl;
    }
    return 0;
}
