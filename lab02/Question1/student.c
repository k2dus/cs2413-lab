// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen
#include <stdlib.h>

bool isValid(const char *s) {
    if (s == NULL) return true;
    size_t length = strlen(s);
    char *stack = (char *)malloc(length);
    size_t top = 0;
    if (length % 2 == 1) return false;
    for (int i = 0; i < (int)length; i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack[top++] = s[i];
        }
        else {
            if (top == 0) {
                free(stack);
                return false;
            }
            char last = stack[top - 1];
            if ((s[i] == ')' && last != '(') ||
                (s[i] == ']' && last != '[') ||
                (s[i] == '}' && last != '{')) {
                free(stack);
                return false;
            }
            top--;
        }
    }

    
    free(stack);
    // TODO: Implement using a stack.
    //
    // Recommended approach:
    // - Use a char array as a stack to store opening brackets.
    // - Scan the string from left to right:
    //   - If you see an opening bracket, push it.
    //   - If you see a closing bracket:
    //       * stack must not be empty
    //       * top of stack must match the closing bracket type
    //       * then pop
    // - At the end, stack must be empty.
    //
    // Helpful matching pairs:
    //   ')' matches '('
    //   ']' matches '['
    //   '}' matches '{'
    //
    // Corner cases:
    // - s == NULL -> return false
    // - odd length strings can’t be valid 
    //
    // Note:
    // - Input contains only bracket characters, per the prompt.

    (void)s; // remove after implementing
    return true; // placeholder
}
