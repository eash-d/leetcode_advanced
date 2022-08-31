/*
 * @lc app=leetcode.cn id=1342 lang=cpp
 *
 * [1342] 将数字变成 0 的操作次数
 */

// @lc code=start
class Solution {
public:
    int numberOfSteps(int num) {
        if (!num)   return 0;
        int step = 0;
        while (num)
        {
            if (num%2 == 0)
            {
                num /= 2;
                ++step;
            }
            else
            {
                num -= 1;
                ++step;
            }
        }
        return step;
    }
};
// @lc code=end

