/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include "a_header.h"
// @lc code=start
class LRUCache
{
private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> cache_map;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (cache_map.find(key) != cache_map.end())
        {
            int value = cache_map[key]->second;
            cache.erase(cache_map[key]);
            cache.push_front({key, value});
            cache_map[key] = cache.begin();
            return value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        int cur_size = cache.size();
        if (update(key, value))
        {
            return;
        }
        else if (cur_size < cap)
        {
            cache.push_front({key, value});
            cache_map[key] = cache.begin();
        }
        else
        {
            cache_map.erase(cache.back().first);
            cache.pop_back();
            cache.push_front({key, value});
            cache_map[key] = cache.begin();
        }
    }

    bool update(int key, int value)
    {
        if (cache_map.find(key) != cache_map.end())
        {
            cache.erase(cache_map[key]);
            cache.push_front({key, value});
            cache_map[key] = cache.begin();
            return true;
        }
        return false;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
