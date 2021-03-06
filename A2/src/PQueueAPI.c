#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "LinkedListAPI.h"
#include "PQueueAPI.h"
#include "patient.h"

Queue *createQueue(void(*printFunction)(void *toBePrinted), void(*deleteFunction)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second)) {
  Queue *q = malloc(sizeof(Queue));
  q->list = initializeList(printFunction, deleteFunction, compareFunction);
  return q;
}

void insertSortedQ(Queue *q, void *data) {
  insertSorted(q->list, data);
  q->count++;
}

int pop (Queue *q) {
  int count = getCount(q);

  if (count > 0) {
    removeFromFront(q->list);
    q->count--;
    return true;
  }

  return false;
}

void *peek (Queue *q) {
  void *data;
  int count = getCount(q);

  if (count > 0) {
    data = getFromFront(q->list);
    return data;
  }

return NULL;
}

int getCount (Queue *q) {
  return q->count;
}

void destroy (Queue *q) {
  deleteList(q->list);
  free(q);
}

int isEmpty (Queue *q) {
  if (q->count > 0) {
    return false;
  } else {
   return true;
  }
}

int Remove(Queue *q, void *data) {
  if (q->count > 0) {
    deleteNodeFromList(q->list, data);
    q->count--;
    return true;
  }
  return false;
}

int comparePatient (const void *first, const void *second) {
  Patient *p1 = (Patient*)first;
  Patient *p2 = (Patient*)second;

  if (p1->priority < p2->priority) {
    return 1;
  }
  else if (p1->priority > p2->priority) {
    return -1;
  }
  else if (p1->priority == p2->priority){
    return 0;
  }
return -2;
}

int compareEntry (const void *first, const void *second) {
  Patient *p1 = (Patient*)first;
  Patient *p2 = (Patient*)second;

  if (p1->entryPlace < p2->entryPlace) {
    return 1;
  }
  else if (p1->entryPlace >= p2->entryPlace) {
    return -1;
  }

return 0;
}

void deletePatient(void *toDelete) {
  Patient *p = (Patient*)toDelete;
  free(p);
}

void printPatient (void *toBePrinted) {
  Patient *p = (Patient*)toBePrinted;
  printf("%s    \t%d\t\t%s\t\t%d\n", p->clientID, p->priority, p->symptom, p->processTime);
}

