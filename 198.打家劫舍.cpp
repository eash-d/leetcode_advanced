/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
# include <iostream>
# include <vector>
# define MAXN 111

class Solution {
public:
    int rob(std::vector<int>& nums) {
        // f[i]表示在i号房屋时，之前偷窃到的最高金额
        //                    也即手中持有的最高金额
        int f[MAXN];
        int n = nums.size();
        f[0] = 0;
        f[1] = 0;
        f[2] = nums[0];
        // [1,2,3] 最后的结果可以从2过来，也可以从3过来，所以+2
        for (int i=3; i<n+2; ++i)
        {
            int money_1 = f[i-2] + nums[i-2];
            int money_2 = f[i-3] + nums[i-3];
            f[i] = (money_1>=money_2 ? money_1:money_2);
        }
        return f[n]>=f[n+1] ? f[n]:f[n+1]; 
    }
};
// @lc code=end

