#ifndef ADDREMOVE_H
#define ADDREMOVE_H

#include "BinarySearchTreeAPI.h"

/**
 *This function allows the user to add a new rule with a customized keyword, response,
 *userRating and learning rate. The rule will not be accepted if it already exists
 *
 *@param theTree is a pointer the the tree in which the rule will be added
 */
void addRule(Tree *theTree);

/**
 *This function allows the user to remove an existing rule. The user inputs a keyword and if
 *it exists in the tree it is removed.
 *
 *@param theTree is a pointer to the tree with the rule to be deleted
 */
void removeRule(Tree *theTree);

#endif
