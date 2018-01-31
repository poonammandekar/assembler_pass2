#include"mylist.h"
#include<stdlib.h>
#include<stdio.h>
int insertBst(bst *b)
{
  return (_insertBst(&b->head));
}

int _insertBst(mnemonic **head)
{
mnemonic *temp,*newnode;
 int n,m,l,no;
char s1[10],s2[10],s3[10],str[1024];
FILE *fp;
 no=0;
fp=fopen("mnemonic","r");
while(!feof(fp))
{
strcpy(s1,"\0");
strcpy(s2,"\0");
strcpy(s3,"\0");
fgets(str,1024,fp);
sscanf(str,"%s%s%s",s1,s2,s3);
  newnode=(mnemonic *)malloc(sizeof(mnemonic));
  newnode->next=NULL;
  newnode->srno=no;
  no++;
if((strcmp(s1,"\0")!=0)&&(strcmp(s2,"\0")!=0)&&(strcmp(s3,"\0")!=0))
{
n=strlen(s1);
m=strlen(s2);
l=strlen(s3);
newnode->mname=(char *)malloc(n*sizeof(char));
  newnode->opcode=(char *)malloc(m*sizeof(char));
newnode->mode=(char *)malloc(l*sizeof(char));
strcpy(newnode->mname,s1);
strcpy(newnode->opcode,s3);
strcpy(newnode->mode,s2);
}
else
{
n=strlen(s1);
m=strlen(s2);
newnode->mname=(char *)malloc(n*sizeof(char));
  newnode->opcode=(char *)malloc(m*sizeof(char));
newnode->mode=(char *)malloc(sizeof(char));
strcpy(newnode->mname,s1);
strcpy(newnode->opcode,s2);
}
  if(*head==NULL)
    {
     *head=temp=newnode;
    }
  else
    {
	temp->next=newnode;
	newnode->next=NULL;
temp=newnode;
      }
 }

return 1;
}
