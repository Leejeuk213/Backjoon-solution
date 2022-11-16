#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dp[21]={0,};
int time[21]={0,};
int pay[21]={0,};
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&time[i],&pay[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int j=i;
        if(i+time[i]>n+1&&dp[i+1]==0)
        {
            int big=0;
            for(int k=i;k>=1;k--)
            {
                if(big<dp[k])
                {
                    big=dp[k];
                }
            }
            dp[i+1]=big;
        }
        while(j<i+time[i]&&j+time[j]<=n+1)
        {
            int big=0;
            for(int k=j;k>=1;k--)
            {
                if(big<dp[k])
                {
                    big=dp[k];
                }
            }
            if(dp[j+time[j]]<big+pay[j])
            {
                dp[j+time[j]]=big+pay[j];
            }
            if(dp[j+time[j]]<dp[i]+pay[j])
            {
                dp[j+time[j]]=dp[i]+pay[j];
            }
            j++;
        }
    }
    sort(&dp[1],&dp[n+5],greater<int>());
    printf("%d\n",dp[1]);
    /*for(int i=1;i<=n+1;i++)
    {
        printf("%d\n",dp[i]);
    }*/
    return 0;
}