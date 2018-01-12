#include <stdio.h>
#include <stdlib.h>

#include "carList.h"
#include "simulation.h"

int main (int argc, char *argv[]) {
  FILE *fPtr;
  int numCars = 0;

  /*Error test to see if there are the correct number of command line arguments, if not end program*/
  if (argc != 2) {
    printf("Incorrect amount of command line arguments!\n");
    return -1;
  }

  /*Opens given file for reading*/
  fPtr = fopen(argv[1], "r");

  /*Sees if file opening was successful, if not end program*/
  if (fPtr == NULL) {
    printf("Error! Could not find designated file.\n");
    return -1;
  }

  /*Create and initialize a list for every direction*/
  List *nList = initializeList(&printCar, &deleteCar, &compareCar);
  List *eList = initializeList(&printCar, &deleteCar, &compareCar);
  List *sList = initializeList(&printCar, &deleteCar, &compareCar);
  List *wList = initializeList(&printCar, &deleteCar, &compareCar);

  /*Calls parseCars function that seperates cars into correct direction list & returns numCars*/
  numCars = parseCars(fPtr, nList, eList, sList, wList);

  /*Calls runSimulation function to run the stop light simulation*/
  runSimulation(fPtr, numCars, nList, eList, sList, wList);

  /*Close file and deletes lists again just in case*/
  fclose(fPtr);
  deleteList(nList);
  deleteList(eList);
  deleteList(sList);
  deleteList(wList);

return 0;
}
