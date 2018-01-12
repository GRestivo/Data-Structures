#include <stdio.h>
#include <stdlib.h>

#include "LinkedListAPI.h"
#include "car.h"

List *initializeList(void (*printFunction)(void *toBePrinted), void (*deleteFunction)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second)) {
  List *list = malloc(sizeof(List));
  list->printNode = printFunction;
  list->deleteNode = deleteFunction;
  list->compare = compareFunction;
  list->head = NULL;
  list->tail = NULL;
return list;
}

Node *initializeNode(List *list, void *data) {
  Node *n = malloc(sizeof(Node));
  n->data = data;
  n->next = NULL;
  n->previous = NULL;
  return n;
}

void insertFront (List *list, void *toBeAdded) {
  Node *toAdd = initializeNode(list, toBeAdded);
  Node *temp;

  /*if head of list is NULL then there is nothing in the list yet*/
  if (list->head == NULL) {
    list->head = toAdd;
    list->tail = toAdd;
  } else {/*If not NULL, find head and redefine to new node*/
    temp = list->head;
    list->head = toAdd;

    list->head->next = temp;
    temp->previous = list->head;
    list->head->previous = NULL;
  }
}

void insertBack (List *list, void *toBeAdded) {
  Node *toAdd = initializeNode(list, toBeAdded);
  Node *temp;

  if (list->head == NULL) {
    list->head = toAdd;
    list->tail = toAdd;
  } else {
    temp = list->tail;
    list->tail = toAdd;

    list->tail->previous = temp;
    temp->next = list->tail;
    list->tail->next = NULL;
  }
}

void deleteList (List *listToDelete) {
  Node *itr = listToDelete->head;
  Node *nextNode = itr->next;

  while (itr != NULL) {
    listToDelete->deleteNode(itr->data);
    itr = nextNode;
    nextNode = itr->next;
    nextNode->previous = NULL;
  }
}

void printForwards (List *list) {
  Node *itr = list->head;

  while (itr != NULL) {
    list->printNode(itr->data);
    itr = itr->next;
  }

}

void printBackwards  (List *list) {
  Node *itr = list->tail;

  while (itr != NULL) {
    list->printNode(itr->data);
    itr = itr->previous;
  }
}


void *getFromFront (List *list) {
  if (list != NULL && list->head != NULL) {
    return list->head->data;
  }
  return NULL;
}

void *getFromBack (List *list) {
  if (list != NULL && list->tail != NULL) {
    return list->tail->data;
  }
  return NULL;
}

int deleteNodeFromList (List *list, void *toBeDeleted) {

  if (list->head != NULL) {
    printf("Flag 1\n");
    if (list->head->next != NULL) {
      Node *future = list->head->next;
      Node *pres = list->head;
      Node *prev = list->head->previous;

      printf("2\n");
      while (future != NULL) {
        printf("3\n");
        if (list->compare(pres->data, toBeDeleted) == 0) {
          list->deleteNode(pres->data);
          free(pres);
          printf("4\n");
          if (prev == NULL) {
            future->previous = NULL;
            printf("5\n");
          }
          else if (future == NULL) {
            prev->next = NULL;
            printf("6\n");
          } else {
            future->previous = prev;
            prev->next = future;
          printf("7\n");
          }
          return 1;
        }
        printf("Not equal\n");
        prev = pres;
        pres = future;
        future = future->next;
      }
      if (list->compare(pres->data, toBeDeleted) == 0) {
        printf("8\n");
        list->deleteNode(pres->data);
        free(pres);
        prev->next = future;
        return 1;
      }
    } else {
      printf("9\n");
      if (list->compare(list->head->data, toBeDeleted) == 0) {
        list->deleteNode(list->head->data);
        free(list->head);
        printf("10\n");
      }
    }
  }

return -1;
}


int compare (const void *first, const void *second) {
  Car *car1 = (Car*)first;
  Car *car2 = (Car*)second;

  if (car1->timeArrived < car2->timeArrived) {
    return 1;
  }
  else if (car1->timeArrived > car2->timeArrived) {
    return -1;
  }
  else {
    return 0;
  }
}

void deleteListNode(void *toDelete) {
  Car *c = (Car*)toDelete;
  free(c);
}


void printNode (void *toBePrinted) {
  Car *c = (Car*)toBePrinted;
  printf("%c %c %d\n", c->direction, c->turn, c->timeArrived);
}



/*
potential code for insert sorted
*/

void insertSorted (List *list, void *toBeAdded) {
/*
  if (temp-> == NULL) {
    list->head = toAdd;
    list->tail = toAdd;
  } else {

    while (something(has to do with comparison) && temp != NULL) {
    }
  }
*/
return;
}
