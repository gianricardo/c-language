/**
 * @file contact.h
 * @author Lucas Camargo
 * @date Oct 2015
 * @brief File containing contact manipulation functions.
 */

#ifndef CONTACT_H_INC
#define CONTACT_H_INC

#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "common.h"

/**
 * @brief Represents a contact
 */
typedef struct contact_t_s {
  
  char name[30];
  
  int birthDay;
  int birthMonth;
  
  char phone[16];
  char email[40];
  char twitter[30];
  
} contact_t;



/**
 * @brief Zeroes a contact memory segment
 */
void ContactInit(contact_t * c);

/**
 * @brief Creates a contact object
 */
contact_t * ContactCreate();

/**
 * @brief Deallocates a contact
 */
void ContactDestroy(contact_t * c);

/**
 * @brief Initializes a contact
 */
void ContactInit(contact_t * c);


/**
 * @brief Prints a contact
 */
void ContactPrint(contact_t * c);


/**
 * @brief Compare a contact with another keeping empty ones in the bottom
 */
int ContactCompare(contact_t * c1, contact_t * c2);


/**
 * @brief Fills in contact details from stdin
 */
void ContactInput(contact_t * c);

#endif