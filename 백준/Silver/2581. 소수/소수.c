#include <stdio.h>
#include <string.h>


int main()
{

int top;
int bottom;
int sum=0;
int small=0;
scanf("%d %d",&top,&bottom);
for(int i=top;i<=bottom;i++)
{
    int cnt=0;
    if (i<=1)
    {
        continue;
    }
    for (int j=2;j<=i;j++)
    {
        if(i%j==0)
        {
            cnt++;
        }
    }
    if(cnt==1)
    {
        if(sum==0)
        {
            small=i;
        }
        sum=sum+i;
    }
}
if(sum!=0)
{
printf("%d\n%d",sum,small);
}
else{
    printf("-1");
}
return 0;
}
