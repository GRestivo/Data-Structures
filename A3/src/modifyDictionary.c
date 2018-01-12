/*This .c file holds two functions, the first (addWord) can add a word to the dictionary
The second (deleteWord) deletes a word from the dictionary*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "modifyDictionary.h"
#include "hashFunction.h"
#include "HashTableAPI.h"
#include "hashData.h"

void addWord (HTable *hTable) {
  int wordLength, key, i, wordCheck;
  char tempWord[100];
  char *word;

  /*while loop to get proper word input, proper meaning no blank line, spaces or non letters*/
  while (1) {
    wordCheck = 0;
    printf("Please input the word you would like to add to the dictionary: ");
    fgets(tempWord, 100, stdin);
    wordLength = strlen(tempWord);

    for (i = 0; i < wordLength - 1; i++) {
      if (!isalpha(tempWord[i]) || isspace(tempWord[i])) {
        wordCheck = 1;
      }
    }
    if (strncmp(tempWord, "\n", 1) == 0 || wordCheck == 1) {
        printf("Invalid input! Please input a single proper word.\n");
    } else {
      break;
    }
  }

  /*remove '\n' character*/
  wordLength = strlen(tempWord);
  for (i = 0; i < wordLength; i++) {
    if (tempWord[i] == '\n') {
      tempWord[i] = '\0';
    }
  }

  word = malloc(sizeof(char) * wordLength);
  strcpy(word, tempWord);

  /*Check if the word already exists, if it does not, inserts word into dictionary*/
  key = hTable->hashFunction(hTable->size, word);
  HashData *d = createHashData(word, key);
  HashData *h = (HashData*)findData(hTable, d);
  if (h == NULL) {
    insertData(hTable, key, d);
    printf("\nWord successfully added to dictionary.\n\n");
  } else {
    printf("\nWord already exists!\n\n");
  }

return;
}


void deleteWord (HTable *hTable) {
  int removeCheck, length, key, i, wordCheck;
  char tempWord[100];
  char *word;

  /*while loop to get proper word input, same rules apply as addWord*/
  while (1) {
    wordCheck = 0;
    printf("Please input the word you would like to delete from the dictionary: ");
    fgets(tempWord, 100, stdin);
    length = strlen(tempWord);

    for (i = 0; i < length - 1; i++) {
      if (!isalpha(tempWord[i]) || isspace(tempWord[i])) {
        wordCheck = 1;
      }
    }
    if (strncmp(tempWord, "\n", 1) == 0 || wordCheck == 1) {
      printf("Invalid input! Please input a proper word.\n");
    } else {
      break;
    }
  }

  /*remove '\n' from word*/
  length = strlen(tempWord);
  for (i = 0; i < length; i++) {
    if (tempWord[i] == '\n') {
      tempWord[i] = '\0';
    }
  }

  /*Check if word exists, if it does then it is deleted, if not then the user is informed*/
  word = malloc (sizeof(char) * 50);
  strcpy(word, tempWord);
  key = hTable->hashFunction(hTable->size,word);
  HashData *h = createHashData(word,key);
  removeCheck = removeNode(hTable, h);
  if (removeCheck == 1) {
    printf("\nWord successfully deleted.\n\n");
  } else {
    printf("\nWord could not be found.\n\n");
  }

return;
}

