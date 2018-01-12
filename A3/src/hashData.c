/*This .c file has one function which dynamically creates data for the hash table*/
#include <stdlib.h>

#include "hashData.h"

HashData *createHashData (char *word, int key) {
  HashData *h = malloc(sizeof(HashData));
  h->word = word;
  h->key = key;
  return h;
}
