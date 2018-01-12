#include <stdio.h>
#include <stdlib.h>

#include "carList.h"
#include "car.h"

List *initializeList(void (*printFunction)(void *toBePrinted), void (*deleteFunction)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second)) {
  List *list = malloc(sizeof(List));
  list->printNode = printFunction;
  list->deleteNode = deleteFunction;
  list->compareNode = compareFunction;
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

    toAdd->next = temp;
    temp->previous = toAdd;
    toAdd->previous = NULL;
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

    toAdd->previous = temp;
    temp->next = toAdd;
    list->tail->next = NULL;
  }
}

void deleteList (List *listToDelete) {
  Node *currentNode = listToDelete->head;
  Node *nextNode;

  while (currentNode != NULL) {
    nextNode = currentNode->next;
    listToDelete->deleteNode(currentNode->data);
    free(currentNode);
    currentNode = nextNode;
  }
  listToDelete->head = NULL;
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
  if (list->head != NULL) {
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

/*Deletes a node from the front of the list*/
void deleteNodeFromList (List *list) {
  Node *currentNode = list->head;
  Node *nextNode;

  if (currentNode != NULL) {
    nextNode = currentNode->next;
    list->deleteNode(currentNode->data);
    free(currentNode);
    list->head = nextNode;
  }
  return;
}

/*deletes a node that could be anywhere in a list*/
void deleteRandomNodeFromList (List *list, void *toBeDeleted) {

  if (list->head != NULL) {
    if (list->head->next != NULL) {
      Node *future = list->head->next;
      Node *pres = list->head;
      Node *prev;

      while (future != NULL) {
        if (list->compareNode(pres->data, toBeDeleted) == 0) {
          list->deleteNode(pres->data);
          free(pres);
          if (prev == NULL) {
            future->previous = NULL;
          }
          else if (future == NULL) {
            prev->next = NULL;
          } else {
            future->previous = prev;
            prev->next = future;
          }
          return;
        }
        prev = pres;
        pres = future;
        future = future->next;
      }
      if (list->compareNode(pres->data, toBeDeleted) == 0) {
        list->deleteNode(pres->data);
        free(pres);
        prev->next = future;
        return;
      }
    } else {
      if (list->compareNode(list->head->data, toBeDeleted) == 0) {
        list->deleteNode(list->head->data);
        free(list->head);
      }
    }
  }

return;
}


int compareCar (const void *first, const void *second) {
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

void deleteCar(void *toDelete) {
  Car *c = (Car*)toDelete;
  free(c);
}


void printCar (void *toBePrinted) {
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
