/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        Node* curr = head;

        while (curr != NULL) {

            if (curr->child != NULL) {

                Node* next = curr->next;
                Node* child = curr->child;

                // Put child after curr
                curr->next = child;
                child->prev = curr;

                // Find the last node of child list
                Node* temp = child;

                while (temp->next != NULL) {
                    temp = temp->next;
                }

                // Connect child list with original next
                if (next != NULL) {
                    temp->next = next;
                    next->prev = temp;
                }

                // Child pointer must be NULL
                curr->child = NULL;
            }

            curr = curr->next;
        }

        return head;
    }
};