#ifndef ADDPATIENTS_H
#define ADDPATIENTS_H

#include <stdlib.h>

#include "PQueueAPI.h"

/*This functions adds the patients from the given file to a priority queue
 *
 *This function reads the given file using the file pointer line by line until reaching the end
 *end of the given file. Based on the symptom code in the file a processing time is associated
 *with the patient. A new patient is dynamically created and then inserted into the priority
 *queue
 *
 *@param FILE *fPtr, a file pointer to the file from which the patients are read from
 *@param Queue *q, a pointer to the queue in which the patients are stored
 *
 *@return int entryPlace, the number of patients read in from the given file
 */
int originalPatients (FILE *fPtr, Queue *q);

/*This function adds a new patient based on user inputted data
 *
 *This function allows the user to add a new patient to the queue after the file patients have
 *been added. The user inputs a clientID (Can be anything except a blank line), a symptom
 *(Must be one of the verified symptom codes) and a priority(must be a number from 1-5)
 *
 *@param Queue *q, a pointer the queue in which the new patient will be entered
 *@param int entryPlace, the placing of the last entered patient
 *
 *@return int entryPlace, the numerical placing of when the patient was placed in the queue
 */
int addNewPatient (Queue *q, int entryPlace);

#endif
