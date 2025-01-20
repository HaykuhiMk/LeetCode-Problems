class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = list1;
        for (int i = 0; i < a - 1; ++i) {
            prev = prev->next;
        }

        ListNode* curr = prev;
        for (int i = 0; i <= b - a + 1; ++i) {
            curr = curr->next;
        }

        ListNode* tail2 = list2;
        while (tail2->next) {
            tail2 = tail2->next;
        }
        tail2->next = curr;
        prev->next = list2;
        return list1;
    }
};
