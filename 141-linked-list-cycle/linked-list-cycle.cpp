/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        ListNode* forward = head;

        while (temp != nullptr && forward != nullptr && forward->next != nullptr) {
            temp = temp->next;               
            forward = forward->next->next;   

            if (temp == forward) {           
                return true;
            }
        }

        return false; 
    }
};
