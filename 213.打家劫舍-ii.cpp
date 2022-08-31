/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
# include <iostream>
# include <vector>
# define MAXN 110
class Solution {
public:
    int rob(std::vector<int>& nums) {
        // f[i]表示在i号房屋偷完钱后，所持有的金额
        int f[MAXN][2];
        int n = nums.size();
        
        // 芜湖
        if (n==1) return nums[0];
        if (n==2) return std::max(nums[0], nums[1]);
        if (n==3) return std::max(std::max(nums[0], nums[1]), nums[2]);

        std::vector<int> head_zero_nums = nums;
        std::vector<int> rear_zero_nums = nums;
        head_zero_nums[0] = 0;
        rear_zero_nums[n-1] = 0;

        f[0][0] = head_zero_nums[0];
        f[0][1] = rear_zero_nums[0];
        f[1][0] = head_zero_nums[1];
        f[1][1] = rear_zero_nums[1];
        f[2][0] = head_zero_nums[2] + head_zero_nums[0];
        f[2][1] = rear_zero_nums[2] + rear_zero_nums[0];

        for(int i=3; i<n; ++i)
        {
            int head_zero_num = head_zero_nums[i];
            int rear_zero_num = rear_zero_nums[i];
            f[i][0] = std::max(f[i-2][0]+head_zero_num, f[i-3][0]+head_zero_num);
            f[i][1] = std::max(f[i-2][1]+rear_zero_num, f[i-3][1]+rear_zero_num);
        }

        return std::max(std::max(f[n-1][0], f[n-1][1]), 
                        std::max(f[n-2][0], f[n-2][1]));
    }
};
// @lc code=end

