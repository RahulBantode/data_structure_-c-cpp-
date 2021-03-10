//double linked list.....

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *next,*prev; 
};

struct node *first,*last;

void create()
{
	struct node *temp;
	int val;
	
	temp = (struct node *)malloc(sizeof(struct node));
	
	printf("Enter the data for node : ");
	scanf("%d",&val);
	
	temp->val  = val;
	temp->next = NULL;
	temp->prev = NULL;
	
	if(first == NULL)
	{
		first = last = temp;
	}
	else
	{
		temp->prev = temp;
		last->next = temp->prev;
		last = temp;
	}
}

void remove()
{
	struct node *ptr;
	
	if(first == NULL)
	{
		printf("\nList are empty\n");
		return;
	}
//	if(first == last)
//	{
//		printf("The deleted node = %d\n",first->val /*last->val kahipn chalele becz ekach mem la point krtay*/);	
//		free(last);
//	}
	
	ptr = first;
	first = ptr->next->prev;
	first->prev = NULL;
	
	printf("The deleted node = %d\n",ptr->val);
	free(ptr);

}

void display()
{
	struct node *ptr;
	
	if(first == NULL)
	{
		printf("\nList are empty\n");
		return;
	}
	
	ptr = first;
	
	while(ptr != NULL)
	{
		printf("%d -> ",ptr->val);
		ptr = ptr->next;
	}
	
	printf("\n");
}

int main()
{
	int ch;
	
	do
	{
		printf("1.Create....\n");
		printf("2.Remove....\n");
		printf("3.Display...\n");
		printf("4.Exit......\n");
		printf("\nEnter your choice\n");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1 : create(); break;
			
			case 2 : remove(); break;
			
			case 3 : display(); break;
			
			case 4 : exit(0); break;
			
			default : printf("Please make valid selection..thank you\n"); break;
		}
		
	}while(ch<=4);

	return 0;
}
