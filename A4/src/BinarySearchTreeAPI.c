#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTreeAPI.h"
#include "BSTFunctions.h"
#include "rule.h"

Tree *createBinTree (CompareFunc compare, DeleteFunc del , PrintFunc print) {
  Tree *t = malloc(sizeof(Tree));
  t->root = NULL;
  t->compareFunc = compare;
  t->deleteFunc = del;
  t->printFunc = print;
  return t;
}

TreeNode *createTreeNode (TreeDataPtr data) {
  TreeNode *n = malloc(sizeof(TreeNode));
  n->data = data;
  n->left = NULL;
  n->left = NULL;
  n->parent = NULL;
  return n;
}

void destroyBinTree (Tree *toDestroy) {
  if (toDestroy == NULL) {
    printf("Tree to destroy does not exist.\n");
  } else {
    freeBinTree (toDestroy, toDestroy->root);
  }
  return;
}

int addToTree(Tree *theTree, TreeDataPtr data){
  TreeNode *nodeAdded = createTreeNode(data);

  if (theTree == NULL) {
    return 0;
  } else if (isTreeEmpty(theTree)) {
    theTree->root = nodeAdded;
  } else {
    nodeAdded = insert(theTree->root, data, theTree);
    return 1;
  }
  return 0;
}

int removeFromTree (Tree *theTree, TreeDataPtr data) {
  TreeNode *dummyNode;

  if (theTree == NULL) {
    printf("\nThe tree does not exist.\n\n");
    return 0;
  } else if (isTreeEmpty(theTree)) {
    printf("\nThe tree is currently empty.\n\n");
    return 0;
  } else if (findInTree(theTree, data) == NULL) {
    printf("\nWas not found in tree.\n\n");
    return 0;
  } else {
    dummyNode = removeBSTNode(theTree->root, data, theTree);
    theTree->compareFunc(dummyNode->data, dummyNode->data);
    return 1;
  }
}

TreeDataPtr findInTree(Tree* theTree, TreeDataPtr data) {
  if (theTree == NULL) {
    printf("The tree does not exist.\n");
    return NULL;
  } else if (isTreeEmpty(theTree)) {
    printf("The tree is currently empty.\n");
  } else {
    return findFunction(theTree->root, data, theTree);
  }

  return NULL;
}

TreeDataPtr getRootData(Tree *theTree) {
  if (theTree->root != NULL) {
    return theTree->root->data;
  }
  return NULL;
}

void printInOrder (Tree *theTree, PrintFunc print) {
  if (isTreeEmpty(theTree) || theTree == NULL)
    printf("The tree is currently empty or does not exist.\n");
  else
    printInOrderFunction(theTree, theTree->root);
  return;
}

void printPreOrder (Tree *theTree, PrintFunc printData) {
  if (isTreeEmpty(theTree) || theTree == NULL)
    printf("The tree is currently empty or does not exist.\n");
  else
    printPreOrderFunction(theTree, theTree->root);
  return;
}

void printPostOrder (Tree *theTree, PrintFunc printData) {
  if (isTreeEmpty(theTree) || theTree == NULL)
    printf("The tree is currently empty or does not exist.\n");
  else
    printPostOrderFunction(theTree, theTree->root);
  return;
}

int isTreeEmpty (Tree *theTree) {
  if (theTree->root == NULL) {
    return 1;
  }
  return 0;
}

int isLeaf (TreeNode *treeNode) {
  if (treeNode->left == NULL && treeNode->right == NULL) {
    return 1;
  }
  return 0;
}

int hasTwoChildren (TreeNode *treeNode) {
  if (treeNode->left != NULL && treeNode->right != NULL) {
    return 1;
  }
  return 0;

}

int getHeight (TreeNode *treeNode) {
  if (treeNode == NULL)
    return 0;
  int left = getHeight(treeNode->left);
  int right = getHeight(treeNode->right);
  if (right >= left)
    return right + 1;
  else
    return left + 1;
}

