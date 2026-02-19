// Question2/Student.c
// ------------------------------------------------------------
// CS Lab - Design Circular Queue (RING BUFFER / QUEUE PRACTICE)
//
// Task:
// Implement the circular queue functions declared in Student.h.
//
// You are designing a fixed-size queue with capacity k.
// The queue supports enqueue/dequeue in O(1) time using a circular array.
//
// Recommended invariants (simple + robust):
// - Use an integer `size` to track how many elements are currently stored.
// - Queue is empty  <=> size == 0
// - Queue is full   <=> size == capacity
// - `head` points to the current front element
// - `tail` points to the next insertion position
// - Wrap indices using modulo: (idx + 1) % capacity
//
// Examples (k = 3):
//   enQueue(1) -> true    queue: [1]
//   enQueue(2) -> true    queue: [1,2]
//   enQueue(3) -> true    queue: [1,2,3]
//   enQueue(4) -> false   (full)
//   Rear()     -> 3
//   isFull()   -> true
//   deQueue()  -> true    queue: [2,3]
//   enQueue(4) -> true    queue: [2,3,4]
//   Rear()     -> 4
//   Front()    -> 2
//
// Return values rules:
// - Front / Rear should return -1 if the queue is empty.
//
// How to run tests (from the folder containing the Makefile):
//   make run2
// ------------------------------------------------------------

#include "Student.h"
#include <stdlib.h>   // malloc, free
#include <stdbool.h>  // bool

MyCircularQueue* myCircularQueueCreate(int k) {
    // TODO:
    // - Allocate MyCircularQueue
    MyCircularQueue *obj = malloc(sizeof(MyCircularQueue));
    // - Allocate the internal buffer `data` of length k
    obj->data = malloc(sizeof(int) * k);
    // - Initialize capacity, head, tail, size
    obj->capacity = k;
    obj->head = 0;
    obj->tail = 0;
    obj->size = 0;

    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    // TODO:
    if (myCircularQueueIsFull(obj) == true) return false;
    // - If full, return false
    // - Write value at tail, advance tail (wrap), size++
    obj -> data[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->capacity;
    obj -> size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    // TODO:
    if (myCircularQueueIsEmpty(obj) == true) return false;
    // - If empty, return false
    // - Advance head (wrap), size--
    obj->head = (obj->head + 1) % obj->capacity;
    obj -> size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    // TODO:
    // - Return -1 if empty
    if (myCircularQueueIsEmpty(obj) == true) return -1;
    // - Otherwise return data[head]
    return obj->data[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    // TODO:
    // - Return -1 if empty
    if (myCircularQueueIsEmpty(obj) == true) return -1;
    // - Otherwise return the last inserted element
    return obj->data[(obj->tail - 1 + obj->capacity) % obj->capacity];
    //   (tail points to next insertion position)
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    // TODO:
    if ((obj->size) == 0) return true;
    // - Return true if size == 0
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    // TODO:
    if ((obj->size) == (obj->capacity)) return true;
    // - Return true if size == capacity
    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    // TODO:
    // - Free internal buffer then free obj
    free(obj->data);
    free(obj);
}
