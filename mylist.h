#ifndef __MYLIST__H__
#define __MYLIST__H__
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h> /* to get definition of NULL */
//char mm[10][10]={"eax","ebx","ecx","edx","esi","edi","ebp","esp"};
typedef struct mnetab
{
  int srno;
  char  *mname;
  char  *opcode;
   char *mode;
  struct mnetab *next;
}mnemonic;

typedef struct BST
{
  mnemonic *head;
}bst;

/*struct reg1
{
  int srno;
  char name[20];
  }regtab[8]={1,"eax",2,"ebx",3,"ecx",4,"edx",5,"esi",6,"edi",7,"ebp",8,"esp"};*/
typedef struct binsymtab
{
  int srno;
  char  *symname;
  char  *dtype;
  char section;
  char status;
  char *value;
  int size;
  struct binsymtab *next;
}symtab;


//mm[8][8]={1,"eax",2,"ebx",3,"ecx",4,"edx",5,"esi",6,"edi",7,"ebp",8,"esp"};
int createlist();

int _insertBst(mnemonic **head );
int insertBst(bst *b);
int createsymtab(symtab *head1,mnemonic *head);
int validatesymbol(symtab *head1,char sname[10]);
int invalidsymbol(symtab *head1,mnemonic *head);
int intermediate(symtab *head1,mnemonic *head);
#endif
