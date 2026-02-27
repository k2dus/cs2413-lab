// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"

bool hasCycle(struct ListNode *head) {
    // TODO: implement
    //     Description: Determine whether a linked list contains a cycle.

    // Requirements: - Do NOT modify the linked list.  - Time complexity: O(n) -
    // Space complexity: O(1)
    // Hints: Use two pointers: - slow moves one step at a time - fast
    // moves two steps at a time

    // If they ever meet, a cycle exists.
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}