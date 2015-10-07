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
 * Represents a contact
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
 * Zeroes a contact memory segment
 */
void ContactInit(contact_t * c);

contact_t * ContactCreate()
{
  contact_t * newContact = ALLOC_NEW(contact_t);
  
  ContactInit(newContact);
  
  return newContact;
}


/**
 * Deallocates a contact
 */
void ContactDestroy(contact_t * c)
{
  free(c);
}

/**
 * Initializes a contact
 */
void ContactInit(contact_t * c)
{
  memset(c, 0, sizeof(contact_t));
}


/**
 * Prints a contact
 */
void ContactPrint(contact_t * c)
{
  printf("Name: %s\n", (*c).name);
  printf("Birthday: %d/%d\n", (*c).birthDay, (*c).birthMonth);
  printf("Phone: %s\n", (*c).phone);
  printf("Email: %s\n", (*c).email);
  printf("Twitter: %s\n", (*c).twitter);
}


/**
 * Compare a contact with another keeping empty ones in the bottom
 */
int ContactCompare(contact_t * c1, contact_t * c2)
{
  if(!(*c1).name[0])
  {
    if(!(*c2).name[0])
    {
      return 0;
    }
    
    return 1;
  }
  
  if(!(*c2).name[0])
  {
      return -1;
  }
  
  return strcmp((*c1).name, (*c2).name);
}


/**
 * Fill in contact details from stdin
 */
void ContactInput(contact_t * c)
{
  clearstdin();
  
  printf("Name (%s)? ", (*c).name);
  fgets((*c).name, 30, stdin);
  printf("Birthday day (%d)? ", (*c).birthDay);
  scanf("%d", &(*c).birthDay);
  printf("Birthday month (%d)? ", (*c).birthMonth);
  scanf("%d", &(*c).birthMonth);
  printf("Phone (%s)? ", (*c).phone);
  fgets((*c).phone, 16, stdin);
  printf("Email (%s)? ", (*c).email);
  fgets((*c).email, 40, stdin);
  printf("Twitter (%s)? ", (*c).twitter);
  fgets((*c).twitter, 30, stdin);
}

#endif