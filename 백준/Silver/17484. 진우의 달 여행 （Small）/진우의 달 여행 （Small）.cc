#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m;
int spaceship[7][7];
int dp[7][7][3];
int solve()
{
    int miny=987654321;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j==0)
            {
                dp[i][j][0]=min(dp[i-1][j+1][1],dp[i-1][j+1][2])+spaceship[i][j];
                dp[i][j][1]=min(dp[i-1][j][0],dp[i-1][j][2])+spaceship[i][j];
                dp[i][j][2]=987654321;
            }
            else if(j>0&&j<m-1)
            {
                dp[i][j][0]=min(dp[i-1][j+1][1],dp[i-1][j+1][2])+spaceship[i][j];
                dp[i][j][1]=min(dp[i-1][j][0],dp[i-1][j][2])+spaceship[i][j];
                dp[i][j][2]=min(dp[i-1][j-1][0],dp[i-1][j-1][1])+spaceship[i][j];
            }
            else
            {
                dp[i][j][0]=987654321;
                dp[i][j][1]=min(dp[i-1][j][0],dp[i-1][j][2])+spaceship[i][j];
                dp[i][j][2]=min(dp[i-1][j-1][0],dp[i-1][j-1][1])+spaceship[i][j];
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(miny>dp[n-1][i][j])
            {
                miny=dp[n-1][i][j];
            }
        }
    }
    return miny;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&spaceship[i][j]);
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<3;j++)
        {
            dp[0][i][j]=spaceship[0][i];
        }
    }
    printf("%d",solve());
    return 0;
}