#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "patient.h"

Patient *createPatient(char *clientID, int priority, char *symptom, int processTime, int entryPlace) {
  Patient *p = malloc(sizeof(Patient));
  p->priority = priority;
  p->clientID = clientID;
  p->symptom = symptom;
  p->processTime = processTime;
  p->entryPlace = entryPlace;
  return p;
}
