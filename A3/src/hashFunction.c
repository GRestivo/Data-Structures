/*This is the hash for the hash table API, returning an numeric key based on the size of the
size of the table and the first letter of the given word*/
#include <string.h>
#include <ctype.h>

#include "hashFunction.h"

int hashFunction(size_t tableSize, void *key) {
  char *Key = (char *)key;
  char firstLetter = ' ';
  int numKey = 0;

  firstLetter = tolower(Key[0]);
  numKey = firstLetter % tableSize;

return numKey;
}
