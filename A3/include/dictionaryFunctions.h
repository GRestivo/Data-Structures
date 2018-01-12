#ifndef DICTIONARYFUNCTIONS_H
#define DICTIONARYFUNCTIONS_H

#include "HashTableAPI.h"

/**Function that takes in a file name from the user, if it exists it is compared to
 *the dictionary and the words that were not found in the dictionary are displayed
 *to the screen along with the number of incorrectly and correctly spelt words
 *@post The result of the spell check displayed to screen showing the incorrectly 
 *spelt words and the number of correctly and incorrectly spelt words
 *@param hashTable is a pointer to the hash table storing the dictionary
 */
void spellCheck(HTable *hashTable);


#endif
