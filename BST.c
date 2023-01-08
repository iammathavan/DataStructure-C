#include <stdlib.h>
#include <stdio.h>
#include "BST.h"


BST* create_node(int number){
    /** 
     * Helper function for BST_insert.
     * This function simply creates a node with the number and returns it.
     */
    BST* node = NULL;
    node = (BST *)calloc(1, sizeof(BST));
    node->data = number;
    node->left = NULL;
    node->right = NULL;
    return node;
}


BST* BST_insert(BST* root, int number){
    /** 
     * Insert the number into the BST given the root.
     */
    if (root == NULL){
        return create_node(number);
    }
    if (number <= root->data){
        root->left = BST_insert(root->left, number);
    }else{
        root->right = BST_insert(root->right, number);
    }
    return root;
}

void BST_print(BST* root, int space){
    /** 
     * Prints the BST into the console.
     * space has to be above 0.
     */
    if (root == NULL){
        return;
    }
    /* Increase distance between levels.  */
    space += LEVEL;
    BST_print(root->right, space);
    printf("\n");
    for (int i = LEVEL; i < space; i++){
        printf(" ");
    }
    printf("%d\n", root->data);
    BST_print(root->left, space);
    return;
}

BST* BST_min(BST* root){
    /** 
     * Return the node with the smallest number in the BST.
     */
    if (root != NULL && root->left != NULL){
        return BST_min(root->left);
    }
    return root;
}

BST* BST_max(BST* root){
    /** 
     * Returns the node with the biggest number in the BST.
     */
    if (root != NULL && root->right != NULL){
        return BST_max(root->right);
    }
    return root;
}


BST* BST_search(BST* root, int number){
    /** 
     * Returns the node that matches the number in the BST.
     */
    if (root == NULL){
        return NULL;
    }
    if (root->data == number){
        return root;
    }
    if (root->data > number){
        return BST_search(root->left, number);
    }
    return BST_search(root->right, number);
}

BST* BST_delete(BST* root, int number){
    /** 
     * Delete the node that matches the number from the BST.
     */
    if (root != NULL){
        if (number < root->data){
            root->left = BST_delete(root->left, number);
        }
        else if (number > root->data){
            root->right = BST_delete(root->right, number);
        }
        /* Number to be deleted is found */
        else{
            if (root->left == NULL){
                BST* temp = root->right;
                free(root);
                printf("%p\n", temp);
                return temp;
            }else if (root->right == NULL){
                BST* temp = root->left;
                free(root);
                printf("%p\n", temp);
                return temp;
            }else{
                /* Node with 2 children */
                BST* temp = BST_min(root->right);
                root->data = temp->data;
                root->right = BST_delete(root->right, temp->data);
            }
        }
    }
    return root;
}

void BST_sort(BST* root){
    /** 
     * Print the data in ascending order.
     * To make it descending order, change the lines below similar to the one 
     * commented beside it.
     */
    if (root == NULL){
        return;
    }
    BST_sort(root->left);  //BST_sort(root->right);
    printf("%d\n", root->data);
    BST_sort(root->right); //BST_sort(root->left);
    return;
}

int BST_count(BST* root, int count){
    /** 
     * Returns the number of nodes in the BST.
     * Always pass the count = 0, for the accuarate results.
     */
    if (root == NULL){
        return 0;
    }
    int left = BST_count(root->left, count+1);
    int right = BST_count(root->right, count+1);
    return 1 + left + right;
}

int BST_height(BST* root){
    /** 
     * Returns the height of the BST.
     */
    if (root == NULL){
        return 0;
    }
    int left = BST_height(root->left);
    int right = BST_height(root->right);
    if (left > right){
        return left + 1;
    }
    return right + 1;
}

BST* BST_free(BST* root){
    /** 
     * Delete the BST.
     */
    if (root != NULL){
        BST_free(root->left);
        BST_free(root->right);
        free(root);
    }
    return NULL;
}
