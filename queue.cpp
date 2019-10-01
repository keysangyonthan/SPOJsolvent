#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node *next;
}*new,*front,*rear*temp;

int main()
{
	int i,value;
	for(i=0;i<5;i++)
	{
		enqueue();
	}
	temp=front;
	for(i=0;i<5;i++)
	{
		printf("%d",temp->data);
		temp= temp->next;
	}
	
	

	
}


enqueue()
	{
	new = (struct node *) malloc(size of(struct node))
	printf("enter elements");
	scanf("%d",&value);
	new->data = value;
	new->next = NULL;
	if(front==NULL)
	{
		front = new;
	
		rear = new ;
		
	}
	
	else
		
	{
		rear->next = new;
		rear = new;
	}
		
	dequeue()
	{
		temp = front;
		front = front->next;
		temp->next = NULL;
	}
