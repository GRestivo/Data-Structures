#ifndef SIMULATION_H
#define SIMULATION_H

#include "carList.h"

/*
 *Reads in info from given file pointer, parses cars into correct direction list
 *
 *Reads in information from a given file pointer line by line. The info is organized by time
 *arrived and then moved into the correct list based on the given direction
 *
 *@param FILE *fPtr : a file pointer to a file opened for reading only
 *@param List *nList, *eList, *sList, *wList : 4 pointers to a list of cars coming from every
 *direction
 *
 *@return numCars : the total number of cars in the given file
 */
int parseCars(FILE *fPtr, List *nList, List *eList, List *sList, List *wList);


/*
 *Runs car 4 way stop light simulation
 *
 *Rotates between 4 directions of approaching cars, reads in their data, sends cars through
 *stop light at appropriate times, records time arrived at the front and time completed for
 *every car and prints this information once the simulation is complete
 *
 *@param int numCars : total number of cars from the given file
 *@param List *nList, eList, sList, wList : 4 pointers to a list of cars coming from every
 *direction
 *
 *@return None
 */
void runSimulation(FILE *fPtr, int numCars, List *nList, List *eList, List *sList, List *wList);


#endif
