#include<stdio.h>
#include<stdlib.h>

struct student
{
	char *name;
	char *roll;
	float cgpa;
	float sgpa;
};

struct node
{
	struct student s;
	struct node *next;
};

void insert(struct node **head)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));

	/**char *rl;
	printf("Enter the ROll No.:");
	scanf("%s",rl);
	temp->s.roll=rl;**/

	char *nm = (char *)malloc(sizeof(char)*20);

	printf("Enter the Name:");
	scanf("%s",nm);
	temp->s.name=nm;

	float cg;
	printf("Enter the CGPA:");
	scanf("%f",& cg );
	temp->s.cgpa=cg;

	float sg;
	printf("Enter the SGPA:");
	scanf("%f",& sg);
	temp->s.sgpa=sg;

	temp->next=*head;
	*head=temp;
}

void printlist(struct node *head)
{
	while(head!=NULL)
	{
		printf("[%s, %f, %f]\n",head->s.name,head->s.cgpa,head->s.sgpa);
		head=head->next;
	}
	printf("\n");
}


int main()
{
	struct node *head=NULL;
	int ch;
	printf("Operations:\n");
	printf("1) Enter student information\n");
	printf("2) Find max\n");
	printf("3) Print list\n");
	printf("3) Exit\n");

	while(1)
	{
		printf("Enter your choice:");
		scanf("%d",& ch);

		switch(ch)
		{
			case 1:
			insert(&head);
			break;

			case 2:
			//max();
			break;

			case 3:
			printlist(head);
			break;

			case 4:
			exit(0);
			break;

			default:
			printf("Wrong choice!!!\n");
		}
	}
}
