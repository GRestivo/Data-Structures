#ifndef PATIENT_H
#define PATIENT_H


/*A struct for a patient that holds their ID, symptom, priority, the time it takes to process
 *them in the hospital and the place the were entered in the queue
 *
 *The struct is typedef'd to be called Patient
 */
typedef struct patient {
  int priority;
  int processTime;
  int entryPlace;
  char *clientID;
  char *symptom;
} Patient;

/*This function dynamically creates a pointer to data that holds a patients information
 *
 *@param char *clientID, a pointer to a string in memory holding the clients ID
 *@param int priority, a priority number from 1-5
 *@param char *symptom, the symptom the patient has
 *@param int processTime, the amount of time it takes to deal with the given symptom
 *@param int entryPlace, the place the patient was entered into the queue
 *
 *@Return Patient *p, a pointer the patients information in memory
 */
Patient *createPatient(char *clientID, int priority, char *symptom, int processTime, int entryPlace);

#endif
