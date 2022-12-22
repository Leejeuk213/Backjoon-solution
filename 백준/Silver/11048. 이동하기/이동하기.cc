#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int num[1001][1001];
int dp[1001][1001];
int n,m;
int rx[3]={1,0,1};
int ry[3]={0,1,1};
void solve()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<3;k++)
            {
                int x=i+rx[k];
                int y=j+ry[k];
                if(x>n||y>m)
                {
                    continue;
                }
                dp[x][y]=max(dp[x][y],dp[i][j]+num[x][y]);
            }
        }
    }
    return;
}
int main()
{
    cin >>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>num[i][j];
        }
    }
    dp[1][1]=num[1][1];
    solve();
    cout<<dp[n][m];
    return 0;
}