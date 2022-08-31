/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
# include <iostream>


class Solution {
    int get_size(ListNode* l)
    {
        int size = 1;
        ListNode* p = l;
        while (p -> next != nullptr)
        {    
            ++size;
            p = p->next;
        }
        return size;
    }


public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p;
        ListNode *q;

        // traverse to get size
        int size_1 = get_size(l1);
        int size_2 = get_size(l2);
        
        if (size_1 >= size_2)
        {
            p = l1;
            q = l2;
        }
        else
        {
            p = l2;
            q = l1;
        }

        while (q != nullptr)
        {
            p->val += q->val;
            if (p->val >= 10)
            {
                p->val -= 10;
                if (p->next != nullptr)
                    ++(p->next->val);
                // if p->next == null
                else
                {
                    ListNode *node = new ListNode(1);
                    p->next = node;
                }
            }
            
            q = q->next;
            p = p->next;
        }

        while (p != nullptr)
        {
            if (p->val >= 10)
            {
                p->val -= 10;
                if (p->next != nullptr)
                    ++(p->next->val);
                // if p->next == null
                else
                {
                    ListNode *node = new ListNode(1);
                    p->next = node;
                }
            }
            p = p->next;
        }

        return size_1>=size_2 ? l1:l2;
        
    }
};
// @lc code=end

