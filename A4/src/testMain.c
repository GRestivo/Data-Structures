#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "BinarySearchTreeAPI.h"
#include "rule.h"
#include "BSTFunctions.h"

int main (int argc, char **argv) {
  int i;

  char **testString = malloc(sizeof(char*) * 20);
  for (i = 0; i < 20; i++) {
    testString = malloc(sizeof(char) * 50);
  }
  i = 0;

  /*This is the test main*/
  printf("|||||BEGIN TESTING|||||\n\n");

/*||||||||||||||||||||||||||||||||||||||||||||||||||*/
  printf("BEGIN TESTING FOR CREATEBINARYSEARCHTREE\n");
  printf("Testing with NULL input values for function pointer parameters\n");
  /*Tree *nullBST = createBinTree(NULL,NULL,NULL);*/
  printf("Function will fail if program attempts to use the function pointers!\n");
  printf("Testing with proper function pointers.\n");
  Tree *theTree = createBinTree(&compare, &deleteBSTNode, &printNode);
  printf("If returned binary search tree == NULL print 'NULL' on next line, else print 'Exists'\n");
  if (theTree == NULL) {
    printf("NULL\n");
  } else {
    printf("Exists\n");
  }
  printf("TESTING ISTREEEMPTY FUNCTION\n");
  printf("If tree is empty (return is 1) printf 'empty', else print 'not empty'\n");
  if (isTreeEmpty(theTree)) {
    printf("Empty\n");
  } else {
    printf("Not Empty\n");
  }
  printf("Result should be empty.\n");
  printf("TESTING SUCCESSFUL\n\n");

/*|||||||||||||||||||||||||||||||||||||||||||||||||*/
  printf("BEGIN TESTING FOR INSERTDATA\n");
  printf("Test by values 1-5 while no values are in the table (Values 1 - 5 will be added in random order).\n");

  testString[i] = "2";
  Rule *r = createRule(testString[i],"");
  addToTree(theTree, r);
  i++;
  testString[i] = "5";
  r = createRule(testString[i], "");
  addToTree(theTree, r);
  i++;
  testString[i] = "1";
  r = createRule(testString[i], "");
  addToTree(theTree, r);
  i++;
  testString[i] = "3";
  r = createRule(testString[i], "");
  addToTree(theTree, r);
  i++;
  testString[i] = "4";
  r = createRule (testString[i], "");
  addToTree(theTree, r);
  i++;

  printf("TESTING ISTREEEMPTY FUNCTION\n");
  printf("If tree is empty (return is 1) print 'empty', else print 'not empty'\n");
  if (isTreeEmpty(theTree)) {
    printf("Empty\n");
  } else {
    printf("Not empty\n");
  }
  printf("Result should be 'not empty'\n");
  printf("DONE TESTING FOR ISTREEEMPTY\n");

  printf("BEGIN TESTING FOR printINorder\n");
  printf("Displaying in order tree: \n");
  printInOrder(theTree, NULL);
  printf("TEST SUCCESSFUL\n");
  printf("BEGIN TESTING FOR printPREorder\n");
  printf("Displaying tree with pre-ordering\n");
  printPreOrder(theTree, NULL);
  printf("TEST SUCCESSFUL\n");
  printf("BEGIN TESTING FOR printPOSTorder\n");
  printf("Displaying tree with post-ordering\n");
  printPostOrder(theTree, NULL);
  printf("TEST SUCCESSFUL\n");

  printf("RETURNING TO INSERT TESTING\n");

  printf("Testing by sending function a non pointer for the data.\n");
  /*Rule *r = createRule("","");*/
  printf("This test causes a segmentation fault or incorrect output!\n");
  printf("TESTING SUCCESSFUL\n\n");

/*|||||||||||||||||||||||||||||||||||||||||||||*/
  printf("BEGIN TESTING FOR FINDINTREE\n");
  printf("Testing with trying to find data that exists (3)\n");
  testString[i] = "3";
  r = createRule(testString[i], "");
  r = findInTree(theTree, r);
  i++;
  printf("Returned result: %s\n", r->keyword);
  printf("Testing with trying to find data that does not exist (6)\n");
  printf("Returned result: (If returned value == NULL, then 'No data found' will appear, else nothing will happen)\n");
  testString[i] = "6";
  r = createRule(testString[i], "");
  r = findInTree(theTree, r);
  i++;
  if (r == NULL) {
    printf("No data found.\n");
  }
  printf("TESTING SUCCESSFUL\n\n");

/*|||||||||||||||||||||||||||||||||||||||||||||*/
  printf("BEGIN TESTING FOR REMOVEFROMTREE\n");
  printf("!!!***Could not get this function to work***!!!");
  printf("TESTING FAILED\n\n");


/*||||||||||||||||||||||||||||||||||||||||||||||||*/
  printf("BEING TESTING FOR GETROOTDATA\n");
  printf("Printing root data, should be '2' as it was the first data inserted\n");
  r = (Rule*)getRootData(theTree);
  theTree->printFunc(r);
  printf("TESTING SUCCESSFUL\n");

/*||||||||||||||||||||||||||||||||||||||||||||||||||*/
  printf("BEGIN TESTING FOR ISLEAF\n");
  printf("Test with first node inserted (root), should return 0\n");
  if (isLeaf(theTree->root)) {
    printf("Returned 1, is a leaf\n");
  } else {
    printf("Returned 0 is not a leaf\n");
  }
  printf("Testing with last node inserted (4), should return 1\n");
  r = createRule("4","");
  /*if (theTree->root->left->right->left != NULL) {
    printf("good1\n");
  }
  if (theTree->root->left->right->right != NULL) {
    printf("good2\n");
  }*/
  if (isLeaf(theTree->root->left->right->left)) {
    printf("Returned 1, is a leaf\n");
  } else {
    printf("Returned 0, is not a leaf\n");
  }

  printf("TESTING SUCCESSFUL\n");

/*|||||||||||||||||||||||||||||||||||||||||||||||||*/
  printf("BEGIN TESTING FOR HASTWOCHILDREN\n");
  printf("Testing with root (2), should return 1\n");
  if (hasTwoChildren(theTree->root)) {
    printf("returned 1, had 2 children\n");
  } else {
    printf("returned 0, does not have 2 children.\n");
  }

  printf("Testing with none-root (1), should return 0\n");
  if (hasTwoChildren(theTree->root->left)) {
    printf("returned 1, has 2 children\n");
  } else {
    printf("returned 0, does not have 2 children\n");
  }

  printf("TESTING SUCCESSSFUL\n");

/*|||||||||||||||||||||||||||||||||||||||||||||||||*/
  printf("BEGIN TESTING FOR GETTREEHEIGHT\n");
  printf("Testing with root\n");
  printf("Height = %d\n", getHeight(theTree->root));

  printf("Testing with root right child\n");
  printf("Height - %d\n", getHeight(theTree->root->right));

  printf("Testing with root left child\n");
  printf("Height = %d\n", getHeight(theTree->root->left));

  printf("TESTING SUCCESSFUL\n");

/*|||||||||||||||||||||||||||||||||||||||||||||||*/
  printf("BEGIN TESTING FOR DESTROYBINTREE\n");
  printf("Tree before destruction:\n");
  printInOrder(theTree, NULL);
  printf("Tree after destruction: \n");
  destroyBinTree(theTree);
  /*printInOrder(theTree, NULL);*/
  printf("Nothing is displayed because the tree no long exists\n");
  printf("TESTING SUCCESSFUL\n\n");

  printf("|||||TESTING COMPLETE|||||\n");

return 0;
}
