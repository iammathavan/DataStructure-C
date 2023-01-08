#ifndef BST_H
#define BST_H

/** 
 * IMPORTANT: AFTER FINISH USING THE BST, IT IS GOOD PRACTICE TO DELETE THE TREE, USE
 * THE BST_free(...) FUNCTION FOR THAT.
 */

/* Space to print the Tree in the console. */
#define LEVEL 10

/* The Structure for the Binary Search Tree. */
typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
}BST;

/* Insert the number into the BST given the root. */
BST* BST_insert(BST* root, int number);

/* Print the BST into the console, given the root and a integer variable space. */
void BST_print(BST* root, int space);

/* Returns the smallest node in BST. */
BST* BST_min(BST* root);

/* Returns the biggest node in BST. */
BST* BST_max(BST* root);

/* Returns the node that matches the number. */
BST* BST_search(BST* root, int number);

/* Delete the node in the BST that matches the number. */
BST* BST_delete(BST* root, int number);

/* Print the Sorted BST into the console. */
void BST_sort(BST* root);

/* Returns the number of nodes in the BST. */
int BST_count(BST* root, int count);

/* Returns the height of the BST. */
int BST_height(BST* root);

/* Free the memory or delete the BST completely. */
BST* BST_free(BST* root);
#endif
