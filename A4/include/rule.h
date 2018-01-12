#ifndef RULE_H
#define RULE_H

typedef struct rule {
  char *keyword;
  char *response;
  double userRating;
  double systemRating;
  double learningRate;
  int totalUses;
} Rule;

Rule *createRule (char *keyword, char *response);

#endif
