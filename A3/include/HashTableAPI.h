/**
 * @file HashTableAPI.h
 * @author Gordon Restivo
 * @date Nov 2017
 * @brief File containing the function definitions of a hash table
 */

#ifndef _HASH_API_
#define _HASH_API_

#include <stdio.h>
#include <stdlib.h>


#include "LinkedListAPI.h"

/**
*Hash table structure
**/
typedef struct HTable HTable;
struct HTable
{
	size_t size; /*< number that represents the size of the hash table*/
	List **array;/*< array that contains all of the table nodes*/
	void (*destroyData)(void *data); /*< function pointer to a function to delete a single piece of data from the hash table*/
	int (*hashFunction)(size_t tableSize, void *key); /*< function pointer to a function to hash the data */
  void (*printNode)(void *toBePrinted); /*< function pointer to a function that prints out a data element of the table*/

    /**A function pointer for add is not mandatory, just a suggestion for adding. 
    * Assigned as &insertDataInMap when initializing a map.
    * Allows overloading of function names to use standard naming conventions, similar to the object oriented approach.
    **/
  void (*add) (struct HTable *hashTable, void *data); /*< function pointer for users to add a data element to the map.*/
};


/**Function to point the hash table to the appropriate functions. Allocates memory to the struct and table based on the size given.
*@return pointer to the hash table
*@param size size of the hash table
*@param hashFunction function pointer to a function to hash the data
*@param destroyData function pointer to a function to delete a single piece of data from the hash table
*@param printNode function pointer to a function that prints out a data element of the table
**/
HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, void *key),void (*destroyData)(void *data),void (*printNode)(void *toBePrinted));

/**Function for creating a node for the hash table.
*@pre Node must be cast to void pointer before being added.
*@post Node is valid and able to be added to the hash table
*@param key integer that represents the data (eg 35->"hello")
*@param data is a generic pointer to any data type.
*@return returns a node for the hash table
**/
Node *createNode(int key, void *data);

/** Deletes the entire hash table and frees memory of every element.
*@pre Hash Table must exist.
*@param hashTable pointer to hash table containing elements of data
**/
void destroyTable(HTable *hashTable);  

/**Inserts a Node in the hash table.
*@pre hashTable type must exist and have data allocated to it
*@param hashTable pointer to the hash table
*@param key integer that represents the data (eg 35->"hello")
*@param data pointer to generic data that is to be inserted into the list
**/
void insertData(HTable *hashTable, int key, void *data);

/** THIS FUNCTION IS NOT MANDATORY, users call this function to insert a Node in the hash table.
* It's meant as a wrapper for insertData so the users don't need to generate the key when adding.
*@pre hashTable type must exist and have data allocated to it
*@param hashTable pointer to the hash table
*@param data pointer to generic data that is to be inserted into the list
**/
/*void insertDataInMap(HTable *hashTable, void *data);*/

/**Function to remove a whol chained list from the hash table
 *@pre Hash table must exist and have memory allocated to it
 *@post List at key will be removed from the hash table if it exists.
 *@param hashTable pointer to the hash table struct
 *@param key integer that represents a piece of data in the table (eg 35->"hello")
 **/
int removeNode(HTable *hashTable, void *data);

/**Function to remove a specific node from a chained list
 *@pre Hash table must exist and have memory allocaed to it
 *@post Node in chained list removed from the hash table if it exists
 *@param hashTable pointer to the hash table struct
 *@param ey integer tat represents a piece of data in the table
 */
void removeKeyData(HTable *hashTable, int key);

/**Function that prints the entire hash table to the screen
 *@pre Hash table must exist and have memory allocaed to it
 *@post All contents of the hash table outputted to the screen based upon the print function
 *@param hashTable pointer to the hash table struct
 */
void printHashTable (HTable *hashTable);

/**Does exactly the same as lookUpData
 */
void *findData (HTable *hashTable, void *data);

/**Function to return the data from the key given.
 *@pre The hash table exists and has memory allocated to it
 *@param hashTable pointer to the hash table containing data nodes
 *@param key integer that represents a piece of data in the table (eg 35->"hello")
 *@return returns a pointer to the data in the hash table. Returns NULL if no match is found.
 **/
int lookupData(HTable *hashTable, int key);

/*compares the data between two nodes*/
int compareNodeData(const void *data1, const void *data2);

/*wrapper to the hash function*/
int hashNode(size_t tableSize, void *key);

/*frees data in a specific node from a given list*/
void destroyNodeData(void *data);

/*Prints a specific node in a given list*/
void printNodeData(void *toBePrinted);

/*Prints the entire list in a given row from the hashTable*/
void printKeyData(void *toBePrinted);

#endif
