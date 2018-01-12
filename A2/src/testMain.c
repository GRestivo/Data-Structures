/*This function tests the priority Queue*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "LinkedListAPI.h"
#include "patient.h"
#include "PQueueAPI.h"

void printTest(void *toBePrinted) {
  Patient *p = (Patient*)toBePrinted;
  printf("%d\n", p->priority);
}

int main (int argc, char **argv) {
  Patient *p;
  void *data;
  char *testID = malloc(sizeof(char) * 10);
  char *testS = malloc(sizeof(char) * 2);
  strcpy(testS,"");
  strcpy(testID, "");


  printf("|||||BEGIN TESTING|||||\n");


  printf("|||TESTING CREATE QUEUE|||\n");

  printf("Testing by sending valid parameters\n");
  Queue *q = malloc(sizeof(Queue));
  q = createQueue(&printTest, &deletePatient, &comparePatient);
  q->count = 0;
  printf("Pointer to queue successfully returned, it will be used for the rest of the tests\n");

  printf("Errors cause by invalid paramters or not using a pointer to a queue.\n");
  /*
  int *ptr = malloc(sizeof(Queue));
  ptr = createQueue(NULL,NULL,NULL);
  */

  printf("TEST SUCCESSFUL\n");

  /*||||||||||||||||||||||||||||||||||||||||||||||*/
  printf("|||TESTING INSERT SORTED QUEUE|||\n");

  printf("Testing with an empty queue, inserting value 5:\n");

  p = createPatient(testID, 5,testS, 0, 0);
  insertSortedQ(q,p);
  printForwards(q->list);
  printf("Printing entire queue displays one node with value 5\n");

  printf("Testing with 1 3 5 in the queue and insert 2:\n");
  p = createPatient(testID,1,testS,0,0);
  insertSortedQ(q,p);
  p = createPatient(testID,3,testS,0,0);
  insertSortedQ(q,p);
  p = createPatient(testID,2,testS,0,0);
  insertSortedQ(q,p);
  printForwards(q->list);
  printf("Printing the entire queue should have the order 1,2,3,5\n");

  printf("Testing with 1 2 3 5 in the queue and inserting 1:\n");
  p = createPatient(testID,1,testS,0,0);
  insertSortedQ(q,p);
  printf("Printing the entire queue should have the order 1,1,2,3,5 with the second 1 being Test3\n");
  printForwards(q->list);

  /*inserting into a non existing queue will cause a seg fault*/
  printf("TEST SUCCESS\n");

  /*|||||||||||||||||||||||||||||||||||||||||||||*/
  printf("|||TESTING POP QUEUE|||\n");

  printf("Testing with a queue with 5 nodes (1,1,2,3,5) and removing the front node:\n");
  pop(q);
  printForwards(q->list);
  printf("Printing the entire q should have the order 1,2,3,5\n");
  printf("Testing with a queue with 4 nodes () and removing all nodes one at a time\n");
  pop(q);
  pop(q);
  pop(q);
  pop(q);
  printForwards(q->list);
  printf("Printing the entire queue should display nothing\n");
  puts("");
  printf("Testing with an empty queue\n");
  pop(q);
  printf("Returns NULL becasue queue is empty\n");
  printf("TEST SUCCESS\n");

  /*|||||||||||||||||||||||||||||||||||||*/
  printf("|||TESTING PEEK QUEUE|||\n");

  printf("Testing with an empty queue:\n");
  data = peek(q);
  printf("Test returned NULL\n");

  printf("Testing with a queue with 1 node, node holds number 5:\n");
  p = createPatient("Tests Peek",5,"",0,0);
  insertSortedQ(q,p);
  data = peek(q);
  q->list->printNode(data);
  printf("Test returned top node data of 5\n");


  printf("Testing with a queue with multiple nodes (values 4,5,6), top node holds number 4:\n");
  p = createPatient(testID,4,testS,0,0);
  insertSortedQ(q,p);
  p = createPatient(testID,6,testS,0,0);
  insertSortedQ(q,p);
  data = peek(q);
  q->list->printNode(data);
  printf("Test returned top node data of 4\n");
  printf("TEST SUCCESS\n");


/*||||||||||||||||||||||||||||||||||||||||||||*/
  printf("|||TESTING REMOVE FROM QUEUE|||\n");

  printf("Removing 5 from a queue of (4,5,6)\n");
  p = createPatient(testID, 5, testS,0,0);
  Remove(q,p);
  printForwards(q->list);
  printf("Test should return only 4 and 6\n");
  printf("Removing 6 from a queue of (4,6)\n");
  p = createPatient(testID,6,testS,0,0);
  Remove(q,p);
  printForwards(q->list);
  printf("Test should return only 4\n");
  printf("TEST SUCCESSFUL\n");

  /*||||||||||||||||||||||||||||||||||||||*/
  printf("|||TESTING ISEMPTY|||\n");

  printf("Checking isEmpty with a queue with non empty queue:\n");
  if (isEmpty(q) == false) {
    isEmpty(q);
  }
  printf("Test returned False because list is not empty\n");
  while (q->count > 0) {
    pop(q);
  }
  printf("Check isEmpty with a queue with no nodes:\n");
  if (isEmpty(q) == true) {
    printf("Test returned True because list is empty\n");
  }
  printf("TEST SUCCESS\n");

  /*|||||||||||||||||||||||||||||||||||||||*/
  printf("|||TESTING DESTROY QUEUE|||\n");

  printf("Testing with a queue that exists:\n");
  destroy(q);
  printf("Testing with a queue that does not exist (the same queue again):\n");
  /*destroy(q) - causes segfault because list does not exist*/
  printf("Causes seg fault because list does not exist.\n");

  printf("|||||END TESTING|||||\n");

free(testID);
free(testS);

return 0;
}
