/*This is the main for a program that runs a hospital Emergncy room simulation */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "addPatients.h"
#include "PQueueAPI.h"
#include "simulation.h"

int main (int argc, char **argv) {
  FILE *fPtr;
  char userChoice[1000];
  int choice = 0, check = 0;
  int entryPlace = 0;

  Queue *q = malloc(sizeof(Queue));
  q = createQueue(&printPatient, &deletePatient, &comparePatient);
  q->count = 0;

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

  entryPlace = originalPatients(fPtr, q);

  /*command loop*/
  do {
    printf("1. Enter a new patient.\n");
    printf("2. Start the simulation\n");
    printf("3. Quit\n");
    printf("Please enter 1, 2 or 3 as your choice: ");
    fgets(userChoice, 1000, stdin);
    int temp = strlen(userChoice);
    if (!isdigit(userChoice[0]) || temp > 2) {/*Input testing*/
      printf("\nInvalid input! Please try again.\n\n");
    } else {
      choice = atoi(userChoice);
      if (choice == 1) {/*Adds a new patient to the priorityQueue*/
        entryPlace = addNewPatient(q, entryPlace);
        printf("New patient successfully added.\n");
      }
      else if (choice == 2) {/*Runs the simulation, prints result and exits*/
        simulation(q);
        check = 1;
      }
      else if (choice == 3) {/*Quits the simulation*/
        printf("Quit\n");
        break;
      } else {
        printf("\nInvalid Number! Please try again.\n\n");
      }
    }
  } while (check != 1);

return 0;
}
