#include<stdio.h>
#include<string.h>
#include<queue>
#include<tuple>
using namespace std;
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int maze[1001][1001];
int cnt[2][1001][1001];
int bfs()
{
    queue<tuple<int,int,int>>q;
    cnt[0][1][1]=1;
    q.push(make_tuple(1,1,0));
    while(!q.empty())
    {
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int w=get<2>(q.front());
        q.pop();
        for(int i=0;i<4;i++)
        {
            int rx=x+dx[i];
            int ry=y+dy[i];
            int rw=w+maze[rx][ry];
            if(rx==n&&ry==m)
            {
                cnt[rw][n][m]=cnt[rw][x][y]+1;
                return cnt[rw][n][m];
            }
            if(rx>n||ry>m||rx==0||ry==0||rw==2)
            {
                continue;
            }
            if(cnt[rw][rx][ry]==0)
            {
                cnt[rw][rx][ry]=cnt[w][x][y]+1;
                q.push(make_tuple(rx,ry,rw));
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%1d",&maze[i][j]);
        }
    }
    if(n==1&&m==1)
    {
        printf("1");
        return 0;
    }
    memset(cnt,0,sizeof(cnt));
    printf("%d",bfs());
    return 0;
}