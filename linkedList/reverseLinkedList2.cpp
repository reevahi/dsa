/**
@author github.com/iitzmahi
Here we maintain 3 pointers, and one dummy node
to reverse the next pointers
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-501);
        dummy->next = head;
        head = dummy;
        ListNode *temp, *prev, *curr, *next;
        temp = head;
        for (int i = 0; i < left - 1; i++) {
            temp = temp->next;
        }
        prev = NULL;
        curr = temp->next;
        next = curr->next;
        int n = right - left + 1;
        while (n != 0) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (curr != NULL)
                next = curr->next;
            n--;
        }
        if (temp->next != NULL)
            temp->next->next = curr;
        temp->next = prev;
        return dummy->next;
    }
};