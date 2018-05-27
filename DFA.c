#include<stdio.h>
#include<string.h>

#include<stdlib.h>

struct state
{
	char stateName[10];
	int final;
     struct state *a;
	struct state *b;
	struct state *next;

};
typedef struct state *ptr;
ptr START=NULL;
ptr  getNode()
{
	struct state *p;
	p=(struct state*) malloc(sizeof(struct state));
	return(p);

}

void insert(char *a)
{
	struct state *temp,*str;
	temp=getNode();
	strcpy(temp->stateName,a);
	temp->final=0;
	temp->a=NULL;
	temp->b=NULL;
	temp->next=NULL;
	if(START==NULL)
	START=temp;
	else
	{
     	str=START;
		while(str->next!=NULL)
		{
     		str=str->next;
		}
          str->next=temp;

	}

}
struct state* transition(int a,struct state *p)
{
	if(a==0) {

   return (p->a);           }
	if(a==1)                  {

	return (p->b);           }
}
struct state* findAddr(char *a)
{
   struct state *p=START;
   while(p!=NULL)
	{
		if(strcmp(p->stateName,a)==0)
		{

			return (p);
		}

		p=p->next;
	}
   return NULL;
}
void finalState()
{
	char st[10];
	int num,j;
   struct state *t;
	printf("Enter number of final State:");
	scanf("%d",&num);
	for( j=0;j<num;j++)
   {
     	printf("\n Enter %d name of Final state:",j+1);
		scanf("%s",st);
      t=findAddr(st);
		if(t!=NULL)
		t->final=1;

	}

}
void transTable()
{
	char st[10];
     int j;
	struct state *t,*t1;
	t=START;
	while(t!=NULL)
	{
	  for( j=0;j<2;j++)
	  {
     	printf("\n%s--->%d :",t->stateName,j);
		scanf("%s",st);
		if(j==0)
      t->a=findAddr(st);
		if(j==1)
      t->b=findAddr(st);


	  }
		t=t->next;
  	}



}/*
void display()
{
     struct state *p;
	p=START;
	if(p==NULL)
	printf("linklist is empty!!!\n");
	else
	{
     while(p!=NULL)
	{
		printf("%s   \n",p->stateName);
          p=p->next;

	 }
	}
}
void display1()
{

     struct state *p;
	p=START;

   while(p!=NULL)
	{
		printf("\n(a)%s,%d   (b)%s\n",p->a->stateName,p->final,p->b->stateName);
          p=p->next;

	 }

}*/

int main()
{
char ch[10];
int ch1[10],word[10];
int a,c=1,n,m,size,i,j;
struct state *f;




printf("Enter number of state:");
scanf("%d",&n);
for( i=0;i<n;i++)
{
	printf("Enter %d-state Name(Like-A,B,C...):\n",i+1);
	scanf("%s",ch);
	insert(ch);

}
printf("Enter number of alphbet:");
scanf("%d",&m);

for( i=0;i<m;i++)
{
	printf("Enter %d-Alphabet(Like-0,1):\n",i+1);
	scanf("%d",&ch1[i]);

}


printf("\nNow we are going to construct transition table :\n");
transTable();
display();
finalState();
display1();

printf("\nEnter size of string if u want to simulate :");
scanf("%d",&size);
printf("Enter string: ");
for(i=0;i<size;i++)
scanf("%d",&word[i]);

printf("\nYour string is:");
for(i=0;i<size;i++)
printf("%d",word[i]);

f=START;

for(i=0;i<size;i++)
f=transition(word[i],f);

 if(f->final==1)
 printf("\nString accepted by this machine.....well done");
 else
 printf("\nNope....Not accepted MaN");

return 0;

}
