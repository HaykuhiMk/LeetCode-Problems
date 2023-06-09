/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newList = new ListNode();
        ListNode* tmp3 = newList;
        if (list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tmp3->val = list1->val;
                tmp3->next = new ListNode();
                tmp3 = tmp3->next;
                list1 = list1->next;
            }
            else if (list1->val >= list2->val)
            {
                tmp3->val = list2->val;
                tmp3->next = new ListNode();
                tmp3 = tmp3->next;
                list2 = list2->next;
            }
        }
        while (list1)
        {
            tmp3->val = list1->val;
            list1 = list1->next;
            if (list1)
            {
                tmp3->next = new ListNode();
                tmp3 = tmp3->next;
            }
        }
        while (list2)
        {
            tmp3->val = list2->val;
            list2 = list2->next;
            if (list2)
            {
                tmp3->next = new ListNode();
                tmp3 = tmp3->next;
            }
        }
        return newList;
    }
};
