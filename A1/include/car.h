#ifndef CAR_H
#define CAR_H
/**
 *Creates a struct that stores info for a car.
 *
 *Is a struct for a car that holds three pieces of information, the cars direction it will arrive from,
 *they direction it will turn and the time it will arrive at the intersecion
 *The struct is typedef'd to be called Car.
 */
typedef struct car {
    char direction;
    char turn;
    int timeArrived;
} Car;

/**
 *This function creates a car
 *
 *Creates a car that is stored in a struct called Car. Space is dynamically allocated 
 *with the size being the size of struct Car.
 *
 *@param direction is the direction from which the car arrived
 *@param turn is which way the car is going to turn 
 *@param timeArrived is the time the car arrived at the intersection
 *
 *@return a pointer to a struct Car with the given information
 */
Car *createCar(char direction, char turn, int time);

#endif
