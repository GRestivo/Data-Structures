#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "BinarySearchTreeAPI.h"
#include "BSTFunctions.h"
#include "rule.h"

TreeNode *insert (TreeNode *currentNode, void *data, Tree *theTree) {
  if (currentNode == NULL)
    return createTreeNode(data);
  if(theTree->compareFunc(currentNode->data, data) > 0)
    currentNode->right = insert(currentNode->right, data, theTree);
  else if(theTree->compareFunc(currentNode->data, data) < 0)
    currentNode->left = insert(currentNode->left, data, theTree);
  return currentNode;
}

TreeNode *findFunction (TreeNode *currentNode, void *data, Tree *theTree) {
  TreeNode *possibleNode;

  if (currentNode == NULL)
    return NULL;

  if (theTree->compareFunc(currentNode->data, data) == 0)
    return currentNode->data;

  possibleNode = findFunction(currentNode->left, data, theTree);
  if (possibleNode)
    return possibleNode;

  possibleNode = findFunction(currentNode->right, data, theTree);
  if (possibleNode)
    return possibleNode;

  return NULL;
}

TreeNode *removeBSTNode (TreeNode *currentNode, void *data, Tree *theTree) {
  printf("Could not get remove function to work.\n");

/*  if (currentNode == NULL) {
    return NULL;
  }

  if (theTree->compareFunc(data, currentNode->data) == 0) {
    printf("equals\n");
    if (currentNode->left == NULL && currentNode->right == NULL) {
      printf("flag1\n");
      theTree->deleteFunc(currentNode);
      currentNode = NULL;
    } else if (currentNode->left == NULL){
      printf("flag2\n");
      holdNode = currentNode;
      currentNode = currentNode->right;
      theTree->deleteFunc(currentNode);
    } else if (currentNode->right == NULL) {
      printf("flag3\n");
      holdNode = currentNode;
      currentNode = currentNode->left;
      theTree->deleteFunc(currentNode);
    } else {
      printf("flag4\n");
      holdNode = FindMinNode(currentNode->right);
      holdNode->left = currentNode->left;
      holdNode = currentNode;
      currentNode = currentNode->right;
      theTree->deleteFunc(holdNode);
      holdNode = NULL;
      currentNode->data = holdNode->data;
      currentNode->right = removeBSTNode(currentNode->right, holdNode->data, theTree);
      
    }
  } else if (theTree->compareFunc(data, currentNode->data) < 0) {
    printf("Flag <\n");
    currentNode->left = removeBSTNode(currentNode->left,data, theTree);
  } else if (theTree->compareFunc(data, currentNode->data) > 0) {
    printf("Flag >\n");
    currentNode->right = removeBSTNode(currentNode->right, data, theTree);
  } */
  return currentNode;
}

TreeNode *FindMinNode(TreeNode *currentNode) {
  if (currentNode != NULL) {
    while (currentNode->left != NULL) {
      currentNode = currentNode->left;
    }
  }
  return currentNode;
}


void freeBinTree (Tree *theTree, TreeNode *currentNode) {
  if (currentNode != NULL) {
    if (currentNode->left != NULL) {
      freeBinTree(theTree, currentNode->left);
    }
    if (currentNode->right != NULL) {
      freeBinTree(theTree, currentNode->right);
    }
    free(currentNode);
  }
}


void printInOrderFunction (Tree *theTree, TreeNode *currentNode) {
  if (currentNode == NULL)
    return;

  printInOrderFunction (theTree, currentNode->left);
  theTree->printFunc(currentNode->data);
  printInOrderFunction (theTree, currentNode->right);
  return;
}

void printPreOrderFunction (Tree *theTree, TreeNode *currentNode) {
  if (currentNode == NULL)
    return;

  theTree->printFunc(currentNode->data);
  printPreOrderFunction(theTree, currentNode->left);
  printPreOrderFunction(theTree, currentNode->right);
}

void printPostOrderFunction (Tree *theTree, TreeNode *currentNode) {
  if (currentNode == NULL)
    return;

  printPostOrderFunction(theTree, currentNode->left);
  printPostOrderFunction(theTree, currentNode->right);
  theTree->printFunc(currentNode->data);
}


int compare (const void *first, const void *second) {
  Rule *r1 = (Rule*)first;
  Rule *r2 = (Rule*)second;


  return strcmp(r1->keyword, r2->keyword);
}

void deleteBSTNode (void *toDelete) {
  Rule *r = (Rule*)toDelete;
  free(r);
}

void printNode(void *toBePrinted) {
  Rule *r = (Rule*)toBePrinted;
  printf("%s\tRating:%0.3lf \tSystem:%0.3lf \tOccurences:%d\n", r->keyword, r->userRating, r->systemRating, r->totalUses);
}
