//static implementation of stack

#include<stdio.h>
#include<stdlib.h>

int stk[100];
int top,size_stack;

void push()
{
	int val;
	if(top >= size_stack - 1)
	{
		printf("\n Stack is overflow...\n");
		return;	
	}
	else
	{
		printf("\nEnter the element to pushed : ");
		scanf("%d",&val);
		top++;
		stk[top] = val;
	}
}

void pop()
{
	int var;
	if(top <= -1)
	{
		printf("\n Stack is underflow...\n");
		return ;
	}
	else
	{
		var = stk[top];
		printf("\nPopped element is : %d\n",var);
		top--;
	}
}

void peek()
{
	if(top <= -1)
	{
		printf("\nstack is underflow , top is missing\n");
	}
	else
	{
		printf("\nPeek of stack : %d\n",stk[top]);
	}
}

void display()
{
	if(top <= -1)
	{
		printf("\n stack is underflow,there is nothing to show..\n");
		return;
	}
	
	printf("stack list :\t");
	for(int i=top; i>=0; i--)
	{
		printf("%d\t",stk[i]);
	}
	printf("\n");
}

int main()
{
	top = -1;	
	printf("Enter the size of stack (between 1 to 100) = ");
	scanf("%d",&size_stack);
	
	int ch;
	do
	{
		printf("\n");
		printf("1.PUSH...\n");
		printf("2.POP....\n");
		printf("3.PEEK...\n");
		printf("4.Display\n");
		printf("5.Exit...\n");
		printf("\nEnter your choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1 : push(); break;
			
			case 2 : pop(); break;
			
			case 3 : peek(); break;
			
			case 4 : display(); break;
			
			case 5 : exit(0); break;
			
			default : printf("\nplease make valid selection\n");
					  break;
					  
		}
	}while(ch<=5);
	
	return 0;
}
