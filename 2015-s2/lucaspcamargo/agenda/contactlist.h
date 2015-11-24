/**
 * @file contactlist.h
 * @author Lucas Camargo
 * @date Oct 2015
 * @brief File containing contact manipulation functions for a a fixed-capacity contact list.
 */

#ifndef CONTACTLIST_H_INC
#define CONTACTLIST_H_INC

// Uses contact datatype
#include "contact.h"

/**
 * @brief Fixed size for the list
 */
#define CL_SIZE 30


/** 
 * @brief Struct for list data that might store other things in the future
*/
typedef struct clist_t_s {
  contact_t buf[CL_SIZE];
} clist_t;

/**
 * @brief Initializes the list object
 */
void CListInit(clist_t * c);

/**
 * @brief Allocates space for a new object
 */
clist_t * CListCreate();

/**
 * @brief Deallocates object
 */
void CListDestroy(clist_t * c);

/**
 * @brief Get item from list
 */
contact_t * CListGet(clist_t * c, int index);

/**
 * @brief Sets item on list
 */
void CListSet(clist_t * c, int index, contact_t val);

/**
 * @brief Removes an item from the list
 */
int CListRemove(clist_t * c, int index);

/**
 * @brief Load list from file
 */
int CListLoad(clist_t * c, const char * filename);

/**
 * @brief Store list in file
 */
int CListStore(clist_t * c, const char * filename);
/**
 * @brief Print whole list
 */
void CListPrint(clist_t * c, int printNums);

/**
 * @brief Print people with this birthday
 */
void CListPrintBirthday(clist_t * c, int d, int m);

/**
 * @brief Print people with this birthmonth
 */
void CListPrintBirthMonth(clist_t * c, int m);

/**
 * @brief Print people with this initial
 */
void CListPrintInitial(clist_t * c, char ch);

/**
 * @brief Find first vacant index in the list
 */
int CListFindFree(clist_t * c);

/**
 * @brief Counts how many records there are
 */
int CListCount(clist_t * c);

/**
 * @brief Returns true if list empty
 */
int CListEmpty(clist_t * c);

/**
 * @brief Returns true if list full
 */
int CListFull(clist_t * c);
/**
 * @brief Sorts list by name
 */
void CListSort(clist_t * c);

/**
 * @brief Sorts list by month
 */
void CListSortMonth(clist_t * c);

/**
 * @brief Gives list index corresponding to name
 */
int CListFindName(clist_t * c, const char * name);


#endif