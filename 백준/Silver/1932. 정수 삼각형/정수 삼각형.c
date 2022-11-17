#include<stdio.h>

int main()
{
    int roop;
    scanf("%d",&roop);
    int size[600]={0,};
    int dp[2500]={0,};
    long long max=-10;
    for(int i=0;i<roop;i++)
    {   
        for(int j=0;j<=i;j++)
        {
            scanf("%d",&size[j]);
        }
        if(i==1)
        {
            dp[1]=dp[0]+size[1];
            dp[0]=dp[0]+size[0];
            continue;
        }
        if(i==0)
        {
            dp[0]=size[0];
            continue;
        }
        for(int j=i-1;j>=0;j--)
        {
            dp[(j*2)+1]=dp[j]+size[j+1];
            dp[(j*2)]=dp[j]+size[j];
        }
        if(i!=1&&i!=0)
        {
            int cnt=0;
            for(int k=1;k<i*2;k=k+2)
            {
                if(dp[k+1]>=dp[k])
                {
                    dp[k-cnt]=dp[k+1];
                    dp[k+1]=0;
                }
                else
                {
                    dp[k+1]=0;
                    dp[k-cnt]=dp[k];
                }
                cnt++;
            }
            dp[i]=dp[(i-1)*2+1];
            dp[(i-1)*2+1]=0;
        }

    }
    for(int i=0;i<2500;i++)
    {
        if(max<=dp[i])
        {
            max=dp[i];
        }
    }
    printf("%lld",max);
    return 0;
}