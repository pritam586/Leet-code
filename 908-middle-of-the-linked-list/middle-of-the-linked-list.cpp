/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode* temp = head;

        
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }

        int mid = size / 2;

       
        ListNode* curr = head;
        for (int i = 0; i < mid; i++) {
            curr = curr->next;
        }

        return curr; 
    }
};