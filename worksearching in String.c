#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void hackerrankInString(char* s) 
{
    char *t=(char *)malloc(sizeof(char)*5120000);
    t="hackerrank";
    int i;
    int count=0;
    int len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(t[count]==s[i])
        {
            count++;
        }
    }
    if(count==10)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

int main() 
{
    int q; 
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        char* s = (char *)malloc(512000 * sizeof(char));
        scanf("%s", s);
        int result_size;
        hackerrankInString(s);
        //printf("%s\n", result);
    }
}