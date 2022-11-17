#include<stdio.h>
int Max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    int roop;
    int wine[10001];
    int dp[10001];
    scanf("%d",&roop);
    for(int i=1;i<=roop;i++)
    {
        scanf("%d",&wine[i]);
    }
    dp[0]=0;
    dp[1]=wine[1];
    dp[2]=wine[1]+wine[2];
    int max=0;
    int index=1;
    for(int i=3;i<=roop;i++)
    {
       int first=wine[i]+dp[i-3]+wine[i-1];
       int second=wine[i]+dp[i-2];
       dp[i]=Max(dp[i-1],Max(first,second));
    }
    printf("%d",dp[roop]);
    return 0;
}