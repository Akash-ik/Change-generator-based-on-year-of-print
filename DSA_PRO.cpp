#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <unistd.h>

struct note
{
	int d;
	int yr;
	struct note* next;
};

struct note *f1=NULL,*r1=NULL;
struct note *f2=NULL,*r2=NULL;
struct note *f5=NULL,*r5=NULL;
struct note *f10=NULL,*r10=NULL;
struct note *f20=NULL,*r20=NULL;
struct note *f50=NULL,*r50=NULL;
struct note *f100=NULL,*r100=NULL;
struct note *f200=NULL,*r200=NULL;
struct note *f500=NULL,*r500=NULL;
struct note *f2k=NULL,*r2k=NULL;

int del(int d)
{
	struct note* f;
	int ret;
	switch(d)
	{
		case 1:
			f=f1;break;
		case 2:
			f=f2;break;
		case 5:
			f=f5;break;
		case 10:
			f=f10;break;
		case 20:
			f=f20;break;
		case 50:
			f=f50;break;
		case 100:
			f=f100;break;
		case 200:
			f=f200;break;
		case 500:
			f=f500;break;
		case 2000:
			f=f2k;break;
	} 
	struct note*temp =f;
	if(temp==NULL)
	return 0;
	
	if(temp->next==NULL)
	{
		printf("DELETED %d:%d\n",temp->d,temp->yr);
		ret=temp->d;
		free(temp);
		f=NULL;
			switch(d)
	{
		case 1:
			f1=f;break;
		case 2:
			f2=f;break;
		case 5:
			f5=f;break;
		case 10:
			f10=f;break;
		case 20:
			f20=f;break;
		case 50:
			f50=f;break;
		case 100:
			f100=f;break;
		case 200:
			f200=f;break;
		case 500:
			f500=f;break;
		case 2000:
			f2k=f;break;
	}
		return ret;
	}
	int max=-1;
	int flag=0;
	while(temp!=NULL)
	{
		if(temp->yr > max)
			max=temp->yr;
		temp=temp->next;	
	}
	temp=f;
	struct note *temp2=temp;
	while(temp!=NULL)
	{
		if(temp->yr == max)
			{
			temp2->next=temp->next;
			flag=1;
			printf("NOTE:%d  YEAR:%d\n",temp->d,temp->yr);
			ret=temp->d;
			free(temp);
			break;
			}
		temp2=temp;
		temp=temp->next;
	}
	
	return ret;	
}


void disp(int d)
{
	
	struct note*f;
	switch(d)
	{
		case 1:
			f=f1;break;
		case 2:
			f=f2;break;
		case 5:
			f=f5;break;
		case 10:
			f=f10;break;
		case 20:
			f=f20;break;
		case 50:
			f=f50;break;
		case 100:
			f=f100;break;
		case 200:
			f=f200;break;
		case 500:
			f=f500;break;
		case 2000:
			f=f2k;break;
	}
	struct note *temp=f;
	printf("\n");
	
	while(temp!=NULL)
	{
		printf("%d\n",temp->yr);
		temp=temp->next;
	}
}

void greedy(int amt)
{
	int a,i,x=0;
	int deno[]={1,2,5,10,20,50,100,200,500,2000};
	int n=10;
	a=0;
	while(a!=amt)
	{
		for(i=n-1;i>=0;i--)
		{
			if(a+deno[i]<=amt && amt>=deno[i])
			{
			x=x+del(deno[i]);
			a=a+deno[i];
			break;
			}
		}
	}
	if(x==amt)
		printf("\nChange was generated");
	else
		printf("\nChange was not generated");
}


void rc(int a)
{
	int x=0;
if(a==1)
	{
	x=del(1);
	}
else if (a==2)
	{
	x=x+del(1);
	x=x+del(1);
	}
else if(a==5)
	{
		x=x+del(1);
		x=x+del(1);
		x=x+del(1);
	}
else if(a==10)
{
		x=x+del(1);
		x=x+del(1);
		x=x+del(1);
		x=x+del(2);
		x=x+del(5);
	}	
else if(a==20)
{
	x=x+del(1);
		x=x+del(1);
		x=x+del(1);
		x=x+del(2);
		x=x+del(5);
		x=x+del(10);
}
else if(a==50)
{
	x=x+del(1);
		x=x+del(1);
		x=x+del(1);
		x=x+del(2);
		x=x+del(5);
		x=x+del(10);
		x=x+del(10);
		x=x+del(20);
}
else if (a==100)
{
	x=x+del(1);
		x=x+del(1);
		x=x+del(1);
		x=x+del(2);
		x=x+del(5);
		x=x+del(10);
		x=x+del(10);
		x=x+del(20);
		x=x+del(50);
}
else if(a==200)
{
	x=x+del(1);
		x=x+del(1);
		x=x+del(1);
		x=x+del(2);
		x=x+del(5);
		x=x+del(10);
		x=x+del(10);
		x=x+del(20);
		x=x+del(50);
		x=x+del(100);
}
else if (a==500)
{
	x=x+del(1);
		x=x+del(1);
		x=x+del(1);
		x=x+del(2);
		x=x+del(5);
		x=x+del(10);
		x=x+del(10);
		x=x+del(20);
		x=x+del(50);
		x=x+del(100);
		x=x+del(100);
		x=x+del(200);
}
else if (a==2000)
{
	x=x+del(1);
		x=x+del(1);
		x=x+del(1);
		x=x+del(2);
		x=x+del(5);
		x=x+del(10);
		x=x+del(10);
		x=x+del(20);
		x=x+del(50);
		x=x+del(100);
		x=x+del(100);
		x=x+del(200);
		x=x+del(500);
		x=x+del(500);
		x=x+del(500);
}
if(x==a)
printf("\nChange generation was successful");
else
printf("\nChange generation was not successful");
}

void insert(int d, int yr)
{
	struct note *np=(struct note*)malloc(sizeof(struct note));
	np->d=d;
	np->yr=yr;
	np->next=NULL;
	struct note *f,*r;
	
	switch(d)
	{
		case 1:
			f=f1;r=r1;break;
		case 2:
			f=f2;r=r2;break;
		case 5:
			f=f5;r=r5;break;
		case 10:
			f=f10;r=r10;break;
		case 20:
			f=f20;r=r20;break;
		case 50:
			f=f50;r=r50;break;
		case 100:
			f=f100;	r=r100;break;
		case 200:
			f=f200;r=r200;break;
		case 500:
			f=f500;r=r500;break;
		case 2000:
			f=f2k;r=r2k;break;
	}
	
	if(f==NULL)
		{
		f=r=np;
		}
	else
	{
		r->next=np;
		r=np;
	}
	switch(d)
	{
		case 1:
			f1=f;r1=r;break;
		case 2:
			f2=f;r2=r;break;
		case 5:
			f5=f;r5=r;break;
		case 10:
			f10=f;r10=r;break;
		case 20:
			f20=f;r20=r;break;
		case 50:
			f50=f;r50=r;break;
		case 100:
			f100=f;r100=r;break;
		case 200:
			f200=f;r200=r;break;
		case 500:
			f500=f;r500=r;break;
		case 2000:
			f2k=f;r2k=r;break;
	}
}


int main()
{
	int opt,pin=666,x,opt1,d,yr,a,i,change,a1,y1;
	int arr[100],arry[100];
	int deno[]={1,2,5,10,20,50,100,200,500,2000};
	for(int i=0;i<20;i++)
						{
							x=2000+rand()%19;
							insert(1,x);
							insert(2,x);
							insert(5,x);
							insert(10,x);
							insert(20,x);
							insert(50,x);
							insert(100,x);
							insert(200,x);
							insert(500,x);
							insert(2000,x);
						}
	do{
	printf("\n\t\t\t\t\tCHANGE GENERATION MACHINE\n");
	printf("\t\t\t\t\t------ ---------- -------\n");
	printf("1.GET CHANGE WITH MINIMUM NOTES\n2.GET RANDOM CHANGE\n3.REQUEST SPECIFIC CHANGE\n4.ADMIN LOGIN\n5.EXIT\n\nENTER OPTION:");
	scanf("%d",&opt);
	switch(opt)
	{
		
			case 1:
			printf("Enter the note that you will give:");
		  	scanf("%d",&a1);
		  	printf("Enter the year of the note:");
		  	scanf("%d",&y1);
		 	printf("Enter the change that you want:");
		  	scanf("%d",&change);
		  	if(change>a1)
		    	printf("\nEntered amount is greater than the given amount:");
		  	else if (a1==2 || a1==5 || a1==10 || a1==20 || a1==50 ||a1==100 || a1==200 || a1==500 || a1 ==2000)
		    {
		      insert(a1,y1);
			  printf("\nChange 1:\n");
			  greedy(change);
			  printf("\nChange 2:\n");
			  greedy(a1-change);
			  }
			else
			printf("\nThe Entered note does not exist");
			break;
		case 2:
			printf("\nEnter the note that you want to give:");
			scanf("%d",&a1);
			printf("\nEnter the year of print:");
			scanf("%d",&y1);
			insert(a1,y1);
			rc(a1);
			break;
		case 3:
			printf("\nEnter the note that you want to give:");
			scanf("%d",&a1);
			printf("\nEnter the year of print:");
			scanf("%d",&y1);
			i=0;
			x=0;
			while(x<a1)
			{
			printf("Enter the notes that you want:");
			scanf("%d",&arr[i]);
			x=x+arr[i];
			i++;
			}
			insert(a1,y1);
			for (int j=0;j<i;j++)
			{
				del(arr[j]);
			}
		  	break;
		case 4:
			printf("\nEnter pin:");
			scanf("%d",&x);
			if(x==pin)
			{
				do{
				
				printf("\nADMIN OPTIONS \n1.QUEUE STATUS\n2.REFILL QUEUE\n3.EXIT\nENTER OPTION:");
				scanf("%d",&opt1);
				switch(opt1)
				{
					case 1:
						printf("Enter the denomination to check:");
						scanf("%d",&a);
						disp(a);
						break;
					case 2:
						for(i=0;i<20;i++)
						{
							x=2000+rand()%19;
							insert(1,x);
							insert(2,x);
							insert(5,x);
							insert(10,x);
							insert(20,x);
							insert(50,x);
							insert(100,x);
							insert(200,x);
							insert(500,x);
							insert(2000,x);
						}
						break;
					default:
						printf("INVALID OPTION");
				}
				}while(opt1!=3);
			}
			else
			{
				printf("INCORRECT PASSWORD\n");
			}
			break;
		}
	}while(opt!=5);
}


