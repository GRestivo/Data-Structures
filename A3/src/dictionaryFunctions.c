/*This .c file contains one function called spellChek which  spell checks a user given file.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionaryFunctions.h"
#include "HashTableAPI.h"
#include "hashData.h"

void spellCheck (HTable *hashTable) {
  int  i,length, key, correctWords = 0, incWords = 0;
  char tempLine[100];
  char *word;
  FILE *fPtr;


  /*Loop that asks the user to input a file name, if the file does not exist the user is 
   *brought back to the main menu, else the file is read
   */
  while (1) {
    printf("Please input the file name of the file to be spell checked: ");
    fgets(tempLine, 100, stdin);
    length = strlen(tempLine);
    for (i = 0; i < length; i++) {
      if (tempLine[i] == '\n')
        tempLine[i] = '\0';
    }

    fPtr = fopen(tempLine,"r");

    if (fPtr == NULL) {
      printf("Error! Could not find designated file.\n");
      return;
    } else {
      break;
    }
  }
  printf("\n");

  /*Reads in file line by line comparing the new word to the dictionary. If it is not found in
  the dictionary it is outputted to the screen*/
  while (fgets(tempLine, 100,fPtr) != NULL) {
    length = strlen(tempLine);
    for (i = 0; i < length; i++) {
      if (tempLine[i] == '\n')
        tempLine[i] = '\0';
    }
    tempLine[0] = tolower(tempLine[0]);
    word = tempLine;
    key = hashTable->hashFunction(hashTable->size, word);
    HashData *d = createHashData(word,key);
    d = findData(hashTable, d);
    if(d == NULL) {/*increments incorrectly spelt words*/
      incWords++;
      printf("%s was not found int the dictionary\n", tempLine);
    } else { /*increments correctly spelt words*/
      correctWords++;
    }

  }
  printf("\n\nSummary:\n");
  printf("Correctly spelt words: %d\nIncorrectly spelt words: %d\n\n", correctWords, incWords);

  /*Close file*/
  fclose(fPtr);

return;
}

