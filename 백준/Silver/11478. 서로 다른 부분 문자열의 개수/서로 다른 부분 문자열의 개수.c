#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char bb[502000][1002];
int count=0;
int compare(const void *a, const void *b)
{
	return strcmp(a, b);
}
int main()
{
char a[1002];
scanf("%s",a);
for(int i=0;i<strlen(a);i++)
{
    bb[i][0]=a[i];
}
    int k=strlen(a);
    int cnt2=0;
    for(int i=0;i<strlen(a);i++)
    {
        int cnt=0;
        
        for(int j=0;j<strlen(a)-i-1;j++)
        {   
            cnt++;
            strcpy(bb[k],bb[j+cnt2]);
            strcat(bb[k++],bb[j+1+i]);
        }
        cnt2=cnt2+cnt+1;
    }
   qsort(bb,k, sizeof(bb[0]), compare);
    for(int i=0;i<k;i++)
    {
        if(strcmp(bb[i],bb[i+1])!=0)
        {
            count++;
        }
        
    }
printf("%d",count); 
return 0;
}