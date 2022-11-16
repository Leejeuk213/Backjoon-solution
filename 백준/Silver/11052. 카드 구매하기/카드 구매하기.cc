#include<stdio.h>

int n;
int price[1002];
int dp[1002]={0,};
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&price[i]);
    }
    dp[1]=price[1];
    for(int i=2;i<=n;i++)
    {
        dp[i]=price[i];
        for(int j=i;j>=1;j--)
        {
            if(dp[i]<dp[i-j]+dp[j])
            {
                dp[i]=dp[i-j]+dp[j];
            }
        }
    }
    printf("%d",dp[n]);
    return 0;
}