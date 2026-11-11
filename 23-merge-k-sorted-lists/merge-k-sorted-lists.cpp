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

    ListNode* merge(ListNode* head1, ListNode* head2) {

        ListNode* head = new ListNode(0);
        ListNode* tail = head;

        while (head1 != NULL && head2 != NULL) {

            if (head1->val <= head2->val) {
                tail->next = head1;
                head1 = head1->next;
            }
            else {
                tail->next = head2;
                head2 = head2->next;
            }

            tail = tail->next;
        }

        if (head1 != NULL)
            tail->next = head1;
        else
            tail->next = head2;

        return head->next;
    }

    void mergesort(vector<ListNode*>& arr, int start, int end) {

        if (start >= end)
            return;

        int mid = start + (end - start) / 2;

        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);

        arr[start] = merge(arr[start], arr[mid + 1]);
    }

      ListNode* mergeKLists(vector<ListNode*>& lists) {

        int K = lists.size();

        if (K == 0)
            return NULL;

        mergesort(lists, 0, K - 1);

        return lists[0];
    }
};
