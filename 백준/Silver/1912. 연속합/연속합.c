#include<stdio.h>

int main()
{
    int num[100001];
    int roop;
    int sum=0;
    int ans=0;
    scanf("%d",&roop);
    for(int i=0;i<roop;i++)
    {
        scanf("%d",&num[i]);
    }
    ans=num[0];
    int max=num[0];
    for(int i=0;i<roop-1;i++)
    {
        if(ans+num[i+1]<num[i+1])
        {
            ans=num[i+1];
        }
        else
        {
            ans=ans+num[i+1];
        }
        if(max<=ans)
        {
            max=ans;
        }
    }
    printf("%d\n",max);
    return 0;
}