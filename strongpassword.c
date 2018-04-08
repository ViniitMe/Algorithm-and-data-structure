#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void minimumNumber(int n, char* password) 
{
    int len=strlen(password);
    int i;
    int add=0;
    int count=0;
    int count2=0;
    int count3=0;
    int count4=0;
    if(n<6)
    {
        printf("%d",6-n);
    }
    if(n>=6&& n<=100)
    {
       for(i=0;i<len;i++)
       {
           if(password[i]>='0' && password[i]<='9')
           {
               count=1;
           }
           if(password[i]>='a' && password[i]<='z')
           {
               count2=1;
           }
           if(password[i]>='A' && password[i]<='Z')
           {
               count3=1;
           }
           if(password[i]=='!'||password[i]=='@'||password[i]=='#'||password[i]=='$'||password[i]=='%'||password[i]=='^'||password[i]=='&'||password[i]=='*'||password[i]=='('||password[i]==')'||password[i]=='-'||password[i]=='+')
           {
               count4=1;
           }
       }
        if(count==0)
        {
            add++;
        }
        if(count2==0)
        {
            add++;
        }
         if(count3==0)
        {
            add++;
        }
        if(count4==0)
        {
            add++;
        }
        printf("%d",add);
        // printf("\n%d",count4);
        //printf("\n%d",count);
        //printf("\n%d",count2);
        //printf("\n%d",count3);
    } 
}

int main() {
    int n; 
    scanf("%i", &n);
    char* password = (char *)malloc(512000 * sizeof(char));
    scanf("%s", password);
    minimumNumber(n, password);
    //int answer=printf("%d\n", answer);
    return 0;
}