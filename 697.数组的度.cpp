/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
# include <iostream>
# include <vector>

class Solution {
    int queue[50000] = {0};
    int f = 0, r = 0;
public:
    int findShortestSubArray(std::vector<int>& nums) {
        int n = nums.size();
        int hash[50050] = {0};
        int degree = 0;
        for (int i=0; i<n; ++i)
        {
            ++hash[nums[i]];
            if (hash[nums[i]] > degree)
                degree = hash[nums[i]];
        }
        std::cout << degree << std::endl;
        return 0;

    }
};
// @lc code=end

