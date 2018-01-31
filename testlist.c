#include "mylist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
  mnemonic *head;
symtab *head1;
bst b;
 int ans;
 b.head=NULL;
 head1=NULL;
ans=createlist(head);
  if(ans==1)
{
    fprintf(stdout,"list created successfully\n");
insertBst(&b);
}
  else
    fprintf(stderr,"list not created\n");

ans=createlist(head1);
  if(ans==1)
{
    fprintf(stdout,"list created successfully\n");
createsymtab(head1,b.head);
}
  else
    fprintf(stderr,"list not created\n");

}
