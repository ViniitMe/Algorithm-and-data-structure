#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void insert(struct node **head, int x)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;

	temp->next=*head;
	*head=temp;
}

int node(struct node **head,int x)
{
	struct node *temp=*head;
	int count=0;

	while(temp->data!=x)
	{
		temp=temp->next;
		count=count+1;
	}

	return count;
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
	struct node *head=NULL;
	int x,ch,n;
	printf("Your choices:");
	printf("\n1)List Entry");
	printf("\n2)Print the list");
	printf("\n3)Find the nth node position");
	printf("\n4)Exit");

	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
	       {

		      	case 1:
		      	printf("Enter the no. in the list:");
		      	scanf("%d",&x);
		      	insert(&head,x);
		      	break;

		      	case 2:
				printf("The linked list is:");
				printlist(head);
				break;

				case 3:
				printf("Enter the data whose index is to find:");
				scanf("%d",&x);
				int b=node(&head,x);
				printf("The index of the node is:%d",b);
				break;

				case 4:
				exit(0);
				break;

				default:
				printf("Incorrect option chosen!!!\n");

			}
	}
	

}