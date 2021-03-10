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
	
	printf("Enter the value = ");
	scanf("%d",&val);
	
	temp->val = val;
	temp->next= NULL;
	
	if(first == NULL)
	{
		first = last = temp;
	}
	else
	{
		last->next = temp;
		last = temp;
	}
	
}

void insert()
{
	struct node *temp;
	int val;
	printf("Enter the value : ");
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
		printf("The list are empty....\n");
	}
	
	ptr = first;
	first = ptr->next;
	
	int val = ptr->val;
	free(ptr);
	printf("The removed item = %d\n",val);
	
}

void show()
{
	struct node *ptr;
	
	if(first == NULL)
	{
		printf("Unable to show list are empty...\n");	
	}	
	
	ptr = first;
	printf("\nThe linked list are....\n");
	
	while(ptr != NULL)
	{
		printf("%d\t",ptr->val);
		ptr = ptr->next;	
	}
	printf("\n\n");
}

int main()
{
	int ch;
	do
	{
		printf("1.create\n");
		printf("2.insert\n");
		printf("3.remove\n");
		printf("4.show\n");
		printf("5.exit\n");
		printf("Enter the choice...\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1 : create();
					 break;
			
			case 2 : insert();
					 break;
			
			case 3 : remove();
					 break;
					 
			case 4 : show();
					 break;
			
			case 5 : exit(0);
					 
			default : printf("Please select valid choice....");
					  break;
			 	
		}
	}while(ch<=5);

	return 0;
}
