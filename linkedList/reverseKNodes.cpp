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
    void reverse(ListNode* head) {
        ListNode *prev, *curr, *next;
        prev = NULL;
        curr = head;
        next = head->next;
        while (curr != NULL) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (curr != NULL)
                next = curr->next;
        }
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        ListNode *curr, *prev, *temp, *next;
        dummy->next = head;
        prev = dummy;
        curr = head;
        temp = head;
        next = dummy;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        temp = head;
        count = count / k;
        while (count--) {
            for (int i = 1; i < k; i++) {
                curr = curr->next;
            }
            next = curr->next;
            curr->next = NULL;
            reverse(temp);
            prev->next = curr;
            prev = temp;
            curr = next;
            temp = next;
        }
        prev->next = next;
        return dummy->next;
    }
};