/**
@author github.com/iitzmahi
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return head;
        ListNode *dummy, *curr, *next;
        dummy = new ListNode();
        dummy->next = head;
        int length = 0;
        curr = head;
        next = head;
        while (curr) {
            if (next->next != NULL)
                next = next->next;
            length++;
            curr = curr->next;
        }
        k = k % length;
        k = length - k;
        curr = dummy;
        while (k--) {
            curr = curr->next;
        }
        next->next = dummy->next;
        dummy->next = curr->next;
        curr->next = NULL;
        return dummy->next;
    }
};