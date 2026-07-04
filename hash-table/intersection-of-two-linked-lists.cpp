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
    int getDiff(ListNode* l1, ListNode* l2) {
        int len1 = 0;
        int len2 = 0;

        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL) {
                len1++;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                len2++;
                l2 = l2->next;
            }
        }
        return len1 - len2;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int diff = getDiff(headA, headB);
        if (diff < 0) {
            while (diff++ != 0)
                headB = headB->next;
        } else {
            while (diff-- != 0)
                headA = headA->next;
        }

        while (headA != NULL) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};