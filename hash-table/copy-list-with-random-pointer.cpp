/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCopyNodeInBtw(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* newNode = temp->next;
            Node* copyNode = new Node(temp->val);

            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = newNode;
        }
    }

    void randomPointer(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* copyNode = temp->next;
            if (temp->random) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = NULL;
            }
            temp = temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head) {
        Node* temp = head;
        Node* dNode = new Node(-1);
        Node* res = dNode;
        while (temp) {
            res->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            res = res->next;
        }
        return dNode->next;
    }

    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        insertCopyNodeInBtw(head);
        randomPointer(head);
        return getDeepCopyList(head);
    }
};