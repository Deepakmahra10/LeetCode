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
        vector<ListNode*> nodes;
        ListNode* temp = head;
        while (temp) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        // reverse complete grp of nodes
        int n = nodes.size();
        for (int i = 0; i + k <= n; i += k) {
            reverse(nodes.begin() + i, nodes.begin() + i + k);
        }

        // Reconnect Nodes
        for (int i = 0; i < n; i++) {
            nodes[i]->next = nodes[i + 1];
        }
        nodes[n - 1]->next = NULL;

        return nodes[0];
    }
};