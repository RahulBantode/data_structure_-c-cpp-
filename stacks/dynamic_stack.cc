//dynamic implementation of stack.....

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next; //self refential pointer;
};

struct node *top;

void push()
{
	int data;
	struct node *temp;
	
	temp = (struct node *)malloc(sizeof(struct node));
	
	printf("Enter the data value for node ");
	scanf("%d",&data);
	
	temp->data = data;
	temp->next = NULL;
	
	if(top == NULL)
	{
		top = temp;	
	}	
	else
	{
		temp->next = top;
		top = temp;		
	}
	
}

void pop()
{
	struct node *ptr;
	
	if(top == NULL)
	{
		printf("\n Stack is empty\n");
		return;
	}
	
	ptr = top;
	top = top->next;
	
	printf("The deleted element from stack : %d\n",ptr->data);
	free(ptr);
		
}

void peek()
{
	if(top == NULL)
	{
		printf("\n Stack is empty\n");
		return ;
	}
	
	printf("The current top is : %d\n",top->data);
}

void display()
{
	if(top == NULL)
	{
		printf("\n Stack is empty\n");
		return ;
	}
	
	struct node *ptr; 
	ptr = top;
	
	printf("The stack list are : \t");
	while(ptr != NULL)
	{
		printf("%d\t",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int main()
{
	int ch;
	do
	{
		
		printf("1.PUSH....\n");
		printf("2.POP.....\n");
		printf("3.PEEK....\n");
		printf("4.Display.\n");
		printf("5.EXIT....\n");
		printf("\nEnter you Choice\n");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1 : push(); break;
			
			case 2 : pop(); break;
			
			case 3 : peek(); break;
			
			case 4 : display(); break;
			
			case 5 : exit(0); break;
			
			default: printf("\nplease make valid selection..thank you\n");
					 break;
		}
	}while(ch<=4);
	
	return 0;
}
