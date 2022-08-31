/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
// @lc code=start
# include <vector>
# include <iostream>
# define ARR_SIZE 1010
# define COST_I 10000
class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int ans;
        int n = cost.size();
        // 数组f, 记录到i层台阶时需要花费的体力值
        int f[ARR_SIZE] = {COST_I};
        f[0] = 0;
        f[1] = 0;
        for (int i=2; i<n+1; ++i)
        {
            // 如果花费更小，那么要替换
            int cost1 = cost[i-2] + f[i-2];
            int cost2 = cost[i-1] + f[i-1];
            f[i] = (cost1 <= cost2 ? cost1 : cost2);
        }
        return f[n];
    }
};
// @lc code=end

