//doubly circular linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *next,*prev;
};

struct node *first,*last;
int cnt = 0;

void create()
{
	struct node *temp;
	int val;
	
	temp = (struct node *)malloc(sizeof(struct node));
	
	printf("Enter the data for node : ");
	scanf("%d",&val);
	
	temp->val = val;
	temp->next= NULL;
	temp->prev= NULL;
	
	if(first == NULL)
	{
		first = last = temp;
		first->prev=last;
		cnt++;
	}
	else
	{
		temp->prev = temp;
		last->next = temp->prev;
		last = temp;
		last->next = first;
		cnt++;
	}
}

void remove()
{
	struct node *ptr;
	
	if(first == NULL || last == NULL)
	{
		printf("\nThe List are empty\n");
		return;
	}
	
	ptr = first;
	first = ptr->next;
	first->prev=last;
	
	printf("\nThe deleted node are : %d\n",ptr->val);
	free(ptr);
	
}

void display()
{
	struct node *ptr;
	
	if(first == NULL)
	{
		printf("\nThe List are empty\n");
		return;
	}
	
	ptr = first;
	
	for(int i=1; i<=cnt; i++)
	{
		printf("%d -> ",ptr->val);
		ptr=ptr->next;
	}
	printf("\n");
}

int main()
{
	int ch;
	
	do
	{
		printf("1.Create...\n");
		printf("2.Remove...\n");
		printf("3.Display..\n");
		printf("4.Exit.....\n");
		printf("Enter Your Choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1 : create(); break;
			
			case 2 : remove(); break;
			
			case 3 : display(); break;
			
			case 4 : exit(0); break;
			
			default : printf("\nEnter the valid choice\n"); break;
		}
		
	}while(ch<=4);
	
	return 0;
}
