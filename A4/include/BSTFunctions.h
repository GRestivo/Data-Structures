#ifndef BSTFUNCTIONS_H
#define BSTFUNCTIONS_H

#include "BinarySearchTreeAPI.h"

/*Internal function for addToTree, discription found in BinarySearchTreeAPI.h*/
TreeNode *insert(TreeNode *currentNode, void *data, Tree *theTree);

/*Internal function for findInTree, discription found in BinarySearchTreeAPI.h*/
TreeNode *findFunction (TreeNode *currentNode, void *data, Tree *theTree);

/*Internal function for removeFromTree, discription found in BinarySearchtreeAPI.h*/
TreeNode *removeBSTNode (TreeNode *currentNode, void *data, Tree *theTree);

/*Func that finds the farthest left node in a given tree*/
TreeNode *FindMinNode (TreeNode *currentNode);

/*Internal function for detroyBinTree, discription found in BinarySearchTreeAPI.h*/
void freeBinTree (Tree *theTree, TreeNode *currentNode);

/*Next 3 functions are all internal functions for their BinarySearchTreeAPI.h counterparts*/
void printInOrderFunction (Tree *theTree, TreeNode *currentNode);

void printPreOrderFunction (Tree *theTree, TreeNode *currentNode);

void printPostOrderFunction (Tree *theTree, TreeNode *currentNode);


int compare (const void *first, const void *second);

void deleteBSTNode (void *toDelete);

void printNode (void *toBePrinted);

#endif
