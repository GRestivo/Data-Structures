#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "car.h"

Car *createCar( char direction, char turn, int time )
{
    Car *c = malloc(sizeof(Car));
    c->direction  = direction;
    c->turn = turn;
    c->timeArrived = time;
    return c;
}
