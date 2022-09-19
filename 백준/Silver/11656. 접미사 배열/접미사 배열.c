#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char num[1001][1001];
int compare(const void *a, const void *b)
{
	return strcmp(a, b);
}
int main()
{
    char a[1001];
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++)
    {
        strncpy(num[i],a+i,strlen(a));       
    }
    qsort(num, strlen(a), sizeof(num[0]), compare);
    for(int i=0;i<strlen(a);i++)
    {
        printf("%s\n",num[i]);
        
    }
}