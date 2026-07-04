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
    ListNode* merge(ListNode* L1, ListNode* L2){
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(L1!=NULL && L2!=NULL){
            if(L1->val <= L2->val){
                tail->next = L1;
                L1 = L1->next;
            }else{
                tail->next = L2;
                L2 = L2->next;
            }
            tail = tail->next;
        }
        if(L1 != NULL){
            tail->next = L1;
        }else{
            tail->next = L2;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;

        ListNode* first = sortList(head);
        ListNode* second  = sortList(mid);

        return merge(first, second);
    }
};