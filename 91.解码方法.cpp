/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

/* 

-> val = s[i-1] * 10 + s[i] > 26
    ex: s = "12", val = 1*10 + 2 = int(12)

-> if (s[i] == 0) combine with front, to be one num;
-> if (s[i-1] * 10 + s[i] > 26) return 0;
    ex: "130": [1,30] x 
               [13,0] x
-> if (s[i]==0 and s[i-1]==0) return 0;
    ex: "100": [10,0] x

*/

// @lc code=start
# include <iostream>
# include <string>
# define MAXN 110
class Solution {
public:
    int numDecodings(std::string s) {
        // 存储方法数
        int method_nums[MAXN] = {0};
        int n = s.size();
        
        // i=0
        if (s[0] != '0')  
            method_nums[0] = 1;
        // i=1
        int val = (s[0] - 48) * 10 + (s[1] - 48);
        if (s[1] == '0')
        {
            if (val > 26)
                return 0;

            if (s[0] != '0')
                method_nums[1] = method_nums[0];
            else 
                return 0;
        }
        else
        {
            if (s[0] == '0') 
                return 0;

            if (val > 0 && val < 27)
                method_nums[1] = 2;
            else
                method_nums[1] = 1;
        }


        for (int i=2; i<n; ++i)
        {
            int val = (s[i-1] - 48) * 10 + (s[i] - 48);
            if (s[i] == '0')
            {
                if (val > 26)
                    return 0;

                if (s[i-1] != '0')
                    method_nums[i] = method_nums[i-2];
                else 
                    return 0;
            }

            else
            {
                if (s[i-1] == '0')
                {
                    method_nums[i] = method_nums[i-1];
                }

                else
                {
                    if (val > 0 && val < 27)
                        method_nums[i] = method_nums[i-1] + method_nums[i-2];
                    else
                        method_nums[i] = method_nums[i-1];
                }
            }
        }
        return method_nums[n-1];
    }
};
// @lc code=end

