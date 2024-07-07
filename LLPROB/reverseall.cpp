#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    // Print reversed list
    ListNode* current = reversedHead;
    while (current != NULL) {
        std::cout << current->val << " ";
        current = current->next;
    }

    // Free allocated memory
    current = reversedHead;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
