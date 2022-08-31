/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int arr[46] = {1, 2};
        for (int i=2; i<n; ++i)
            arr[i] = (arr[i-1] + arr[i-2]);
        return arr[n-1];
    }
};
// @lc code=end

