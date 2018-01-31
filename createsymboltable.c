
#include"mylist.h"
#include<stdlib.h>
#include<stdio.h>
int createsymtab(symtab *head1,mnemonic *head)
{
  FILE *fp;
  symtab *temp,*newnode,*temp2;
  char str[1024],sname[10],tp[10],s1[10],s2[10],s3[10],value1[100];
  int i,x,n,k,a,b,c,ans,z,add,count,v,flag;
  n=0;
  add=0;
  v=0;
  printf("-----------------------------------------------Symbol Table--------------------------------------------\n"); 
  fp=fopen("intermediate","r"); 
      fgets(str,1024,fp);
      if(strcmp(str,"section .data\n")==0)
	{
    next:
	  i=0;
	  fgets(str,1024,fp);
	  count=0;
	  if(feof(fp))
	    {
	      goto end;
	    }
	  if((strcmp(str,"section .bss\n")==0)||(strcmp(str,"section .text\n")==0))
	{
	  goto end;
	}
	else
	  {
	    newnode=(symtab *)malloc(sizeof(symtab));
	    newnode->next=NULL;
	    i=0;
	     x=0;
	    while(str[i]==' ' || str[i]=='\t')
	      {
		i++;
	      }
	    while(str[i]!=' ')
	      {
		sname[x]=str[i];
		i++;
		x++;
	      }
	    sname[x]='\0';
	    if(n==0)
	      {
		newnode->size=0;
	      }
	    else
	      {
		newnode->size=add;
	      }
	    ans=validatesymbol(head1,sname);
	    if(ans==1)
	    {
	    k=strlen(sname);
	    newnode->symname=(char *)malloc(k*sizeof(char));
	    strcpy(newnode->symname,sname);
	    newnode->srno=n;
	    newnode->status='D';
	    newnode->section='D';
	     n++;
	    x=0;
	     while(str[i]==' ')
	      {
		i++;
	      }
	    while(str[i]!=' ')
	      {
		tp[x]=str[i];
		i++;
		x++;
	      }

	    tp[x]='\0';
	    k=strlen(tp);
            newnode->dtype=(char *)malloc(k*sizeof(char));
	    strcpy(newnode->dtype,tp);
      
	     while(str[i]==' ')
	      {
		i++;
	      }
	    if(str[i]=='"')
	      {
		i++;
		x=0;
		while(str[i]!='"')
		  {
		    value1[x]=str[i];
		    i++;
		    x++;
		     add++;
		  }
		while(str[i]!='\0')
		  {
		if(str[i]=='1')
		  {
		    i++;
		    if(str[i]=='0')
		      {
			add++;
			i++;
			if(str[i]==',')
			  {
			    i++;
			    if(str[i]='0')
			      add++;
			  }
			
		      }
		  }
		else
		  i++;
		  }
		value1[x]='\0';
	      }
	    else
	      {
		x=0;
		while(str[i]!='\0')
		  {
		    if(str[i]==',')
		      {
			count++;
			}
		    value1[x]=str[i];
		    i++;
		    x++;
		  }
		count++;
		value1[x]='\0';
		}
	    c=strlen(value1);
	    newnode->value=(char *)malloc(c*sizeof(char));
	    strcpy(newnode->value,value1);
	   
	    if(strcmp(newnode->dtype,"dd")==0)
	      {
		add=(add + (count*4));
	      }
	    else if(strcmp(newnode->dtype,"dw")==0)
	      {
		add=(add + (count*2));
		}
	      
	     
	    if(head1==NULL)
	      {
		temp=head1=newnode;
	      }
	    else
	      {
		temp->next=newnode;
		temp=newnode;
	      }
	    goto next;
	     }
	    else
	    goto next;
	}
	}
      
 end:

      if((strcmp(str,"section .bss\n")==0))
	{
	  flag=0;
	aa:
	  fgets(str,1024,fp);
      if(feof(fp))
	{
	  goto end1;
	}
      else if(strcmp(str,"section .text\n")!=0)
	{
	  strcpy(s1,"\0");
	  strcpy(s2,"\0");
	  strcpy(s3,"\0");
	  sscanf(str,"%s%s%s",s1,s2,s3);
	  a=strlen(s1);
	   ans=validatesymbol(head1,s1);
	  if(ans==1)
	  {
	  b=strlen(s2);
	  c=strlen(s3);
	  newnode=(symtab *)malloc(sizeof(symtab));
          newnode->next=NULL;
	  newnode->symname=(char *)malloc(a*sizeof(char));
	  newnode->dtype=(char *)malloc(b*sizeof(char));
	  newnode->value=(char *)malloc(c*sizeof(char));
	  strcpy(newnode->symname,s1);
	  strcpy(newnode->dtype,s2);
	  strcpy(newnode->value,s3);
	  z=atoi(newnode->value);
	  if(flag==0)
	    {
	      newnode->size=0;
	      flag=1;
	    }
	  else
	    {
	      newnode->size=v;
	    }
	  if(strcmp(newnode->dtype,"resb")==0)
	    {
	      v=v+z;
	    }
	  else if(strcmp(newnode->dtype,"resw")==0)
		 {
		   v=(v+(z*2));
		 }
	  else if(strcmp(newnode->dtype,"resd")==0)
	    {
	      v=(v+(z*4));
	      }
	  newnode->status='U';
	  newnode->srno=n;
	  newnode->section='B';
	  n++;
	  for(temp=head1;temp->next!=NULL;temp=temp->next);
	  temp->next=newnode;
	  temp=newnode;
	  goto aa;
	  }
	  else
	  goto aa;
	}
	}
	end1:

      if(strcmp(str,"section .text\n")==0)
	{
	ss:
	  strcpy(s1,"\0");
          strcpy(s2,"\0");
          strcpy(s3,"\0");
	  fgets(str,1024,fp);
	  if(feof(fp))
	    {
	      goto end2;
	    }
	  else
	    {
	  sscanf(str,"%s%s%s",s1,s2,s3);
	  a=strlen(s1);
	 ans= validatesymbol(head1,s1);
	  if(ans==1)
	  {
	  if(s1[a-1]==':')
	    {
	      s1[a-1]='\0';
	      newnode=(symtab *)malloc(sizeof(symtab));
	  newnode->symname=(char *)malloc(a*sizeof(char));
	  newnode->dtype=(char *)malloc(5*sizeof(char));
	  strcpy(newnode->symname,s1);
          strcpy(newnode->dtype,"label");
	  newnode->next=NULL;
	  newnode->status='D';
          newnode->srno=n;
	  newnode->section='C';
	  newnode->size=0;
	   b=strlen("-");
	  newnode->value=(char *)malloc(b*sizeof(char));
	  strcpy(newnode->value,"-");
          n++;
	  for(temp=head1;temp->next!=NULL;temp=temp->next);
          temp->next=newnode;
          temp=newnode;
	  goto ss;
	    }
	  else goto ss;
	  }
	  else
	  goto ss;
	    }
	}
 end2:
      printf("sr No.\t\tName\t\ttype\t\tsection\t\tstatus\t\taddress\t\tvalue\n");
      printf("--------------------------------------------------------------------------------------------------\n");
       for(temp=head1;temp!=NULL;temp=temp->next)
        {
          printf("%d\t\t%s\t\t%s\t\t%c\t\t%c\t\t%d\t\t%s \n",temp->srno,temp->symname,temp->dtype,temp->section,temp->status,temp->size,temp->value);
	  }
       printf("-------------------------------------Error Table-------------------------------------------\n");
       printf("-------------------------------------------------------------------------------------------\n");
       invalidsymbol(head1,head);
intermediate(head1,head);
      return 0;
	
}
