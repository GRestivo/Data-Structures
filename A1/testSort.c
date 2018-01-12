#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "carList.h"
#include "testSort.h"
#include "car.h"

int parseCars(FILE *fPtr, List *nList, List *eList, List *sList, List *wList) {
  int numCars = 0, newNum = 0, count = 0;
  int i, j;
  char direction[1] = "";
  char turn[1] = "";
  int timeArrived = 0;
  char carArray[1000][8];
  for (i = 0; i < 1000; i++) {
    strcpy(carArray[i], "");
  }

  /*Reads in from file 1 line at a time into a car array and counts them*/
  i = 0;
  while (fgets(carArray[i], 8, fPtr) != NULL) {
      sscanf(carArray[i],"%c %c %d", &direction[0], &turn[0], &timeArrived);
      sprintf(carArray[i], "%d",timeArrived);
      strcat(carArray[i], " ");
      strncat(carArray[i], direction, 1);
      strcat(carArray[i], " ");
      strncat(carArray[i], turn, 1);
      numCars++;
      i++;
  }

  /*dynamically creates a 2D array for the sorted cars*/
  char **sortedArray;
  sortedArray = malloc(sizeof(char*) * numCars);
  for (i = 0; i < numCars; i++) {
    sortedArray[i] = malloc(sizeof(char) * 8);
  }

  /*sorts array in carArray and stores it in sortedArray*/
  for (j = 0; j < numCars; j++) {
    timeArrived = 2000;
    for (i = 0; i < numCars; i++) {
      sscanf(carArray[i],"%d", &newNum);
      if (newNum < timeArrived) {
        timeArrived = newNum;
        count = i;
      }
    }
  strcpy(sortedArray[j], carArray[count]);
  strcpy(carArray[count], "2001");
  }

  /*Organizes the cars into 4 different lists*/
  for (i = 0; i < numCars; i++) {
    sscanf(sortedArray[i], "%d %c %c", &timeArrived, &direction[0], &turn[0]);
    if (direction[0] == 'N') {
      Car *c = createCar(direction[0], turn[0], timeArrived);
      insertBack(nList, c);
    }
    else if (direction[0] == 'E') {
      Car *c = createCar(direction[0], turn[0], timeArrived);
      insertBack(eList, c);
    }
    else if (direction[0] == 'S') {
      Car *c = createCar(direction[0], turn[0], timeArrived);
      insertBack(sList, c);
    }
    else if (direction[0] == 'W') {
      Car *c = createCar(direction[0], turn[0], timeArrived);
      insertBack(wList, c);
    }
  }

return numCars;
}
