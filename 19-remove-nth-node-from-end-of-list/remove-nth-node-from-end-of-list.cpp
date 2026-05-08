/**
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

        int totalNode = 0;
        ListNode* temp = head;

        // Count total nodes
        while(temp != nullptr){
            totalNode++;
            temp = temp->next;
        }

        int nodeToDelete = totalNode - n;

        if(nodeToDelete == 0){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode* curr = head;

        
        for(int i = 0; i < nodeToDelete - 1; i++){
            curr = curr->next;
        }

        //ListNode* delNode = curr->next;

        curr->next = curr->next->next;

        return head;
    }
};