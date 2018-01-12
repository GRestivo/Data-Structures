#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "simulation.h"
#include "carList.h"
#include "car.h"

#define GREEN 10
#define YELLOW 3
#define RED 14
#define RIGHT 1
#define LEFT 2.5
#define FORWARD 2


int parseCars(FILE *fPtr, List *nList, List *eList, List *sList, List *wList) {
  int numCars = 0, newNum = 0, count = 0;
  int i, j;
  int timeArrived = 0;
  char direction[1] = "";
  char turn[1] = "";
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


/*This function will run the entire simulation*/
void runSimulation (FILE * fPtr, int numCars, List *nList, List *eList, List *sList, List *wList) {
  int N = 0, E = 0, S = 0, W = 0;
  double time = 1.0, timeStart = 0.0, timeArrived = 0.0, timeCompleted = 0.0;
  double timeArrivedFrontN = 0.0, timeArrivedFrontE = 0.0, timeArrivedFrontS = 0.0, timeArrivedFrontW = 0.0, tempTimeArrivedFront = 0.0;
  char tempArray[10];
  char direction[2];
  strcpy(tempArray, "");
  Car *c;

  printf("Initial Vehicle Information    Intersection Arrival Time   Completed at Time\n");

  fseek(fPtr, 0, SEEK_SET);
  while (fgets(tempArray, 8, fPtr) != NULL) {
    sscanf(tempArray, "%c", &direction[0]);
    if (direction[0] == 'N') {
      N++;
    }
    else if (direction[0] == 'E') {
      E++;
    }
    else if (direction[0] == 'S') {
      S++;
    }
    else if (direction[0] == 'W') {
      W++;
    }
    strcpy(tempArray, "");
  }

  /*Loop that switches between directions until no cars are left*/
  while (N != 0 || E != 0 || S != 0 || W != 0) {
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*NORTH DIRECTION*/

    /*if statement to make sure time is not changed on the first rotation*/
    if (time != 1) {
      time = timeStart + RED;
    }
    timeStart = time;

    do {
      if (N == 0) {
        deleteList(nList);
        break;
      }
      else if (nList->head == NULL){
        break;
      }

     /*Reads car front front of list, if timeArrivedFront is greater than the new cars
      *arrival time then set timeArrivedFrontN to that time, then check if the new arrival
      *time passes the alloted green light time, if so then break to next direction*/
      c = (Car*)getFromFront(nList);
      if (timeArrivedFrontN == 0) {
        timeArrivedFrontN = time;
      }
      if (c->timeArrived > timeArrivedFrontN) {
        timeArrivedFrontN = c->timeArrived;
      }
      if (c->timeArrived > time) {
        time = c->timeArrived;
      }
      if (timeArrivedFrontN > timeStart + GREEN || time > timeStart + GREEN) {
        break;
      }

      /*if-else statement to find correct direction*/
      if (c->turn == 'R') {
        tempTimeArrivedFront = time;
        time = time + RIGHT;
        timeCompleted = time;
      }
      else if (c->turn == 'F') {
        tempTimeArrivedFront = time;
        time = time + FORWARD;
        timeCompleted = time;
      }
      else if (c->turn == 'L') {
        tempTimeArrivedFront = time;
        time = time + LEFT;
        timeCompleted = time;
      }

      /*Puts correct info into final print array and deletes the car*/
      printf("%c %c %d                          %.1f                         %.1f\n", c->direction, c->turn, c->timeArrived, timeArrivedFrontN, timeCompleted);
      deleteNodeFromList(nList);
      N--;

      timeArrivedFrontN = tempTimeArrivedFront;

    } while (time < timeStart + GREEN && N != 0);

    /*Checks to see if it's 1st second of yellow and car wants to turn left*/
    if (nList->head != NULL && N != 0) {
      c = (Car*)getFromFront(nList);
      if (time == (timeStart + GREEN + 1) && c->turn == 'L') {
        tempTimeArrivedFront = time;
        time = time + LEFT;
        timeCompleted = time;
        printf("%c %c %d                          %.1f                         %.1f\n", c->direction, c->turn, c->timeArrived, timeArrivedFrontN, timeCompleted);
        deleteNodeFromList(nList);
        N--;
        timeArrivedFrontN = tempTimeArrivedFront;
      }
    }

/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*EAST DIRECTION*/

    time = timeStart + RED;
    timeStart = time;
    do {
      if (E == 0) {
        deleteList(eList);
        break;
      }
      else if (eList->head == NULL){
        break;
      }

      /*Reads car front front of list, if timeArrivedFront is greater than the new cars
      *arrival time then set timeArrivedFrontN to that time, then check if the new arrival
      *time passes the alloted green light time, if so then break to next direction*/
      c = (Car*)getFromFront(eList);
      if (timeArrivedFrontE == 0) {
        timeArrivedFrontE = time;
      }
      if (c->timeArrived > timeArrivedFrontE) {
        timeArrivedFrontE = timeArrived;
      }
      if (c->timeArrived > time) {
        time = c->timeArrived;
      }
      if (timeArrivedFrontE > timeStart + GREEN || time > timeStart + GREEN) {
        break;
      }

      /*if-else statement to find correct direction*/
      if (c->turn == 'R') {
        tempTimeArrivedFront = time;
        time = time + RIGHT;
        timeCompleted = time;
      }
      else if (c->turn == 'F') {
        tempTimeArrivedFront = time;
        time = time + FORWARD;
        timeCompleted = time;
      }
      else if (c->turn == 'L') {
        tempTimeArrivedFront = time;
        time = time + LEFT;
        timeCompleted = time;
      }

      /*Puts correct info into final print array and deletes the car*/
      printf("%c %c %d                          %.1f                         %.1f\n", c->direction, c->turn, c->timeArrived, timeArrivedFrontE, timeCompleted);
      deleteNodeFromList(eList);
      E--;
      timeArrivedFrontE = tempTimeArrivedFront;

    } while (time < timeStart + GREEN && E != 0);

    /*Checks to see if it's 1st second of yellow and car wants to turn left*/
    if (eList->head != NULL && E != 0) {
      c = (Car*)getFromFront(eList);
      if (time == (timeStart + GREEN + 1) && c->turn == 'L') {
        tempTimeArrivedFront = time;
        time = time + LEFT;
        timeCompleted = time;
        printf("%c %c %d                          %.1f                         %.1f\n", c->direction, c->turn, c->timeArrived, timeArrivedFrontE, timeCompleted);
        deleteNodeFromList(eList);
        E--;
        timeArrivedFrontE = tempTimeArrivedFront;
      }
    }


/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*SOUTH DIRECTION*/

    time = timeStart + RED;
    timeStart = time;
    do {
      if (S == 0) {
        deleteList(sList);
        break;
      }
      else if (sList->head == NULL){
        break;
      }

     /*Reads car front front of list, if timeArrivedFront is greater than the new cars
      *arrival time then set timeArrivedFrontN to that time, then check if the new arrival
      *time passes the alloted green light time, if so then break to next direction*/
      c = (Car*)getFromFront(sList);
      if (timeArrivedFrontS == 0) {
        timeArrivedFrontS = time;
      }
      if (c->timeArrived > timeArrivedFrontS) {
        timeArrivedFrontS = timeArrived;
      }
      if (c->timeArrived > time) {
        time = c->timeArrived;
      }
      if (timeArrivedFrontS > timeStart + GREEN || time > timeStart + GREEN) {
        break;
      }

      /*if-else statement to find correct direction*/
      if (c->turn == 'R') {
        tempTimeArrivedFront = time;
        time = time + RIGHT;
        timeCompleted = time;
      }
      else if (c->turn == 'F') {
        tempTimeArrivedFront = time;
        time = time + FORWARD;
        timeCompleted = time;
      }
      else if (c->turn == 'L') {
        tempTimeArrivedFront = time;
        time = time + LEFT;
        timeCompleted = time;
      }

      /*Puts correct info into final print array and deletes the car*/
      printf("%c %c %d                          %.1f                         %.1f\n", c->direction, c->turn, c->timeArrived, timeArrivedFrontS, timeCompleted);
      deleteNodeFromList(sList);
      S--;
      timeArrivedFrontS = tempTimeArrivedFront;
    } while (time < timeStart + GREEN && S != 0);

    /*Checks to see if it's 1st second of yellow and car wants to turn left*/
    if (sList->head != NULL && S != 0) {
      c = (Car*)getFromFront(sList);
      if (time == (timeStart + GREEN + 1) && c->turn == 'L') {
        tempTimeArrivedFront = time;
        time = time + LEFT;
        timeCompleted = time;
        printf("%c %c %d                          %.1f                         %.1f\n", c->direction, c->turn, c->timeArrived, timeArrivedFrontS, timeCompleted);
        deleteNodeFromList(sList);
        S--;
        timeArrivedFrontS = tempTimeArrivedFront;
      }
    }

/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*WEST DIRECTION*/
    time = timeStart + RED;
    timeStart = time;
    do {
      if (W == 0) {
        deleteList(wList);
        break;
      }
      else if (wList->head == NULL){
        break;
      }

     /*Reads car front front of list, if timeArrivedFront is greater than the new cars
      *arrival time then set timeArrivedFrontN to that time, then check if the new arrival
      *time passes the alloted green light time, if so then break to next direction*/
      c = (Car*)getFromFront(wList);
      if (timeArrivedFrontW == 0) {
        timeArrivedFrontW = time;
      }
      if (c->timeArrived > timeArrivedFrontW) {
        timeArrivedFrontW = timeArrived;
      }
      if (c->timeArrived > time) {
        time = c->timeArrived;
      }
      if (timeArrivedFrontW > timeStart + GREEN || time > timeStart + GREEN) {
        break;
      }

      /*if-else statement to find correct direction*/
      if (c->turn == 'R') {
        tempTimeArrivedFront = time;
        time = time + RIGHT;
        timeCompleted = time;
      }
      else if (c->turn == 'F') {
        tempTimeArrivedFront = time;
        time = time + FORWARD;
        timeCompleted = time;
      }
      else if (c->turn == 'L') {
        tempTimeArrivedFront = time;
        time = time + LEFT;
        timeCompleted = time;
      }

      /*Prints car to output and deletes the car*/
      printf("%c %c %d                          %.1f                         %.1f\n", c->direction, c->turn, c->timeArrived, timeArrivedFrontW, timeCompleted);
      deleteNodeFromList(wList);
      W--;

      timeArrivedFrontW = tempTimeArrivedFront;

    } while (time < timeStart + GREEN && W != 0);

    /*Checks to see if it's 1st second of yellow and car wants to turn left*/
    if (wList->head != NULL && W != 0) {
      c = (Car*)getFromFront(wList);
      if (time == (timeStart + GREEN + 1) && c->turn == 'L') {
        tempTimeArrivedFront = time;
        time = time + LEFT;

        timeCompleted = time;
	      printf("%c %c %d                          %.1f                         %.1f\n", c->direction, c->turn, c->timeArrived, timeArrivedFrontW, timeCompleted);
        deleteNodeFromList(wList);
        W--;
        timeArrivedFrontW = tempTimeArrivedFront;
      }
    }
  }

return;
}
