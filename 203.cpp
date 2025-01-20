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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        ListNode* new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};
