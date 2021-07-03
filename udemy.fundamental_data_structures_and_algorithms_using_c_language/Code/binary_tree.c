#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    struct Node *right;
    struct Node *left;
} Node;

typedef struct BinarySearchTree {
    Node *root;
} BinarySearchTree;

void init(BinarySearchTree *bst){
    bst->root = NULL;
}

void insert(Node **root_ptr, int key){
    /* Keep in mind every node is a root of it's own sub-tree. 
       This root might not be the root of the entire tree */
    if (*root_ptr == NULL) {
        *root_ptr = (Node*)malloc(sizeof(Node));
        if (*root_ptr == NULL){
            printf("Error allocating space.\n");
            exit(1);
        }
        (*root_ptr)->key = key;
        (*root_ptr)->left = (*root_ptr)->right = NULL;
    } else if ( key < (*root_ptr)->key ) { // left
        insert(&((*root_ptr)->left),key);
    } else if ( key > (*root_ptr)->key  ) { // right
        insert(&((*root_ptr)->right),key);
    } else {
        printf("Failed, key already exists in the tree.");
    }
}

void inorder(Node *root_ptr){
    if (root_ptr != NULL){
        inorder(root_ptr->left); // inorder traversal to the leftest side
        printf("%d ",root_ptr->key); // access
        inorder(root_ptr->right); // inorder traversal to the rightest side
    }
    else {
        return;
    }
}

void preorder(Node *root_ptr){
    if (root_ptr != NULL){
        printf("%d ",root_ptr->key); // access
        preorder(root_ptr->left); // inorder traversal to the leftest side
        preorder(root_ptr->right); // inorder traversal to the rightest side
    }
    else {
        return;
    }
}

void postorder(Node *root_ptr){
    if (root_ptr != NULL){
        postorder(root_ptr->left); // inorder traversal to the leftest side
        postorder(root_ptr->right); // inorder traversal to the rightest side
        printf("%d ",root_ptr->key); // access
    }
    else {
        return;
    }
}

Node *binary_search(Node *root_ptr, int target) {
    if (root_ptr == NULL){
        return NULL; 
    } else if (root_ptr->key == target){
        return root_ptr;
        
    } else if (target < root_ptr->key) {
        return binary_search(root_ptr->left,target);
    } else if (target > root_ptr->key){
        return binary_search(root_ptr->right,target);
    }
}

void menu() {
    printf("1. Insert operation.\n");
    printf("2. In-order traversal.\n");
    printf("3. Pre-order traversal.\n");
    printf("4. Post-order traversal.\n");
    printf("5. Binary search.\n");
    printf("6. Exit.\n");
}


int main() {
    int choice, key, target, quit=0;
    Node *target_node = NULL;
    BinarySearchTree bst;
    init(&bst);
    insert(&bst.root,0);
    insert(&bst.root,10);
    insert(&bst.root,45);
    insert(&bst.root,98);
    insert(&bst.root,120);
    menu();
    while (!quit) {
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1: printf("Enter the key:");
                    scanf("%d",&key);
                    insert(&bst.root,key);
                    break;
            case 2: inorder(bst.root);
                    printf("\n");
                    break;
            case 3: preorder(bst.root);
                    printf("\n");
                    break;
            case 4: postorder(bst.root);
                    printf("\n");
                    break;
            case 5: printf("Enter the target: ");
                    scanf("%d",&target);
                    target_node = binary_search(bst.root, target);
                    target_node == NULL? 
                            printf("Not found.\n") : 
                            printf("%d found at %p\n",target_node->key,target_node);
                    break;
            case 6: exit(0);
                    break;
            default: printf("Invalid choice.\n");
                    break;
        }
    }
    return 0;
}


/* Output: 
1. Insert operation.
2. In-order traversal.
3. Pre-order traversal.
4. Post-order traversal.
5. Binary search.
6. Exit.
Enter the choice: 2
0 10 45 98 120
Enter the choice: 5
Enter the target: 23
Not found.
Enter the choice: 120
Invalid choice.
Enter the choice: 5
Enter the target: 120
120 found at 0x800062c10
Enter the choice: 6
*/
