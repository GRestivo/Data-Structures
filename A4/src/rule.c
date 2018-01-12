#include <stdlib.h>

#include "rule.h"

Rule *createRule(char *keyword, char *response) {
  Rule *r = malloc(sizeof(Rule));
  r->keyword = keyword;
  r->response = response;
  r->totalUses = 0;
  return r;
}
