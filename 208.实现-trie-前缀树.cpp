/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include "a_header.h"
// @lc code=start
class Trie
{
private:
    struct TrieNode
    {
        bool isWord;
        unordered_map<char, TrieNode *> children;
        TrieNode()
        {
            isWord = false;
        }
        TrieNode(bool isw)
        {
            isWord = isw;
        }
    };
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (size_t i = 0; i < word.length(); i++)
        {
            if (node->children.find(word[i]) == node->children.end())
            {
                node->children[word[i]] = new TrieNode(i == word.length() - 1);
            }
            else if (i == word.length() - 1)
            {
                node->children[word[i]]->isWord = true;
            }
            node = node->children[word[i]];
        }
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (size_t i = 0; i < word.length(); i++)
        {
            if (node->children.find(word[i]) == node->children.end())
            {
                return false;
            }
            else
            {
                node = node->children[word[i]];
            }
        }
        return node->isWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (size_t i = 0; i < prefix.length(); i++)
        {
            if (node->children.find(prefix[i]) == node->children.end())
            {
                return false;
            }
            else
            {
                node = node->children[prefix[i]];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
