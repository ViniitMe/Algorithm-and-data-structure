#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void insert(struct node **head,int x)    //**head will have the address of head pointer whereas *head has the address of first node
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;

	temp->next=*head;
	*head=temp;
}


void append(struct node **head, int x )
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	struct node *last=*head;   //give last, the address of first node and traverse till we get last node
	while(last->next!=NULL)
	{
		last=last->next;
	}

	last->next=temp;
	temp->next=NULL;

}

void insert_after(struct node *prev, int x)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if (prev==NULL)
	{
		printf("add one more node ");
		return;
	}
	temp->data=x;
	temp->next=prev->next;
	prev->next=temp;
}

void delete(struct node **head,int num)
{
	struct node *prev,*temp;
	temp=*head;

	if(temp!=NULL && temp->data==num)
	{
		*head=temp->next;
		free(temp);
	}

	while(temp!=NULL && temp->data!=num)
	{
		prev=temp;  //as previous node is needed
		temp=temp->next;
	}

	if(temp==NULL)
		return;

	prev->next=temp->next;
	free(temp);

}

void printlist(struct node *head)
{
	while(head!=NULL)
	{

		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}


int main()
{
	int ch,x;
	struct node *head=NULL;

	printf("Functions:\n");
	printf("1-Insert a no. in the front of list\n");
	printf("2-Enter the no. in the nth position\n");
	printf("3-Enter the no. in the last\n");
	printf("4-Print the list\n");
	printf("5-Delete the node\n");
	printf("6-Exit\n");

	while(1)   //for running the loop infinitely until exit comes
	{
		printf("Enter your choice:");
		scanf("%d",& ch);

		switch(ch)
		{
			case 1:
			printf("Enter the data:");
			scanf("%d",& x);
			insert(&head,x);      //& head will point to the address of the head not 1st node
			break;

			case 2:
			printf("Enter the data:");
			scanf("%d",& x);
			insert_after(head->next,x);
			break;

			case 3:
			printf("Enter the data:");
			scanf("%d",& x);
			append(&head, x);
			break;

			case 4:
			printf("The list is:");
			printlist(head);
			break;

			case 5:
			printf("Enter the data you want to delete:");
			scanf("%d",&x);
			delete(&head, x);
			break;

			case 6:
			exit(0);
			break;

			default:
			printf("Wrong choice!!!\n");

		}
	
	}
	
}
