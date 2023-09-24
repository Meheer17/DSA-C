#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    int val;
    struct Node *left, *right;
};

struct Node *create(int num)
{
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));    
    if(new_node == NULL)
    {
        printf("\nMemory can't be allocated for new node\n");
        free(new_node);
        return NULL;
    }
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->val = num;
    return new_node;
}

struct Node *root = NULL;
struct Node *current = NULL;

void add(int num)
{
    struct Node *new_n = create(num);
    if(!root){
        root = new_n;
        return;
    }
    current = root;
    while(current){
        if(current->val == new_n->val){
            return;
        }
        if(current->val > new_n->val){
            if(!current->left){
                current->left = new_n;
                return;
            }
            current = current->left;
        } else {
            if(!current->right){
                current->right = new_n;
                return;
            }
            current = current->right;
        }
    } 
}

int Max()
{
    if(!root) return 0;
    current = root;
    while (current->right) current = current->right;
    return current->val;
}

int Min(){
    if(!root) return 0;
    current = root;
    while (current->left) current = current->left;
    return current->val;
}

int isPresent(int num)
{
    if(!root) return 0;
    current = root;
    while(current)
    {
        if(current->val == num)
        {
            return 1;
        } 
        
        else 
        {
            if(current->val > num)
            {
                if(current->left == NULL)
                {
                    return 0;
                } 
                
                else 
                {
                    current = current->left;
                }
            } 
            else 
            {
                if(current->right == NULL)
                {
                    return 0;
                } 
                else 
                {
                    current = current->right;
                }
            }
        }
    }
}

// void isBinTree (struct Node *node){
//     if(!node || ((!node->left || node->left->val < node->val) &&
//         (!node->right || node->right->val >= node->val) &&
//         subTree(node->left) && subTree(node->right))) return 1;
//     return 0;
// }

void printInorder(struct Node* node)
{
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->val);
    printInorder(node->right);
}

void printPreOrder(struct Node *node)
{
    if(node == NULL) return;
    printf("%d ", node->val);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printPostOrder(struct Node *node)
{
    if(node == NULL) return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ", node->val);
}

int main()
{
    add(5);
    add(6);
    add(2);
    add(9);
    add(8);
    add(1);
    printPostOrder(root);
    return 0;
}