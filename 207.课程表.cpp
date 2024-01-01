/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include "a_header.h"
// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<int>> &g, vector<int> &indegree,
             vector<int> &visited, int i)
    {
        if (indegree[i] != 0)
        {
            return;
        }

        visited[i] = 1;
        for (auto course : g[i])
        {
            indegree[course]--;
            if (visited[course] == 0 && indegree[course] == 0)
            {
                dfs(g, indegree, visited, course);
            }
        }
    }
    bool canFinish(int numCourses,
                   vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> visited(numCourses, 0);
        for (auto &p : prerequisites)
        {
            g[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        vector<int> start;
        for (size_t i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                start.push_back(i);
            }
        }
        if (start.size() == 0)
        {
            return false;
        }
        for (auto &course : start)
        {
            dfs(g, indegree, visited, course);
        }
        int tmp = numCourses;
        for (size_t i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                tmp--;
            }
        }
        return tmp == 0 ? true : false;
    }
};
// @lc code=end
