/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkAVL(struct TreeNode* node, long long min, long long max) {
    if (node == NULL) return 0;
    if (node->val <= min || node->val >= max) return -1;
    int leftH  = checkAVL(node->left,  min,       node->val);
    int rightH = checkAVL(node->right, node->val, max);

    if (leftH == -1 || rightH == -1) return -1;
    if (abs(leftH - rightH) >= 1) return -1;
    int result;
    if(leftH>rightH) return 1+leftH;
    else return 1+rightH;
}

bool isAVL(struct TreeNode* root) {
    return checkAVL(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1) != -1;
}