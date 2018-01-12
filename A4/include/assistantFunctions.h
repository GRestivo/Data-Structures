#ifndef ASSISTANTFUNCTIONS_H
#define ASSISTANTFUNCTIONS_H

#include "BinarySearchTreeAPI.h"

/**
 *This function allows the user to modify the user rating of a pre-existing rule
 *The user is asked for a key word, if it exists the previous user rating is displayed
 *and the user is allowed to input a new rating, if not an error message appears
 *
 *@param theTree is a pointer to the tree with the rules to modify
 */
void modifyRule (Tree *theTree);


/**
 *This function allows the user to discuss with the 'bot'. The user inputs a question, which 
 *is then parsed into seperate words, each word is tested to see if it is in the tree, if it
 *is in the tree and has the highet rating value then the response is printed to the screen,
 *The user is then asked if the response was helpful, if yes the rating are increased accordingly
 *if no they are decreased accordingly
 *
 *@param theTree is a pointer to the tree with the rules to modify
*/
void discuss (Tree *theTree);

#endif
