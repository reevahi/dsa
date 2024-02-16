/**
@author github.com/iitzmahi
Explaination is self explanatory
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* dummy = new ListNode(-101);
        ListNode *prev, *curr, *next;
        dummy->next = head;
        prev = dummy;
        curr = head;
        next = curr->next;
        while (next) {
            if (curr->val != next->val) {
                prev = curr;
                curr = next;
                next = curr->next;
            } else {
                while (next != NULL && curr->val == next->val) {
                    next = next->next;
                }
                prev->next = next;
                curr = next;
                if (curr != NULL)
                    next = curr->next;
            }
        }
        return dummy->next;
    }
};