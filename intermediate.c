#include"mylist.h"
#include<stdlib.h>
#include<stdio.h>
int intermediate(symtab *head1,mnemonic *head)
{
  FILE *fp;
  char str[1024],s1[10],s2[10],s3[10],s4[10],op1[10],op2[10],sym[20];
  mnemonic *temp1,*temp;
  symtab *temp2;
  int flag,x,i,c,j,flag1,z;
  char mm[8][8]={"eax","ebx","ecx","edx","esi","edi","ebp","esp"};
  printf("-------------------------------------------------------Register Table---------------------------------------\n");
  printf("srno\tRegister\n");
  for(i=0;i<8;i++)
    {
      printf("%d\t%s\n",i,mm[i]);
    }
  printf("-----------------------------------------------intermediate code is--------------------------------------------------\n");
  fp=fopen("intermediate","r"); 
  while(!feof(fp))
    {
      strcpy(s1,"\0");
      strcpy(s2,"\0");
      strcpy(s3,"\0");
      strcpy(s4,"\0");
      fgets(str,1024,fp);
      sscanf(str,"%s%s%s%s",s1,s2,s3,s4);
      if(strcmp(s1,"main:")==0)
	{
	  ss:
	  strcpy(s1,"\0");
	  strcpy(s2,"\0");
	  strcpy(s3,"\0");
	  strcpy(s4,"\0");
	  flag=0;
	  flag1=0;
	  fgets(str,1024,fp);
	  
	  if(feof(fp))
	    {
printf("---------------------------------------------opcode table------------------------------------------------------\n");
for(temp=head;temp!=NULL;temp=temp->next)
{
  fprintf(stdout,"%d\t%s\t%s\t%s\n",temp->srno,temp->mname,temp->opcode,temp->mode);
}
	      return 0;
	    }

	  else
	    {
	  sscanf(str,"%s%s%s%s",s1,s2,s3,s4);
	  i=0;
	  if((strcmp(s1,"mul")==0)||(strcmp(s1,"div")==0)||(strcmp(s1,"inc")==0)||(strcmp(s1,"dec")==0)||(strcmp(s1,"jmp")==0)||(strcmp(s1,"je")==0)||(strcmp(s1,"jz")==0)||(strcmp(s1,"jl")==0)||(strcmp(s1,"jg")==0)||(strcmp(s1,"jge")==0)||(strcmp(s1,"jle")==0)||(strcmp(s1,"call")==0)||(strcmp(s1,"push")==0)||(strcmp(s1,"pop")==0)||(strcmp(s1,"ret")==0)||(strcmp(s1,"neg")==0)||(strcmp(s1,"not")==0))
	    {
	      if(strcmp(s1,"ret")==0)
		{
		  for(temp1=head;temp1!=NULL;temp1=temp1->next)
		    {

		      if(strcmp(s1,temp1->mname)==0)
			{
			  printf("mnemonic=%s#%d\n",temp1->mname,temp1->srno);
			  break;
			}
		    }

		}
	      else if(strcmp(s1,"jmp")==0)
		{
		  {
		    for(temp1=head;temp1!=NULL;temp1=temp1->next)
		      {

			if(strcmp(s1,temp1->mname)==0)
			  {
			    printf("mnemonic=%s#%d\t",temp1->mname,temp1->srno);
			    break;
			  }
		      }
		    for(temp2=head1;temp2!=NULL;temp2=temp2->next)
		      {
			if(strcmp(s2,temp2->symname)==0)
                          {
                            printf("label=%s#%d\n",temp2->symname,temp2->srno);
                            break;
                          }

		      }

		}
	    }
	    }
	  else
	    {
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
	  for(temp1=head;temp1!=NULL;temp1=temp1->next)
	    {

	      if(strcmp(s1,temp1->mname)==0)
		{
		  flag=1;
		  break;
		}
	    }
	  printf("mnemonic=%s#%d\t",temp1->mname,temp1->srno);
	    }
	 
	  i=0;
	      flag1=0;
	      x=0;
	      while(s2[i]!=',')
		{
		  op1[x]=s2[i];
		  i++;
		  x++;
		}
	      op1[x]='\0';
	      printf("op1=%s",op1);
	      for(j=0;j<8;j++)
		{
		  if(strcmp(op1,mm[j])==0)
		    {
		      printf("#%d\t",j);
		      flag1=1;
		      break;
		    }
		}
	      if(flag1==0)
		{
		  z=0;
		  x=0;
		  while(op1[x]!='[')
		    {
		      x++;
		    }
		  x++;
		  while(op1[x]!=']')
		    {
		      sym[z]=op1[x];
		      x++;
		      z++;
		    }
		  sym[z]='\0';
		 		  for(temp2=head1;temp2!=NULL;temp2=temp2->next)
                    {

                      if(strcmp(sym,temp2->symname)==0)
                        {
                          printf("#%d\t",temp2->srno);
                          break;
                        }
                    }

		}
	      x=0;
	      i++;
              while(s2[i]!='\0')
		{
                  op2[x]=s2[i];
                  i++;
                  x++;
                }
              op2[x]='\0';
	      printf("op2=%s",op2);
	      flag1=0;
	      for(j=0;j<8;j++)
                {
                  if(strcmp(op2,mm[j])==0)
                    {
                      printf("#%d\t",j);
                      flag1=1;
                      break;
                    }
                }
	      if(flag1==0)
		{
                  z=0;
                  x=0;
                  while(op2[x]!='[')
                    {
                      x++;
                    }
                  x++;
                  while(op2[x]!=']')
                    {
                      sym[z]=op2[x];
                      x++;
                      z++;
                    }
		  sym[z]='\0';
		  for(temp2=head1;temp2!=NULL;temp2=temp2->next)
		    {

		      if(strcmp(sym,temp2->symname)==0)
			{
			  printf("#%d\t",temp2->srno);
			  break;
			}
		    }
		}
	    }
	    }
	  printf("\n");
	  goto ss;
	    
	}
    }
}

