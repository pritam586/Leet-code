class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> st;

        ListNode* temp = head;

        // Step 1: Push all values into stack
        while(temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Step 2: Replace values using stack
        temp = head;

        while(!st.empty()) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
};