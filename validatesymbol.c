#include"mylist.h"
#include<stdlib.h>
int validatesymbol(symtab *head1,char sname[10])
{
  symtab *temp1;
      for(temp1=head1;temp1!=NULL;temp1=temp1->next)
	{
	 
	  if(strcmp(sname,temp1->symname)==0)
	    {
	    temp1->status='M';
	    return 0;
	    }
	}
      return 1;
 
}
