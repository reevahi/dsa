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
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftHead, *rightHead, *left, *right, *temp;
        temp = head;
        left = right = leftHead = rightHead = NULL;
        while (temp) {
            if (temp->val < x) {
                if (leftHead == NULL) {
                    leftHead = temp;
                    left = temp;
                } else {
                    left->next = temp;
                    left = temp;
                }
            } else {
                if (rightHead == NULL) {
                    rightHead = temp;
                    right = temp;
                } else {
                    right->next = temp;
                    right = temp;
                }
            }
            temp = temp->next;
        }
        if (right != NULL)
            right->next = NULL;
        if (left == NULL)
            return rightHead;
        else {
            left->next = rightHead;
            return leftHead;
        }
    }
};