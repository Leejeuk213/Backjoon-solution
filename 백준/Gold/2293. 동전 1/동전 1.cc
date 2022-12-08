#include<stdio.h>
#include<algorithm>
using namespace std;
int coin[101];
int dp[10001]={0,};
int n,k;
int main()
{   
    scanf("%d %d",&n,&k);
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&coin[i]);
    }
    sort(coin,coin+n);
    for(int i=0;i<n;i++)
    {
        for(int j=coin[i];j<=k;j++)
        {
            dp[j]=dp[j]+dp[j-coin[i]];
        }
    }
    printf("%d",dp[k]);
    return 0;
}