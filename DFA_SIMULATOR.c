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
	printf("👉Enter number of final State:\n");
	scanf("%d",&num);
	for(j=0;j<num;j++)
   {
     	printf("\n👉Enter %d name of Final state:\n",j+1);
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
     	printf("\n>> %s--->%d :  ",t->stateName,j);
		scanf("%s",st);
		if(j==0)
      t->a=findAddr(st);
		if(j==1)
      t->b=findAddr(st);


	  }
		t=t->next;
  	}



}

void display1()
{
char *sign;

     struct state *p;
	p=START;

   while(p!=NULL)
	{
          if(p->final==1)
          sign="+";
          else
          sign=" ";

		printf("\n%s%s --->%s(0)--->%s(1)\n",sign,p->stateName,p->a->stateName,p->b->stateName);
          p=p->next;

	 }

}

int main()
{
char ch[10];
int ch1[10],word[10];
int a,c=1,n,m,size,i,j,flage=1;
struct state *f;


printf("-->CAUTION: 😨😩\nplz read instruction carefully whatever is displaying and insert input in proper way.\nIf you are doing invailid activity u will never find your desire output ....Happy to coding MAn!!!\n\n ");
printf("-->Note : Assuring that You must have only two symbols in alphabet 0 and 1 ,and it's tackle out implicitly in this app.And u can take any no. of state and its name.\n\n");
printf("👉Enter number of state:\n ");
scanf("%d",&n);
for( i=0;i<n;i++)
{
	printf("👉Enter %d-state Name(Like-A,q0,state1...):\n",i+1);
	scanf("%s",&ch);

	insert(ch);

}



/*
printf("Enter number of alphbet:");
scanf("%d",&m);

for( i=0;i<m;i++)
{
	printf("Enter %d-Alphabet(Like-0,1):\n",i+1);
	scanf("%d",&ch1[i]);

}
*/

printf("\----Now going to construct Transition Table🚴🏃----\n");
printf("\n👉plz write same stateNames which have written by u already at above ,when required:\n");
transTable();
//display();
finalState();

printf("\-->Finally you've constructed transition table and it 's below👌\n\n\nTransition Table:");


display1();
while(flage)
{
printf("\n👉Enter size of string if u want to simulate :\n");
scanf("%d",&size);
printf("👉Enter string(*symbol seperated by space): \n");
for(i=0;i<size;i++)
scanf("%d",&word[i]);

printf("\n👉Your string is:\n");
for(i=0;i<size;i++)
printf("%d",word[i]);

f=START;

for(i=0;i<size;i++)
f=transition(word[i],f);

 if(f->final==1)
 printf("\nYepe,String accepted by this machine.well done Bro.👍\n");
 else
 printf("\nNope....Not accepted MaN👎. Try with another.\n");

printf("For Continue press 1 otherWise 0: ");
scanf("%d",&flage);
}
return 0;
}

