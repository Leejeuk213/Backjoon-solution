#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m;
int INF=987654321;
int ans[101][101];
vector<int> before[101][101];
int depth[101][101];
int main()
{
    memset(depth,0,sizeof(depth));
    cin >>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) 
        {
            if(i==j)ans[i][j]=0;
            else ans[i][j]=INF;
        }
    }
    
    while(m--)
    {
        int q,w,e;

        cin >>q>>w>>e;

        if(ans[q][w]>e) 
        {
            ans[q][w]=e;
            depth[q][w]=1;
            before[q][w].clear();
            before[q][w].push_back(q);
            before[q][w].push_back(w);
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(ans[i][j]>ans[i][k]+ans[k][j])
                {
                    ans[i][j]=ans[i][k]+ans[k][j];
                    depth[i][j]=depth[i][k]+depth[k][j];
                    before[i][j].clear();
                    for(int q=0;q<before[i][k].size();q++)
                    {
                        before[i][j].push_back(before[i][k][q]);
                    }
                    for(int q=1;q<before[k][j].size();q++)
                    {
                        before[i][j].push_back(before[k][j][q]);
                    }
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) 
        {
            if(ans[i][j]==INF) cout<<"0"<<" ";
            else cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) 
        {
            if(i==j||ans[i][j]==INF)
            {
                cout <<"0"<<"\n";
            }
            else
            {
                cout<<depth[i][j]+1<<" ";
                for(int k=0;k<before[i][j].size();k++)
                {
                    cout<<before[i][j][k]<<" ";
                }
                cout <<"\n";
            }
        }
    }
    return 0;
}