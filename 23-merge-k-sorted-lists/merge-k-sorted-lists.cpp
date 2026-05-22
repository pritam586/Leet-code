class Solution {
public:

    ListNode* convetList(vector<int>& ans) {

        if(ans.empty()) return NULL;

        ListNode* head = new ListNode(ans[0]);

        ListNode* temp = head;

        for(int i = 1; i < ans.size(); i++) {

            temp->next = new ListNode(ans[i]);

            temp = temp->next;
        }

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<int> ans;

        // Store all elements
        for(int i = 0; i < lists.size(); i++) {

            ListNode* temp = lists[i];

            while(temp != NULL) {

                ans.push_back(temp->val);

                temp = temp->next;
            }
        }

        // Sort values
        sort(ans.begin(), ans.end());

        // Convert vector to linked list
        ListNode* head = convetList(ans);

        return head;
    }
};