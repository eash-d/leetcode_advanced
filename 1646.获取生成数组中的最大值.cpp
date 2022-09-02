/*
 * @lc app=leetcode.cn id=1646 lang=cpp
 *
 * [1646] 获取生成数组中的最大值
 */

// @lc code=start
# include <iostream>
#define MAXN 111

class Solution {
    void update(int x, int& greater)
    {
        if (x > greater)
            greater = x;
    }

public:
    int getMaximumGenerated(int n) {
        if (n==0 || n==1)
            return n;
        int nums[MAXN];
        int greater = -1;
        nums[0] = 0;
        nums[1] = 1;
        for (int i=2; i<n+1; ++i)
        {
            // even
            if (i%2 == 0)
            {
                nums[i] = nums[i/2];
                update(nums[i], greater);
            }
            // odd
            else
            {
                nums[i] = nums[i/2] + nums[i/2+1];
                update(nums[i], greater);
            }
        }

        return greater;
    }
};
// @lc code=end

