//
//  main.c
//  LeftViewOfTree
//
//  Created by allamaprabhu on 6/1/15.
//  Copyright (c) 2015 72f. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int level;
    struct node *left;
    struct node *right;
};

static struct node* queue[100];
int front = 0;
int rear = 0;

struct node *newNode(int data);
void leftView(struct node *root);


void push(struct node * n);
struct node* pop();
void printQueue();

int main(int argc, const char * argv[]) {
    // insert code here...
    struct node *root = newNode(10);
    
    struct node *n=newNode(5);
    root->left=n;
    n=newNode(3);
    root->right=n;
    
    n=newNode(2);
    root->left->left=n;
    
    n=newNode(6);
    root->left->right=n;
    
    n=newNode(15);
    root->left->right->left=n;
    
    n=newNode(3);
    root->left->right->left->right=n;
    
    
    n=newNode(8);
    root->right->right=n;

    n=newNode(9);
    root->right->right->right=n;

    n=newNode(10);
    root->right->right->right->right=n;

    n=newNode(11);
    root->right->right->right->right->right=n;

    
    
//    push(root);
//    push(root->left);
//    push(root->right);
//    
//    push(root->left->left);
//    push(root->left->right);
//    push(root->left->right->left);
//
//    printQueue();
    leftView(root);
}

struct node *newNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->left=NULL;
    n->right=NULL;
    n->data=data;
    n->level = 0;
    return n;
}

void leftView(struct node *root)
{
    int currentLevel = 0;
    root->level = 1;
    push(root);
    
    while (front!=rear) {
        struct node *n = pop();
        if ((n->level) > currentLevel) {
            printf("%d \n",n->data);
            currentLevel = n->level;
//            printQueue();
        }
        
        if (n->left) {
            n->left->level = n->level+1;
            push(n->left);
        }
        if (n->right) {
            n->right->level = n->level+1;
            push(n->right);
        }
    }
}

void push(struct node * n)
{
    if (queue[0]==0) {
        front = 0;
        rear = 0;
    }
    queue[rear] = n;
    rear++;
}

struct node* pop()
{
    if (queue[0]==0) {
        return NULL;
    }
    struct node *popped = queue[front];
    front++;
    return popped;
}

void printQueue()
{
    int i = front;
    do
    {
        struct node *n = queue[i];
        printf("%d\n",n->data);
        i++;
    } while (i!=rear);
}