#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int INF=987654321;
int d[101][101];

int ans[101][101];
int n,m;
int main()
{
    cin >>n;
    cin >>m;

    for(int i=0;i<m;i++)
    {
        int q,w,e;
        cin >>q>>w>>e;
        if(d[q][w]==0) d[q][w]=e;
        else
        {
            if(d[q][w]>e) d[q][w]=e;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) ans[i][j]=0;
            else if(d[i][j]) ans[i][j]=d[i][j];
            else ans[i][j]=INF; 
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(ans[i][j]==INF)cout<<"0"<<" ";
            else cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}