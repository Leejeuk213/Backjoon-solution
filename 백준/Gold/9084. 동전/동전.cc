#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{   
    int roop;
    scanf("%d",&roop);
    for(int i=0;i<roop;i++)
    {
        int coin[101];
        int dp[10001]={0,};
        int n,k;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&coin[i]);
        }
        scanf("%d",&k);
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=coin[i];j<=k;j++)
            {
                dp[j]=dp[j]+dp[j-coin[i]];
            }
        }
        printf("%d\n",dp[k]);
    }
    return 0;
}