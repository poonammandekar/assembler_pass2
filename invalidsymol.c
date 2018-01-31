#include"mylist.h"
#include<stdlib.h>
int invalidsymbol(symtab *head1,mnemonic *head)
{
  FILE *fp;
  symtab *temp;
  mnemonic *temp1;
  char str[1024],s1[10],s2[10],s3[10],s4[10];
  int flag,flag1,i;
  for(temp=head1;temp!=NULL;temp=temp->next)
    {
  if((temp->symname[0]<'a' || temp->symname[0]>'z')&&(temp->symname[0]<'A' || temp->symname[0]>'Z'))
    {
      if(strcmp(temp->dtype,"label")==0)
	printf("%s is invalid label\n",temp->symname);
	else
      printf("%s is invalid symbol\n",temp->symname);
    }
  if(temp->status=='M')
    {
      printf("redefinition of %s\n",temp->symname);
    }
    }
    fp=fopen("intermediate","r");
  while(!feof(fp))
    {
      fgets(str,1024,fp);    
      sscanf(str,"%s%s%s%s",s1,s2,s3,s4);
      if((strcmp(s1,"section")==0)&&(strcmp(s2,".text")==0))
	{
	prev:
	  strcpy(s1,"\0");
	  strcpy(s2,"\0");
	  strcpy(s3,"\0");
	  strcpy(s4,"\0");
	  fgets(str,1024,fp);
	  sscanf(str,"%s%s%s%s",s1,s2,s3,s4);
	  if(strcmp(s1,"extern")==0)
	    {
	      goto prev;
	    }
	 else if((strcmp(s1,"global")==0)&&(strcmp(s2,"main")==0))
	{
	 
       	  temp=head1;
	  while(temp!=NULL)
	    {
	  if(strcmp(s2,temp->symname)!=0)
	    {
	      temp=temp->next;
	      break;
	    }
	  else
	    temp=temp->next;
	    }
	   if(temp==NULL)
	    {
	      printf("%s is used but not defined\n",s2);
	    }
	}
      else
	{
	  if(feof(fp))
	    {
	      return 0;
	    }
	  else
	    {
	  i=0;
	  flag=0;
	  while(s1[i]!='\0')
	    {
	      if(s1[i]==':')
		{
	      flag=1;
	      break;
		}
	      else
		{
		  i++;
		}
	    }
	  if(flag==0)
	    {
	  flag1=0;
          flag=0;
		  for(temp1=head;temp1!=NULL;temp1=temp1->next)
		    {

		      if(strcmp(s1,temp1->mname)==0)
			{
			  flag1=1;
			  break;
			}
		    }
		  	  if(flag1==0)
		    {
		      printf("%s is invalid mnemonic\n",s1);
		      }
	    }
	    }
	}
      goto prev;
      }
	}
}
