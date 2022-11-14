#include<stdio.h>

int main()
{
    int roop;
    int num[1001];
    int dp[1001];
    scanf("%d",&roop);
    for(int i=0;i<roop;i++)
    {
        scanf("%d",&num[i]);
    }
    int max=0;
    int max_index=0;
    int max2=0;
    for(int i=0;i<roop;i++)
    {
        max_index=0;
        max2=0;
        dp[i]=1;
        for(int j=0;j<=i;j++)
        {
           if(num[j]<num[i])
           {
                if(max2<dp[j])
                {
                    max_index=j;
                    max2=dp[j];
                    dp[i]=max2+1;
                }
           }
        }
        if(max<dp[i])
        {
            max=dp[i];
        }
    }
    printf("%d",max);
    return 0;
}