#include "PQueueAPI.h"

/*This function runs the hospital emergency room simulation
 *
 *This function runs the hospital emergency room simulation. After each patient is processed
 *they are removed from the queue and the time they are finished being processed is set to
 *the time. The new information is then stored in a new Queue which sorts the patients based
 *on their entry place and not their priority. The final queue is then printed to the screen
 *and the simulation is finished
 *
 *@param Queue *q, a pointer to the queue which holds all the sorted patients for the
 *simulation
 */
void simulation (Queue *q);
