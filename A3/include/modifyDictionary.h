#ifndef MODIFYDICTIONARY_H
#define MODIFYDICTIONARY_H

#include "HashTableAPI.h"

/**Function that adds a user given word to the hash table, only adds the word if it
 *doesn't already exist in the hashTable
 *@post user given word is added to hash table if it isn't already there
 *@param hashTable is a pointer to the Hash table to be added to
 */
void addWord (HTable *hashTable);

/**Function that deletes a user given word from the hash table, only deletes if the
 *word exists
 *@post given word is removed from the hash table if it was already present
 *@param hashTable is a pointer to the Hash table to be added to
 */
void deleteWord (HTable *hashTable);

#endif
