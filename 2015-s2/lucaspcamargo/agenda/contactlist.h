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
#include "stdio.h"

// Fixed size for the list
#define CL_SIZE 30

// Utility
#define self (*c)

/** 
 * Struct for list data that might store other things in the future
*/
typedef struct clist_t_s {
  contact_t buf[CL_SIZE];
} clist_t;

/**
 * Initializes the list object
 */
void CListInit(clist_t * c)
{
  memset(c, 0, sizeof(clist_t));
}

/**
 * Allocates space for a new object
 */
clist_t * CListCreate()
{
  clist_t * newList = ALLOC_NEW(clist_t);
  
  CListInit(newList);
  
  return newList;
}

/**
 * Deallocates object
 */
void CListDestroy(clist_t * c)
{
  free(c);
}

/**
 * Get item from list
 */
contact_t * CListGet(clist_t * c, int index)
{
  return &(self.buf[index]);
}

/**
 * Sets item on list
 */
void CListSet(clist_t * c, int index, contact_t val)
{
  (self.buf[index]) = val;
}

int CListRemove(clist_t * c, int index)
{
  ContactInit(&(self.buf[index]));
}


/**
 * Load list from file
 */
int CListLoad(clist_t * c, const char * filename)
{
  FILE * f = fopen(filename, "rb");
  
  if(f)
  {    
    int readCount = fread(c, sizeof(clist_t), 1, f);
    fclose(f);
    
    if(readCount == 1)
      return 0; // success
    else
    {
      // did not read enough
      memset(c, 0, sizeof(clist_t)); // clear list block
      return -2;
    }
  }
  else return -1; // could not open file
}

/**
 * Store list in file
 */
int CListStore(clist_t * c, const char * filename)
{
  
  printf("Writing records to file [%s]\n", filename);
  
  FILE * f = fopen(filename, "w");
  
  if(f)
  {
    
    int res = fwrite(c, sizeof(clist_t), 1, f);
    fclose(f);
    
    if(res == 1)
    {
      return 0; // success
    }
    else
    {
      return -2; // write failure
    }
  }
  else return -1; // could not open file
  
}

/**
 * Print whole list
 */
void CListPrint(clist_t * c, int printNums)
{
  int printed = 0;
  printf("\n");
  
  for(int i = 0; i < CL_SIZE; i++)
  {
    if(!(*CListGet(c, i)).name[0])
      continue;
    
    printed = 1;
    
    if(printNums) printf("#%d\n", i+1);
    ContactPrint(CListGet(c, i));
    printf("\n");
    
  }
    if(!printed)
      printf("No records to print.\n");
}

/**
 * Print people with this birthday
 */
void CListPrintBirthday(clist_t * c, int d, int m)
{
  int printed = 0;
  printf("\n");
  
  for(int i = 0; i < CL_SIZE; i++)
  {
    if(!(*CListGet(c, i)).name[0])
      continue;
    
    if((*CListGet(c, i)).birthDay != d || (*CListGet(c, i)).birthMonth != m)
      continue;
    
    printed = 1;
    
    ContactPrint(CListGet(c, i));
    printf("\n");
    
  }
    if(!printed)
      printf("No one born on this day.\n");
}

/**
 * Print people with this birthmonth
 */
void CListPrintBirthMonth(clist_t * c, int m)
{
  printf("\n");
  int printed = 0;
  
  for(int i = 0; i < CL_SIZE; i++)
  {
    if(!(*CListGet(c, i)).name[0])
      continue;
    
    if((*CListGet(c, i)).birthMonth != m)
      continue;
    
    printed = 1;
    
    ContactPrint(CListGet(c, i));
    printf("\n");
    
  }
    if(!printed)
      printf("No one born on this month.\n");
}

/**
 * Print people with this initial
 */
void CListPrintInitial(clist_t * c, char ch)
{
  printf("\n");
  int printed = 0;
  
  for(int i = 0; i < CL_SIZE; i++)
  {
    if(!(toupper((*CListGet(c, i)).name[0]) == toupper(ch)))
      continue;
    
    printed = 1;
    
    ContactPrint(CListGet(c, i));
    printf("\n");
    
  }
    if(!printed)
      printf("No one has the initial %c.\n", toupper(ch));
}

/**
 * Find first vacant index in the list
 */
int CListFindFree(clist_t * c)
{
  for(int i = 0; i < CL_SIZE; i++)
  {
    if(!(*CListGet(c, i)).name[0])
      return i;
  }
  
  return -1;
}

/**
 * Counts how many records there are
 */
int CListCount(clist_t * c)
{
  int count = 0;
  
  for(int i = 0; i < CL_SIZE; i++)
  {
    if((*CListGet(c, i)).name[0])
      count++;
  }
  
  return count;
}

/**
 * Returns true if list empty
 */
int CListEmpty(clist_t * c)
{
  return CListCount(c) == 0;
}

/**
 * Returns true if list full
 */
int CListFull(clist_t * c)
{
  return CListCount(c) == CL_SIZE;
}

/**
 * Sorts list by name
 */
void CListSort(clist_t * c)
{
  contact_t swap;
  int swapped = 1;
  
  while(swapped)
  {
    swapped = 0;
    
    for(int i = 0; i <(CL_SIZE-1); i++)
    {
      if(ContactCompare( &(self.buf[i]), &(self.buf[i+1]) ) > 0)
      {
	swap = self.buf[i];
	self.buf[i] = self.buf[i+1];
	self.buf[i+1] = swap;

	swapped = 1;
      }
    }
  }
}


/**
 * Sorts list by month
 */
void CListSortMonth(clist_t * c)
{
  contact_t swap;
  int swapped = 1;
  
  while(swapped)
  {
    swapped = 0;
    
    for(int i = 0; i <(CL_SIZE-1); i++)
    {
      if(self.buf[i].birthMonth > self.buf[i+1].birthMonth)
      {
	swap = self.buf[i];
	self.buf[i] = self.buf[i+1];
	self.buf[i+1] = swap;

	swapped = 1;
      }
    }
  }
}

/**
 * Gives list index corresponding to name
 */
int CListFindName(clist_t * c, const char * name)
{
  for(int i = 0; i <(CL_SIZE-1); i++)
  {
    if(!strcmp(CListGet(c, i)->name, name))
      return i;
  }
  return -1;
}

/**
 * avoid pollution of preprocessor symbol space
 */
#undef self

#endif