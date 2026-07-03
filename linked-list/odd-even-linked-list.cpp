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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* oddHead = new ListNode(-1);
        ListNode* oddTail = oddHead;

        ListNode* evenHead = new ListNode(-1);
        ListNode* evenTail = evenHead;

        ListNode *curr = head, *temp;
        int pos = 1;
        while (curr) {
            temp = curr;
            curr = curr->next;
            temp->next = NULL;

            if (pos%2 == 1) {
                oddTail->next = temp;
                oddTail = temp;
            } else {
                evenTail->next = temp;
                evenTail = temp;
            }
            pos++;
        }
        oddTail->next = evenHead->next;
        return oddHead->next;
    }
};