#include<iostream>
struct node
{
	node* prev;
	int data;
	node*next;	
};
node *head=NULL;
node *head1=NULL;
node * getnode(int data)
{
	node *temp=new node();
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
void insertdata(int data)
{
	node *temp=getnode(data);
	if(head1==NULL)
	{
		head1=temp;
		head=temp;
		return;
	}
	temp->prev=head;
	head->next=temp;
	head=temp;
}

void print()
{
	node *temp=head1;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

void reverse()
{
	
	node *temp=head1;
	if(temp==NULL)return;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}
int main()
{
	int i,n,data;
	printf("enter no of values you want to enter :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter data : ");
		scanf("%d",&data);
		insertdata(data);
		printf("data is \n");
		print();
		printf("\nreverse of data is\n");
		reverse();
	}
}