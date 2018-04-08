#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ispalindrome(char *A)
{
	int i;
	int count=0;
	int len=strlen(A);
	if(len==1)
	{
		printf("Palindrome");
	}
	for(i=0;i<len;i++)
	{
		if(A[i]!=A[len-i-1])
		{
			printf("Not a Palindrome");
			break;
		}
		else
		{
			count++;
		}
	}
	if(count==len)
		printf("Palindrome");

}

int main()
{
	char *A=(char *)malloc(sizeof(char)*51200);
	printf("Enter the string:");
	scanf("%s",A);
	printf("Entered string:");
	printf("%s\n",A);
	ispalindrome(A);
	return 0;
}