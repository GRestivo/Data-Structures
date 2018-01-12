#include <stdio.h>
#include <stdlib.h>

#include "carList.h"
#include "car.h"



int main(int argc, char **argv) {
  FILE *fPtr = fopen(argv[1], "r");
  Car *c;

  List *testList = initializeList(&printCar, &deleteCar, &compareCar);

  int i = 0, numCars = 0;
  char turn[2] = "";
  char direction[2] = "";
  int timeArrived = 0;
  char carArray[15][8];
  for (i = 0; i < 15; i++) {
    carArray[i][0] = '\0';
  }

  i = 0;
  while (fgets(carArray[i], 8, fPtr) != NULL) {
      sscanf(carArray[i],"%c %c %d", &direction[0], &turn[0], &timeArrived);
      printf("%c %c %d\n", direction[0], turn[0], timeArrived);
      c = createCar(direction[0], turn[0], timeArrived);
      insertBack(testList, c);
      numCars++;
      i++;
  }
/*
  printf("\n");
  deleteNodeFromList(testList);
  printf("\n");
  printForwards(testList);
  deleteNodeFromList(testList);
  printf("\n");
  printForwards(testList);
  deleteNodeFromList(testList);
  printf("\n");
  printForwards(testList);

*/


  printf("\n");
  i = 0;
  while (testList->head != NULL) {
    deleteNodeFromList(testList);
    printForwards(testList);
    printf("\n");
    i++;
  }

return 0;

}
