#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int n;
int dp[46]={0,};
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=45;i++)
    {
        dp[i]=(i*(i+1))/2;
    }
    for(int i=0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        int check=0;
        for(int j=1;j<=45;j++)
        {
            for(int k=1;k<=45;k++)
            {
                for(int l=1;l<=45;l++)
                {
                    if(dp[j]+dp[k]+dp[l]>num)
                    {
                        break;
                    }
                    else if(dp[j]+dp[k]+dp[l]==num)
                    {
                        check=1;
                    }
                    if(check)
                    {
                        break;
                    }
                }
                if(check)
                {
                    break;
                }
            }
            if(check)
            {
                break;
            }
        }
        if(check)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}