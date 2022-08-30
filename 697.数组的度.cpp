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
    int cal_degree(std::vector<int>& nums)
    {
        int degree = 0;
        int n = nums.size();
        int hash_degree[50050] = {0};
        for (int i=0; i<n; ++i)
        {
            ++hash_degree[nums[i]];
            if (hash_degree[nums[i]] > degree)
                degree = hash_degree[nums[i]];
        }
        return degree;
    }

public:
    int findShortestSubArray(std::vector<int>& nums) {
        int n = nums.size();
        int hash_subarr_size[50050] = {0};
        int hash_subarr_degree[50050] = {0};
        int degree = cal_degree(nums);
        if (degree == 1)    return 1;
        int len = 0;
        int min_len = 55555;
        int sum = 0;
        for (int i=0; i<n; ++i)
        {
            int num = nums[i];

            ++len;
            ++hash_subarr_degree[num];
            // if subarray's degree == array's degree
            if (hash_subarr_degree[num] == degree)
            {
                // if shorter, update
                if ( (len - hash_subarr_size[num]) < min_len)
                {
                    min_len = len - hash_subarr_size[num];
                }
                // set zero
                hash_subarr_size[num] = 0;
            }

            // ++
            if (hash_subarr_size[num] == 0)
                hash_subarr_size[num] = len;
        }

        return min_len+1;
    }
};
// @lc code=end

