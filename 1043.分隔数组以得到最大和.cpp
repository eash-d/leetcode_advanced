/*
 * @lc app=leetcode.cn id=1043 lang=cpp
 *
 * [1043] 分隔数组以得到最大和
 */

/* 

 -> arr = [10,9,3,2]
 -> k = 2

 -> arr = [a,b,c,d,e,f,g,h]
 -> k = 3; k = 2

 -> 草了，做这种难度大的一定要从暴力开始一步步优化
 -> 不然想了好几种莫名其妙的办法，结果都是莫名其妙

 -> 比如arr = [1,15,7,9,2,5,10]; k = 3
 -> dp = [1,30,45]
 -> 假设我当前访问到9，那先做一个事情，就是找k范围内的最大值 max(15,7,9) = 15
 -> 那接下来把15往后延到9的位置，变成  [1,15,15,15] (从dp[0]开始+)，算一下值
 -> 再把15延到7的位置                 [15,15,15,9] (从dp[1]开始+)
 
--------------------这里我思路断了 我换一种想法-----------------

 -> 那假如 arr = [1,14,2,15]; k = 3
 -> dp = [1,28,42]
 -> 假设当前访问到15，
 -> 有这么几种情况:  [1 15 15 15]  (dp[0] + ...)  
                    [14 14 15 15] (dp[1] + ...)  
                    [14 14 14 15] (dp[2] + ...)

 -> 对应的就是 i-k i-k+1 i-k+2

-------------------这里我又觉得不对劲，再微调一下思路-----------------

 -> arr = [a,b,c,d]; k = 3; now access 'd'   
 
 -> 当max(a,b,c,d) = d; 那么非常简单  假设max(a,b,c) = b
 -> 有dp = [a, 2b, 3b]，此时我要么是 a+3d, 要么是 2b+2d, 要么是 3b+d
 -> 这三个的大小是没办法比较的，所以一定要枚举找最大值，这是一种情况。

 -> 当max(a,b,c,d) = b; 也就是最大值在中间，这个就比较蛋疼了
 -> 首先有dp = [a, 2b, 3b]， 现在有几种情况，我得比较那种更好
 ->     
        1. [a, b, b, b]                 // a + k * greater(=max(b,c,d))
        2. [b, b, max(c,d), max(c,d)]   // 2b + k-1 * greater(=max(c,d))
        3. [b, b, b, d]                 // 3b + k-2 * greater(=max(d))
 
 -> 那其实这样一来我个人就感觉比较清晰了

 -> 提交其实时间不是很理想，那我最先想到的一种优化方法就是去掉algorithm这个东西
    不再用迭代器找最大值，而是每次记录最大值
 */

// @lc code=start
# include <iostream>
# include <vector>
# include <algorithm>
# define MAXN 555

class Solution {
    int ret_greater(std::vector<int>& arr, int i, int k)
    {
        /* 
         返回当前下标i对应的k范围内的最大值
         */
        auto start = arr.begin() + i - k;
        auto end = arr.begin() + i + 1;

        return *std::max_element(start, end);    
    }


public:
    int maxSumAfterPartitioning(std::vector<int>& arr, int k) {
        // arr.push_back(0);
        // 注释全部以示例1为例
        int dp[MAXN] = {0};    
        int n = arr.size();
        int r=0;
        int maxval = arr[r];
        while (r-k < 0)
        {   // 先赋值第一轮，赋值完 r = 3，即 arr[r] = 9
            if (arr[r] > maxval)
                maxval = arr[r];
            dp[r] = maxval * (r+1);
            ++r;
        }

        for (int i=r; i<n; ++i)
        {
            int greater = ret_greater(arr, i, k);
            int mul = k;
            int cnt = k-1;
            if (greater == arr[i])
            {
                for (int j=i-k; j!=i ; ++j)
                {
                    int val = dp[j] + greater*mul;
                    dp[i] = std::max(val, dp[i]);
                    --mul;
                }
            }

            else
            {
                for (int j=i-k; j!=i ; ++j)
                {
                    int greater = ret_greater(arr, i, cnt);
                    int val = dp[j] + greater*mul;
                    dp[i] = std::max(val, dp[i]);
                    --cnt;
                    --mul;
                }
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

