/**The is the main for a program that holds a dictionary in a hash table and allows several
 *different functions to be executed modifying and using the dictionary
 *@author Gordon Restivo
 *@student number: 0971067
 *@last date modified: 11/14/2017
 */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "hashFunction.h"
#include "HashTableAPI.h"
#include "hashData.h"
#include "modifyDictionary.h"
#include "dictionaryFunctions.h"

int main (int argc, char **argv) {
  FILE *fPtr;
  char tempChoice[100];
  char *string;
  int choice = 0, breakCheck = 0, i = 0;


  /*Error test to see if there are the correct number of command line arguments, if not end program*/
  if (argc != 2) {
    printf("Error! Incorrect amount of command line arguments!\n");
    return -1;
  }

  /*Opens given file for reading*/
  fPtr = fopen(argv[1], "r");

  /*Sees if file opening was successful, if not end program*/
  if (fPtr == NULL) {
    printf("Error! Could not find designated file.\n");
    return -1;
  }

  /*creates hash table*/
  size_t tableSize = 26;
  HTable *hTable = createTable(tableSize, &hashFunction, &destroyNodeData, &printKeyData);

  string = malloc (sizeof(char) * 50);

  /*reads in file line by line and inputs it into the hash table*/
  while (fgets(string, 100, fPtr) != NULL) {
    int length = strlen(string);
    for (i = 0; i < length; i++) {
      if (string[i] == '\n') {
        string[i] = '\0';
      }
    }
    string[0] = tolower(string[0]);
    int tempKey = hashFunction(tableSize, string);
    HashData *d = createHashData(string,tempKey);
    insertData(hTable, tempKey, d);
    string = malloc(sizeof(char) * 50);
  }

  /*Closes file pointer*/
  fclose(fPtr);

  /*Command loop to give user different dictionary function options*/
  while (true) {
    printf("1) Add a word to Dictionary\n");
    printf("2) Remove a word from Dictionary\n");
    printf("3) Spell Check a file\n");
    printf("4) Show Dictionary Words\n");
    printf("5) Quit\n");
    printf("Input choice: ");
    fgets(tempChoice, 100, stdin);
    tempChoice[1] = '\0';
    if (isdigit(tempChoice[0])) {
      choice = atoi(tempChoice);
      if (choice >= 1 && choice <= 5) {
        switch(choice) {
          case 1:
            addWord(hTable);
            break;
          case 2:
            deleteWord(hTable);
            break;
          case 3:
            spellCheck(hTable);
            break;
          case 4:
            printHashTable(hTable);
            break;
          case 5:
            breakCheck = 1;
            break;
        }
      } else {
        printf("Invalid input! Must be a number between 1-5, please try again.\n");
      }
      if (breakCheck == 1) {
        break;
      }
    } else {
      printf("Invalid input! Must be a number between 1-5, please try again.\n");
    }
  }

  /*frees the hash table*/
  destroyTable(hTable);
  /*for (i = 0; i < 1000; i++) {
    free(string[i]);
  }*/
  free(string);

return 0;
}
