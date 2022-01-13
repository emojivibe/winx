#include<stdio.h>
#include<stdlib.h>
void create();
void traverse();
int length();
void rev_list();
void node_swap();
void search();
struct node{
 
    int info;
    struct node *next;
};
 
struct node *start=NULL;
 int main()
 {
 int op;
 do
 {
 printf("\n1. creating a linked list ");
 printf("\n2. counting number of nodes in a linked list ");
 printf("\n3. reversing the linked list ");
 printf("\n4. swapping of two nodes ");	
 printf("\n5. swapping of two nodes ");
 printf("\n6. traverse ");
 printf("\n7. exit ");
 printf("\n\t\tenter your choice ");
 scanf("%d",&op);
 switch(op)
 {
 	case 1:
				{
					create();
					break;
					
				}
				case 2:
					{
	printf("\nnumber of nodes in a linked list:%d",length());					
						break;
					}
					case 3:
					{
						rev_list();
						break;
					}
					case 4:
					{
						node_swap();
						break;
					}
					case 5:
						{
							search();
							break;
						}
						case 6:
							{
								traverse();
								break;
							}
							case 7:
							{
							exit(0);
							}
						default:
							printf("you have entered a wrong choice");
							
		}
	}while(1);
}
void create()
{
	struct node *temp,*ptr;
	int i,n;
	printf("how many nodes do you want to create=");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		if(temp==NULL)
		{
			printf("memory overflow");
			exit(0);
			
		}
		printf("enter the data value for the node %d=",i);
		scanf("%d",&temp->info);
		temp->next=NULL;
		if(start==NULL)
		start=temp;
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			ptr=ptr->next;
			ptr->next=temp;
			
		}
	}
}
int length()
{
	int count =0;
	struct node *temp;
	temp=start;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
void rev_list()
{
	struct node *prev,*cur;
	printf("\noriginal list:");
	traverse();
	if(start!=NULL)
	{
		prev=start;
		cur=start->next;
		start=start->next;
		prev->next=NULL;
		while(start!=NULL)
		{
			start=start->next;
			cur->next=prev;
			prev=cur;
			cur=start;
		}
		start=prev;
	}
	printf("\nreversed list:");
	traverse();
}
void node_swap()
{
	struct node *p=start,*q=start,*r=start;
	int i,loc;
	printf("\nbefore swapping:");
	traverse();
	printf("\nenter location of node to swap=");
	scanf("%d",&loc);
	for(i=1;i<loc-1;i++)
	p=p->next;
	for(i=1;i<loc;i++)
	q=q->next;
	for(i=1;i<loc+1;i++)
	r=r->next;
	q->next=r->next;
	r->next=q;
	p->next=r;
	printf("\nafter swapping:");
	traverse();
	
}
void search()
{
	struct node *temp=start;
	int key,flag=0,count=0;
	printf("\nenter the data value to be searched=");
	scanf("%d",&key);
	while(temp!=NULL)
	{
		count++;
		if(temp->info==key)
		{
			flag=1;
			break;
		}
		temp=temp->next;
	}
	if(flag==1)
	printf("\nsearch successful,element found at %d",count);
	else
	printf("\nsearcg unsuccessful");
	
}
void traverse()
{
	struct node *ptr;
	if(start==NULL)
	printf("list is empty\n");
	else
	{
		ptr=start;
		while(ptr!=NULL)
		{
			printf("\t%d",ptr->info);
			ptr=ptr->next;
		}
	}
}
 
 
 
 
 
 
 
 
 

