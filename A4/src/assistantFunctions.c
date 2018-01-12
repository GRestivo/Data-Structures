#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "rule.h"
#include "BinarySearchTreeAPI.h"

void modifyRule (Tree *theTree) {
  char tempKeyword[40];
  int ratingCheck, i;
  double userRating;
  void *data;

  printf("Please enter the key word of the rule you would like to modify: ");
  fgets(tempKeyword, 35, stdin);
  for (i = 0; i < strlen(tempKeyword); i++) {
    if (tempKeyword[i] == '\n')
      tempKeyword[i] = '\0';
  }
  Rule *r = createRule(tempKeyword, "");
  data = findInTree(theTree, r);
  if (data != NULL) {
    r = (Rule*)data;
    printf("Key word found! Key word currently user value: %0.3lf\n", r->userRating);
    while (1) {
      ratingCheck = 0;
      printf("Please input the new user rating (a value between 0 - 1.0):");
      fgets(tempKeyword, 35, stdin);
      for (i = 0; i < strlen(tempKeyword) - 1; i++) {
        if (!isdigit(tempKeyword[i]) && tempKeyword[i] != '.') {
          ratingCheck = 1;
        }
      }
      if (ratingCheck != 1) {
        sscanf(tempKeyword,"%lf", &userRating);
        if (userRating < 0 || userRating > 1) {
          printf("User rating must be a value from 0 - 1.0 , try again.\n");
        } else {
          break;
        }
      } else {
        printf("Not a valid input! Must be a proper number value.\n");
      }
    }
    r->userRating = userRating;
    printf("User rating has been updated.\n\n");
  } else {
    printf("Key word was not in the tree.\n");
  }
  return;
}

void discuss (Tree *theTree) {
  char userQuestion[200], tempResponse[200], userHelpful[30];
  double topRating = 0.0;
  char *token;
  void *data;
  Rule *usedRule;

  strcpy(tempResponse,"");

  printf("Please input your question: \n");
  fgets(userQuestion, 200, stdin);
  token = strtok(userQuestion, ".?!(),\"' ");
  while (token != NULL) {
    Rule *r = createRule(token, "");
    data = findInTree(theTree, r);
    if (data != NULL) {
      r = (Rule*)data;
      if ((r->userRating + r->systemRating) > topRating) {
        topRating = r->userRating + r->systemRating;
        strcpy(tempResponse, r->response);
        usedRule = r;
      }
    }
    token = strtok(NULL, ".?!().\"' ");
  }
  if (strcmp(tempResponse, "") == 0) {
    printf("User given sentence contains no key words!.\n");
  } else {
    printf("%s\n", tempResponse);
    printf("\nWas this feedBack helpful 'y' or 'n': ");
    usedRule->totalUses++;
    while (1) {
      fgets(userHelpful, 10, stdin);
      if (strcmp(userHelpful, "y\n") == 0) {
        usedRule->systemRating = usedRule->systemRating + (usedRule->systemRating * usedRule->learningRate/usedRule->totalUses);
        break;
      } else if (strcmp(userHelpful, "n\n") == 0) {
        usedRule->systemRating = usedRule->systemRating - (usedRule->systemRating * usedRule->learningRate/usedRule->totalUses);
        break;
      } else {
        printf("Not a valid response, try again: ");
      }
    }
    if (usedRule->systemRating > 1)
      usedRule->systemRating = 1;
    else if (usedRule->systemRating < 0)
      usedRule->systemRating = 0;
  }
}
