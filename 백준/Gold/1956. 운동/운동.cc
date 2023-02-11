#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int INF=987654321;
int v[401][401];
int n,m;
int ans=INF;
int main()
{
    cin >>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) v[i][j]=0;
            else v[i][j]=INF;
        }
    }
    for(int i=0;i<m;i++)
    {
        int q,w,e;
        cin >>q>>w>>e;
        v[q][w]=e;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(v[i][j]!=INF&&v[j][i]!=INF&&i!=j)
            {
                ans=min(ans,v[i][j]+v[j][i]);
            }
        }
    }
    if(ans==INF) cout<<"-1";
    else cout <<ans;
    return 0;
}