
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newHead = nullptr;
        ListNode* temp = nullptr;

        if (l1->value > l2->value) swap(l1, l2);

        newHead = l1;

        while (l1 && l2) {
            temp = l1;

            while(l1 && l1->value <= l2->val) {
                temp = l1;
                l1 = l1->next;
            }

            temp->next = l2;
            swap(l1, l2);
        }

        return newHead;
    }
};

