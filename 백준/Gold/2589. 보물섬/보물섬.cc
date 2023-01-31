#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<algorithm>
#include<tuple>
using namespace std;
string v[51];
int rx[4]={0,0,1,-1};
int ry[4]={1,-1,0,0};
int ans=0;
int n,m;
int visit[51][51];
void bfs(int sx,int sy)
{
    memset(visit,0,sizeof(visit));
    queue<tuple<int,int,int>>q;
    visit[sx][sy]=1;
    q.push(make_tuple(sx,sy,0));
    while(!q.empty())
    {
        int fx=get<0>(q.front());
        int fy=get<1>(q.front());
        int cnt=get<2>(q.front());
        q.pop();
        ans=max(ans,cnt);
        for(int i=0;i<4;i++)
        {
            int x=fx+rx[i];
            int y=fy+ry[i];
            if(x<0||y<0||x==n||y==m)continue;

            if(visit[x][y]==0&&v[x][y]=='L')
            {
                visit[x][y]=1;
                q.push(make_tuple(x,y,cnt+1));
            }
        }
    }
    return ;
}


int main()
{
    cin >>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='L')
            {
                bfs(i,j);
            }
        }
    }
    cout <<ans;
    return 0;
}