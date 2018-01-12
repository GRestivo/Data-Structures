#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedListAPI.h"


/*This is a struct for a queue
 *
 *This is a struct for a queue that holds the number of nodes in the queue and the list
 *which holds the nodes and their information
 *
 *The struct is typedef'd to be called Queue
 */
typedef struct queue {
  int count;/*number of ints in Queue*/
  List *list;
} Queue;

/*This function creates the queue in memory
 *
 *This function dynamically allocates memory for a queue. With the given function pointer it
 *then intializes a list and returns a pointer to the space in memory holding the queue
 *
 *@param void (*printFunction)(*toBePrinted), a function pointer to a print function for the queue
 *@param void (*deleteFunction)(*toBeDeleted),a function pointer to a delete function for the queue
 *@param int (*compareFunction)(const void *first, const void *second), a function pointer to a compare the queue that compares data
 *
 *@return Queue *q, a pointer to the space in memory holding the queue
 */
Queue * createQueue (void (*printFunction)(void *toBePrinted), void (*deleteFunction)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second));

/*This functions stores data into a sorted list
 *
 *This function initializes a node with the given data and stores it into a sorted list. The
 *list is sorted based on the compare function used to initialize it and the compared data.
 *Pointers are adjusted accordingly.
 *
 *This is a wrapper function to a linked list API
 *
 *@ Queue *q, A pointer to a queue in which the data is stored
 *@param void *data, A void pointer to the data that will be stored in the queue
 */
void insertSortedQ (Queue *q, void *data);

/*This function removes a node from the front of a given Queue
 *
 *This function removes a node from the front of the given Queue and then free and deletes the
 *node. Pointers are adjusted accordingly in the queue.
 *
 *This is a wrapper function for removeFrontFront(); from LinkedListAPI.c
 *
 *@param Queue *q, a pointer to the queue from which the front node will be removed
 */
int pop (Queue *q);

/*This function retrieves the data from the node at the front of the given queue.
 *
 *This is a wrapper functions for getFromFront(); from LinkedListAPI.c
 *
 *@param Queue *q, a pointer to the queue from which the data will be taken
 *
 *@return void *data, returns the data from the node at the front of the queue, if the queue is
 *empty returns NULL
 */
void *peek (Queue *q);

/*This function returns the amount of nodes in the given queue
 *
 *@param Queue *q, a pointer to the queue which you wish to know the number of nodes within
 *
 *@return q->count, the number of nodes within the given queue as an integer
 */
int getCount (Queue *q);

/*This function frees the given queue from memory
 *
 *This function frees the data from each node in the given queue, frees each individual node
 *and then frees the queue
 *
 *@param Queue *q, a pointer to the queue that is to be destroyed
 */
void destroy(Queue *q);

/*This function frees and deletes a given node
 *
 *This function takes in data for a specific node in the queue. It iterates through the queue
 *until a node with the matching data is found. The node is then freed and removed. If no node
 *is found nothing happens. Pointers are adjusted accordingly
 *
 *@param Queue *q, a pointer to the queue which holds the node to be deleted
 *@param void *data, the data of the node that is to be deleted
 */
int Remove(Queue *q, void *data);

/*This function returns 1 or -1 depending on if the given queue is not empty or empty
 *
 *@param Queue *q
 *
 *return 1, if the queue is not empty
 *return -1, if the queue is empty
 */
int isEmpty(Queue *q);

/*The function comapare 2 patients to each other based on their priorities and returns an integer
 *value based on the result
 *
 *@param const void *first, *second, void pointers to the data that will be compared
 *
 *@return 1, if the first value is < the second value
 *@return -1, if the first value is > the second value
 *@return 0, if the compared values are the same
 */
int comparePatient (const void *first, const void *second);

/*This function compares 2 patients based on their entry place into the queue and returns an
 *integer value based on the result
 *
 *@param const void *first, *second, void pointers to the data that will be compared
 *
 *@return 1, if the first value is < the second value
 *@return -1, if the first value is > the second value
 *@return 0, if the comapred values are the same
 */
int compareEntry (const void *first, const void *second);

/*This function frees the data for a specific patient
 *
 *@param void *toDelete, a void pointer to the data that will be freed
 */
void deletePatient(void *toDelete);

/*This function prints the patients data held within *toBePrinted
 *
 *@param void *toBePrinted, a void pointer to the patients data that will be printed
 */
void printPatient (void *toBePrinted);

#endif
