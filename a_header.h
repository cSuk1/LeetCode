#ifndef __A_HEADER_H__
#define __A_HEADER_H__

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif // __A_HEADER_H__