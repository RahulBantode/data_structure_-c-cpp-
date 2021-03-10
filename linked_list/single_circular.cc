//Demonstration of singly circular linked list.....
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *next;
};

struct node *first;
struct node *last;

void create()
{
	struct node *temp;
	int val;
	
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data for node : ");
	scanf("%d",&val);
	
	temp->val = val;
	temp->next = NULL;
	
	if(first == NULL)
	{
		first = last = temp;
		first->next=first;
	}
	else
	{
		last->next = temp;
		last = temp;
		last->next = first;
	}
}

void insert_beg()
{
	struct node *temp;
	
	int val;
	
	temp = (struct node *)malloc(sizeof(struct node));
	
	printf("Enter the data for node : ");
	scanf("%d",&val);
	
	temp->val = val;
	temp->next = NULL;
	
	temp->next = first;
	first = temp;
	
}
void remove()
{
	struct node *ptr;
	
	if(first == NULL)
	{
		printf("\nNothing to delete list are empty\n");
	}
	else
	{
		ptr = first;
		first = ptr->next;
	
		int val = ptr->val;
		printf("\nDeleted value = %d\n",val);
	
		free(ptr);
	}
}

void remove_any()
{
	if(first == NULL)
	{
		printf("\nList are empty\n");
		return ;
	}
	struct node *cur , *prev;
	int val;
	
	printf("Enter the value which you want to delete..");
	scanf("%d",&val);
	
	while(first!=NULL && first->val == val)
	{
		remove();
	}
	
	prev = NULL;
	cur = first;
	
	while(cur != NULL)
	{
		if(cur->val == val)
		{
			if(prev != NULL)
			{
				prev->next = cur->next;
			}
			
			printf("The deleted node is = %d\n",cur->val);
			free(cur);
			return;
		}
		prev = cur;
		cur = cur->next;
	}
}

void display()
{
	struct node *ptr;
	
	ptr = first;
	if(first == NULL)
	{
		printf("\nNothing to show list are empty\n");
	}
	else
	{
		do
		{
			printf("%d -> ",ptr->val);
			ptr = ptr->next;
		}while(ptr != last->next);
		
		printf("\n");
	}
}

int main()
{
	int ch;
	
	do
	{
		printf("1.Create.....\n");
		printf("2.Remove.....\n");
		printf("3.Display....\n");
		printf("4.Insert_beg.\n");
		printf("5.Remove any.\n");
		printf("6.Exit.......\n");
		
		printf("\nEnter the choice\n");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1 : create(); break;
			
			case 2 : remove(); break;
			
			case 3 : display(); break;
			
			case 4 : insert_beg(); break;
			
			case 5 : remove_any(); break;
			
			case 6 : exit(0); break;
			
			default : printf("Enter valid selection....\n");
					  break;
					  	
		}
	}while(ch<=6);
	
}
