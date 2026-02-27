// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    if (head != NULL && head->next != NULL) head = head->next;

    while (curr != NULL && curr->next != NULL) {
        struct ListNode* first = curr;
        struct ListNode* second = curr->next;
        struct ListNode* nextPair = second->next;

        second->next = first;
        first->next = nextPair;

        if (prev != NULL) prev->next = second;

        prev = first;
        curr = nextPair;
    }
    return head;
}