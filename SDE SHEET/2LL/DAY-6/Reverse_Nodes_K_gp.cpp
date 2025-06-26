#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int v) {
        val = v;
        next = nullptr;
    }
};

class Solution {
public:
    // Helper function to reverse a part of the list
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* curr = head;
        while (prev != tail) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return tail;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = groupPrev;
            // Find the kth node
            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }
            if (kth == nullptr) break;

            ListNode* groupNext = kth->next;
            ListNode* newHead = reverse(groupPrev->next, kth);

            ListNode* temp = groupPrev->next;
            groupPrev->next = newHead;
            groupPrev = temp;
        }

        return dummy.next;
    }
};

// Function to print the list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    int k = 2;
    ListNode* result = sol.reverseKGroup(head, k);
    printList(result); // Output: 2 1 4 3 5

    return 0;
}
