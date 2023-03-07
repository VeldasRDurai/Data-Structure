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

NODE* insertLeft(NODE* root, int value) {
  root->left = create(value);
  return root->left;
}

NODE* insertRight(NODE* root, int value) {
  root->right = create(value);
  return root->right;
}

int main() {
}