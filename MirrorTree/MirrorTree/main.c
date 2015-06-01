//
//  main.c
//  MirrorTree
//
//  Created by allamaprabhu on 5/19/15.
//  Copyright (c) 2015 GeeksForGeek. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
static int count = 0;

struct node *newNode(int data);
void mirror(struct node *root);
void countLeaf(struct node *root);

int main(int argc, const char * argv[]) {
    // insert code here...
    struct node *root = newNode(1);
    
    struct node *n=newNode(3);
    root->left=n;
    n=newNode(2);
    root->right=n;
    n=newNode(5);
    root->right->left=n;
    n=newNode(4);
    root->right->right=n;
    
//    mirror(root);
    countLeaf(root);
    printf("%d\n",count/2);
    
    return 0;
}

struct node *newNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->left=NULL;
    n->right=NULL;
    n->data=data;
    return n;
}

void countLeaf(struct node *root)
{
    if (root==NULL) {
        count++;
        return;
    }
    countLeaf(root->left);
    countLeaf(root->right);
}

void mirror(struct node *root)
{
    if (root==NULL)
        return;
    if (root->left && root->right) {
        struct node *temp = root->left;
        root->left=root->right;
        root->right=temp;
    }
    else if (root->left == NULL && root->right) {
        root->left=root->right;
        root->right = NULL;
    }
    else if (root->right ==NULL && root->left) {
        root->right=root->left;
        root->left=NULL;
    }
    mirror(root->left);
    mirror(root->right);
}