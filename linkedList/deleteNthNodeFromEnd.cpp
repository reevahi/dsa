/**
@author github.com/iitzmahi
first we check the length of the list and then we upto the node
and delete it
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy, *prev, *curr, *next;
        dummy = new ListNode(-1);
        dummy->next = head;
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        temp = head;
        n = count - n;
        prev = dummy;
        curr = prev->next;
        next = curr->next;
        while (n--) {
            prev = curr;
            curr = next;
            next = curr->next;
        }
        prev->next = next;
        return dummy->next;
    }
};