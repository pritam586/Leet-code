class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempa = headA;
        ListNode *tempb = headB;

        while (tempa != nullptr) {
            ListNode *tempbIter = headB; // restart B each time
            while (tempbIter != nullptr) {
                if (tempa == tempbIter) { // check pointer equality
                    return tempa; // intersection found
                }
                tempbIter = tempbIter->next;
            }
            tempa = tempa->next;
        }
        return nullptr; // no intersection
    }
};
