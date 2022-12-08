#include<stdio.h>
#include<algorithm>
using namespace std;
int coin[101];
int dp[10001]={0,};
int n,k;
int main()
{   
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&coin[i]);
    }
    for(int i=1;i<=k;i++)
    {
        dp[i]=987654321;
    }
    dp[0]=0;
    sort(coin,coin+n);
    for(int i=0;i<n;i++)
    {
        for(int j=coin[i];j<=k;j++)
        {
            dp[j]=min(dp[j],dp[j-coin[i]]+1);
        }
    }
    if(dp[k]==987654321)
    {
        printf("-1");
    }
    else
    {
        printf("%d",dp[k]);
    }
    return 0;
}