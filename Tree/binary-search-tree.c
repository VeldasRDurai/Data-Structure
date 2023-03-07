#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int item;
  struct node* left;
  struct node* right;
}NODE;

void inorderTraversal(NODE* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ", root->item);
  inorderTraversal(root->right);
}

void preorderTraversal(NODE* root) {
  if (root == NULL) return;
  printf("%d ", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(NODE* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ", root->item);
}

NODE* createNode(int value) {
  NODE* newNode = malloc(sizeof(NODE));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

NODE* insert(NODE* root, int value) {
  if (root == NULL) 
    return createNode(value);
  if (x > root->data)
    root->right = insert(root->right, value);
  else
    root->left  = insert(root->left,  value);
  return root;
}

NODE* search(NODE* root, int value) {
    if (root==NULL || root->data == value)
        return root;
    return x > root->data ? 
        search(root->right, value) :
        search(root->left, value)
}


NODE* delete(NODE* root, int value);

int main() {
}