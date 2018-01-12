#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "addRemoveRule.h"
#include "BinarySearchTreeAPI.h"
#include "rule.h"

void addRule(Tree *theTree) {
  char *keyWord = malloc (sizeof(char) * 30);
  char *response = malloc(sizeof(char) * 200);
  char tempNums[30];
  double userRating, learningRate;
  int i =0, ratingCheck = 0, kWordCheck = 0;
  void *data;

  /*Loop to get new key word and to check if it already exists*/
  while (1) {
    kWordCheck = 0;
    printf("Please input a key word for the new rule: ");
    fgets(keyWord, 100, stdin);
    for (i = 0; i < strlen(keyWord); i++) {
      if (keyWord[i] == ' ')
        kWordCheck = 1;
      if (keyWord[i] == '\n') {
        keyWord[i] = '\0';
      }
    }
    Rule *r = createRule(keyWord, response);
    data = findInTree(theTree, r);
    if (strcmp(keyWord, "\n") == 0) {
      printf("Cannot enter an empty string, try again.\n");
    } else if (kWordCheck == 1) {
      printf("Key word must be a singular word with no spaces! Try again.\n");
    } else if (data != NULL) {
      printf("Rule already exists! Try again.\n");
    } else {
      break;
    }
  }

  /*Loop to get response for key word*/
  while (1) {
    printf("Please input a response for the new rule: ");
    fgets(response, 200, stdin);
    for (i = 0; i < strlen(response); i++) {
      if (response[i] == '\n')
        response[i] = '\0';
    }
    if (strcmp(response ,"\n") == 0) {
      printf("Cannot enter an empty string, try again.\n");
    } else {
      break;
    }
  }
  /*Get user rating*/
  while (1) {
    ratingCheck = 0;
    printf("Please input the user rating (a value between 0 - 1.0):");
    fgets(tempNums, 25, stdin);
    for (i = 0; i < strlen(tempNums) - 1; i++) {
      if (!isdigit(tempNums[i]) && tempNums[i] != '.') {
        ratingCheck = 1;
      }
    }
    if (ratingCheck != 1) {
      sscanf(tempNums,"%lf", &userRating);
      if (userRating < 0 || userRating > 1) {
        printf("User rating must be a value from 0 - 1.0 , try again.\n");
      } else {
        break;
      }
    } else {
      printf("Not a valid input! Must be a proper number value.\n");
    }
  }
  /*Get learning rate*/
  while (1) {
    ratingCheck = 0;
    printf("Please input the learning rate (a value between 0 - 1.0):");
    fgets(tempNums, 25, stdin);
    for (i = 0; i < strlen(tempNums) - 1; i++) {
      if (!isdigit(tempNums[i]) && tempNums[i] != '.') {
        ratingCheck = 1;
      }
    }
    if (ratingCheck != 1) {
      sscanf(tempNums,"%lf",&learningRate);
      if (learningRate < 0 || learningRate > 1) {
        printf("Learning Rate must be a value from 0 - 1.0 , try again.\n");
      } else {
        break;
      }
    } else {
      printf("Not a valid input! Must be a number value.\n");
    }
  }

  for (i = 0; i < strlen(keyWord); i++) {
    if (keyWord[i] == '\n')
      keyWord[i] = '\0';
  }
  for (i = 0; i < strlen(response); i++) {
    if (response[i] == '\n')
      response[i] = '\0';
  }

  Rule *r = createRule (keyWord, response);
  r->userRating = userRating;
  r->systemRating = userRating;
  r->learningRate = learningRate;


  addToTree(theTree, r);
  printf("Rule successfully added.\n");

return;
}

void removeRule (Tree *theTree) {
  char *keyWord = malloc (sizeof(char) * 30);
  char *response = malloc(sizeof(char) * 2);
  int i =0, kWordCheck = 0;

  /*Loop to get new key word and to check if it already exists*/
  while (1) {
    kWordCheck = 0;
    printf("Please input a key word of the rule to be deleted: ");
    fgets(keyWord, 100, stdin);
    for (i = 0; i < strlen(keyWord); i++) {
      if (keyWord[i] == ' ') {
        kWordCheck = 1;
      }
    }
    if (strcmp(keyWord, "\n") == 0) {
      printf("Cannot enter an empty string, try again.\n");
    } else if (kWordCheck == 1) {
      printf("Key word must be a singular word with no spaces! Try again.\n");
    } else {
      break;
    }
  }

  for (i = 0; i < strlen(keyWord); i++) {
    if (keyWord[i] == '\n')
      keyWord[i] = '\0';
  }

  strcpy(response,"");
  Rule *r = createRule (keyWord, response);

  if (removeFromTree(theTree, r) == 1) {
    printf("Rule was successfully removed.\n");
  }

return;
}
