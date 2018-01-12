#include <stdio.h>
#include <stdlib.h>

#include "PQueueAPI.h"
#include "patient.h"
#include "simulation.h"
#include "LinkedListAPI.h"

void simulation (Queue *q) {
  int time = 1, timeFinished = 0;
  Queue *printQ = malloc(sizeof(Queue));
  printQ = createQueue(&printPatient, &deletePatient, &compareEntry);

  printf("Beginning Simulation:\n\n");

  /*while loop that rus the simulation until no patients are left to be processed*/
  while (q->count > 0) {
    Patient *p = (Patient*)peek(q);
    timeFinished = time + p->processTime;
    time = time + p->processTime;
    Patient *newP = createPatient(p->clientID, p->priority, p->symptom, timeFinished, p->entryPlace);
    insertSortedQ(printQ, newP);
    pop(q);
    time++;
  }

  /*prints out final results in the order the patients were given, not by the order they
  were processed*/
  printf("Patient ID	Priority	Symptom Code	Time Finished\n");
  printForwards(printQ->list);
  printf("\nSimulation end\n");

  /*Frees queues*/
  destroy(q);
  destroy(printQ);

}

