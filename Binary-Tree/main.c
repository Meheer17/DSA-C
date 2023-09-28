#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100

typedef struct Node
{
    int val;
    struct Node *left, *right;
} Node;

typedef struct Queue
{
  Node *items[MAX_QUEUE_SIZE];
  int front;
  int rear;
} Queue;

void enqueue (Queue * q, Node * item)
{
  if (q->rear == MAX_QUEUE_SIZE - 1)
    {
      printf ("Queue Overflow\n");
      exit (EXIT_FAILURE);
    }
  q->rear++;
  q->items[q->rear] = item;
}

Node *dequeue (Queue * q)
{
  if (q->front == q->rear)
    {
      printf ("Queue Underflow\n");
      exit (EXIT_FAILURE);
    }
  q->front++;
  return q->items[q->front];
}

int is_empty (Queue * q)
{
  return q->front == q->rear;
}

void bfs (Node * root)
{
  Queue q;
  q.front = -1;
  q.rear = -1;

  enqueue (&q, root);

  while (!is_empty (&q))
    {
      Node *current = dequeue (&q);
      printf ("%d ", current->val);

      if (current->left != NULL)
	{
	  enqueue (&q, current->left);
	}
      if (current->right != NULL)
	{
	  enqueue (&q, current->right);
	}
    }
}

struct Node *create(int num)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL)
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
struct Node *prev = NULL;

void add(int num)
{
    struct Node *new_n = create(num);
    if (!root)
    {
        root = new_n;
        return;
    }
    current = root;
    while (current)
    {
        if (current->val == new_n->val)
        {
            return;
        }
        if (current->val > new_n->val)
        {
            if (!current->left)
            {
                current->left = new_n;
                return;
            }
            current = current->left;
        }
        else
        {
            if (!current->right)
            {
                current->right = new_n;
                return;
            }
            current = current->right;
        }
    }
}

int Max()
{
    if (!root)
        return 0;
    current = root;
    while (current->right)
        current = current->right;
    return current->val;
}

int Min()
{
    if (!root)
        return 0;
    current = root;
    while (current->left)
        current = current->left;
    return current->val;
}

int isPresent(int num)
{
    if (!root)
        return 0;
    current = root;
    while (current)
    {
        if (current->val == num)
        {
            return 1;
        }

        else
        {
            if (current->val > num)
            {
                if (current->left == NULL)
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
                if (current->right == NULL)
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

void printInorder(struct Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->val);
    printInorder(node->right);
}

void printPreOrder(struct Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->val);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printPostOrder(struct Node *node)
{
    if (node == NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ", node->val);
}

void delete(int num){
    if(!root) return NULL;
    current = root;
    prev = current;
    while(current && current->val !== num){
        prev = current;
        if(current->val > num){
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if(!current) return NULL;
    else {
        int num_nodes = 0;
        void prev_del(){
            if(prev->left == current) prev->left = NULL;
            else prev->right = NULL;
        }
        if(current->left && current->right) num_nodes = 2;
        else if(current->left || current->right) num_nodes = 1;
        if(!prev) root = NULL;
        if(num_nodes == 0){
            prev_del();
        } else if(num_nodes == 1){
            if(current->left){
                prev_del();
                add(current->left->val);
            } else {
                prev_del();
                add(current->right->val);
            }
        } else if(num_nodes == 2){
            prev_del()
            add(current->left->val);
            add(current->right->val);               
        }
    }
}

int main()
{
    add(5);
    add(6);
    add(2);
    add(9);
    add(8);
    add(1);
    bfs(root);
    return 0;
}