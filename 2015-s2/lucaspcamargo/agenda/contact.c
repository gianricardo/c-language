#include "contact.h"

#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "common.h"


void ContactInit(contact_t * c)
{
  memset(c, 0, sizeof(contact_t));
}

contact_t * ContactCreate()
{
  contact_t * newContact = ALLOC_NEW(contact_t);
  
  ContactInit(newContact);
  
  return newContact;
}


void ContactDestroy(contact_t * c)
{
  free(c);
}

void ContactPrint(contact_t * c)
{
  printf("Name: %s\n", (*c).name);
  printf("Birthday: %d/%d\n", (*c).birthDay, (*c).birthMonth);
  printf("Phone: %s\n", (*c).phone);
  printf("Email: %s\n", (*c).email);
  printf("Twitter: %s\n", (*c).twitter);
}

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

void ContactInput(contact_t * c)
{
  
  printf("Name (%s)? ", (*c).name);
  clearstdin();
  memset((*c).name, 1, 30);
  fgets((*c).name, 30, stdin);
  trim((*c).name);
  printf("Birthday day (%d)? ", (*c).birthDay);
  scanf("%d", &(*c).birthDay);
  printf("Birthday month (%d)? ", (*c).birthMonth);
  scanf("%d", &(*c).birthMonth);
  printf("Phone (%s)? ", (*c).phone);
  clearstdin();
  memset((*c).phone, 1, 16);
  fgets((*c).phone, 16, stdin);
  trim((*c).phone);
  printf("Email (%s)? ", (*c).email);
  memset((*c).email, 1, 40);
  fgets((*c).email, 40, stdin);
  trim((*c).email);
  printf("Twitter (%s)? ", (*c).twitter);
  memset((*c).twitter, 1, 30);
  fgets((*c).twitter, 30, stdin);
  trim((*c).twitter);
}