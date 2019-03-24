/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (30.45%)
 * Total Accepted:    749.4K
 * Total Submissions: 2.5M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        unsigned char carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while (l1 || l2 || carry)
        {
            unsigned char next = carry;
            if (l1)
            {
                next += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                next += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(next % 10);
            cur = cur->next;
            carry = next / 10;
        }
        ListNode *ret = head->next;
        delete head;
        return ret;
    }
};
