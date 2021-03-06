
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashFunction.h"
#include "HashTableAPI.h"
#include "LinkedListAPI.h"
#include "hashData.h"


HTable *createTable (size_t size, int (*hashFunction)(size_t tableSize, void *key), void (*destroyData)(void *data), void (*printNode)(void *toBePrinted)) {
  int i = 0;

  HTable *hTable = malloc(sizeof(HTable));
  hTable->hashFunction = hashFunction;
  hTable->destroyData = destroyData;
  hTable->printNode = printNode;
  hTable->size = size;
  hTable->array = malloc(sizeof(Node) * size);
  for (i = 0; i < size; i++) {
    hTable->array[i] = malloc(sizeof(List));
    List *list = initializeList(&printNodeData,&destroyNodeData,&compareNodeData);
    hTable->array[i] = list;
  }
  return hTable;
}

void destroyTable (HTable *hashTable) {
  int i = 0;

  if (hashTable != NULL) {
    for (i = 0; i < hashTable->size; i++) {
      removeKeyData(hashTable, i);
      /*free(hashTable->array[i]);*/
    }
  }
}

void insertData (HTable *hashTable, int key, void *data) {

  if (hashTable != NULL) {
    List *list = hashTable->array[key];
    insertBack(list, data);
  }

}

void removeKeyData (HTable *hashTable, int key) {

  if (hashTable != NULL) {
    List *list = hashTable->array[key];
    if (list->head != NULL) {
      deleteList(list);
    }
  }

}


int removeNode (HTable *hashTable, void *data) {

  if (hashTable != NULL) {
    HashData *d = (HashData*)data;
    List *list = hashTable->array[d->key];
    if (list->head != NULL) {
      return deleteNodeFromList(list, data);
    }
  }
  return -1;
}

void printHashTable (HTable *hashTable) {
  int i = 0;

  if (hashTable != NULL) {
    printf("\n");
    for (i = 0; i < hashTable->size; i++) {
      List *list = hashTable->array[i];
      if (list->head != NULL) {
      	printForwards(list);
      }
    }
    printf("\n");
  }

}


void *findData (HTable *hashTable, void *data) {

  if (hashTable != NULL) {
    HashData *h = (HashData*)data;
    List *list = hashTable->array[h->key];

    Node *current = list->head;

    while (current != NULL) {
      if (list->compareNode(current->data, data) == 0) {
        return current->data;
      }
      current = current->next;
    }
  }
  return NULL;
}


int lookUpData (HTable *hashTable, void *data) {

  HashData *d = (HashData*)data;
  List *list = hashTable->array[d->key];

  Node *current = list->head;

  while (current != NULL) {
    if (list->compareNode(current->data,data) == 0) {
      return 1;
    } else if (current->next != NULL) {
      current = current->next;
    } else {
      return -1;
    }
  }
  return -1;
}

int hashNode (size_t tableSize, void *key) {
  int hash = hashFunction(tableSize, key);
  return hash;
}

int compareNodeData (const void *data1, const void *data2) {
  HashData *d1 = (HashData*)data1;
  HashData *d2 = (HashData*)data2;
  return strcmp(d1->word,d2->word);
}

void destroyNodeData (void *data) {
  HashData *d = (HashData*)data;
  free(d);
}

void printKeyData (void *toBePrinted) {
  List *list = (List*)toBePrinted;
  printForwards(list);
}

void printNodeData (void *toBePrinted) {
  HashData *h = (HashData*)toBePrinted;
  printf("%d:%s\n",  h->key,h->word);
}
