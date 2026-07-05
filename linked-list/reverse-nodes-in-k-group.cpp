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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        while(temp && cnt<k){
            temp = temp->next;
            cnt++;
        }
        if(cnt<k) return head;

        temp = head;
        ListNode* prev = NULL;
        ListNode* newNode = NULL;
        cnt = 0;
        while(temp && cnt<k){
            newNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = newNode;

            cnt++;
        }
        head->next = reverseKGroup(temp, k);

        return prev;
    }
};