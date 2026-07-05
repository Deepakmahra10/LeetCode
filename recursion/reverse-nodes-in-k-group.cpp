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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* getKNode(ListNode* temp, int k) {
        k -= 1;
        while (temp && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1)
            return head;

        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp) {
            ListNode* kNode = getKNode(temp, k);
            if (kNode == NULL) {
                if (prev)
                    prev->next = temp;
                break;
            }
            ListNode* nextNode = kNode->next;
            kNode->next = NULL;
            reverseList(temp);
            if (temp == head) {
                head = kNode;
            } else {
                prev->next = kNode;
            }
            prev = temp;
            temp = nextNode;
        }

        return head;
    }
};