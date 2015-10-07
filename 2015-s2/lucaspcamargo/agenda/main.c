/**
 * @file main.c
 * @author Lucas Camargo
 * @date Oct 2015
 * @brief File containing main program logic.
 */

#include <stdio.h>
#include <ctype.h>

#include "contactlist.h"

/** 
 * Adds a contact 
 */
void addContact(clist_t *);

/** 
 * Remove a contact 
 */
void removeByName(clist_t *);

/** 
 * Alter a contact 
 */
void alterByName(clist_t *);

/** 
 * Lists contacts by given birthday
 */
void listContactsBirthday(clist_t *);

/** 
 * Lists contacts by given birthmonth
 */
void listContactsMonth(clist_t *);

/** 
 * Lists contacts by given name initial
 */
void listContactsInitial(clist_t *);

/** 
 * Lists contacts by name
 */
void listContactsOrderName(clist_t *);

/** 
 * Lists contacts by birthday month
 */
void listContactsOrderMonth(clist_t *);

/**
 * Begins program execution
 */
int main() {
  
  const char * filename = "cl.dat"; 
  clist_t list;
  
  CListInit(&list);
  
  if(CListLoad(&list, filename))
    printf("Could not load contacts from file. A new file will be created.\n");
  
  int opt = -1;
  
  while(opt)
  {
    printf("\nWhat do you want to do?\n");
    printf(" [1] Add contact\n");
    printf(" [2] Remove contact\n");
    printf(" [3] Edit contact\n");
    printf(" [4] Query contacts by birthday\n");
    printf(" [5] Query contacts by birth month\n");
    printf(" [6] Query contacts by name initial\n");
    printf(" [7] Show contacts sorted by name\n");
    printf(" [8] Show contacts sorted by birthday month\n");
    printf(" [0] Exit\n");
    printf("? ");
    
    scanf("%d", &opt);
    
    switch(opt)
    {
      
      /**
      * Adds new contact
      */
      case 1: 
	addContact(&list);
	break;
	
      case 2:
	removeByName(&list);
	break;
	
      case 3:
	alterByName(&list);
	break;
	
      case 4:
	listContactsBirthday(&list);
	break;
      
      case 5:
	listContactsMonth(&list);
	break;
	
      case 6:
	listContactsInitial(&list);
	break;
	
      case 7:
	listContactsOrderName(&list);
	break;
	
      case 8:
	listContactsOrderMonth(&list);
	break;
	
      case 0:
	// do nothing
	break;
	
      default:
	printf("Invalid option.");
    }
    
  }
  
  if(CListStore(&list, filename))
    printf("Could not save contacts to file.\n");
  
  printf("Done.");
  return 0;
}
void addContact(clist_t * l)
{
  if(CListFull(l))
  {
    printf("List full :(\n");
  }
  else
  {
    ContactInput(CListGet(l, CListFindFree(l)));
  } 
}

void removeByName(clist_t * l)
{
  char name[30];
  printf("Who do you want to remove? ");
  
  clearstdin();
  fgets(name, 30, stdin);
  
  int index = CListFindName(l, name);
  if(index >= 0)
  {
    CListRemove(l, index);
  }
  else{
    printf("No one with this name was found...\n");
  }
}

void alterByName(clist_t * l)
{
  char name[30];
  printf("Who do you want to alter? ");
  
  clearstdin();
  fgets(name, 30, stdin);
  
  int index = CListFindName(l, name);
  if(index >= 0)
  {
    ContactInput(CListGet(l, index));
  }
  else{
    printf("No one with this name was found...\n");
  }
}

void listContactsBirthday(clist_t * l)
{
  int d, m;
  printf("On what day (dd/mm)? ");
  if(scanf("%d/%d", &d, &m) == 2)
  {
    CListPrintBirthday(l, d, m);
  }
  else{
    printf("Invalid input!\n");
  }
  
}

void listContactsMonth(clist_t * l)
{
  int m;
  printf("On what month (number)? ");
  if(scanf("%d", &m) == 1)
  {
    CListPrintBirthMonth(l, m);
  }
  else{
    printf("Invalid input!\n");
  }
}

void listContactsInitial(clist_t * l)
{
  
  char c[2];
  printf("What initial (letter)? ");
  if(scanf("%1s", c) == 1 && isalpha(c[0]) )
  {
    CListPrintInitial(l, c[0]);
  }
  else{
    printf("Invalid input!\n");
  }
}

void listContactsOrderName(clist_t * l)
{
  CListSort(l);
  CListPrint(l, 1);
}


void listContactsOrderMonth(clist_t * l)
{
  CListSortMonth(l);
  CListPrint(l, 0);
  CListSort(l);
  
}