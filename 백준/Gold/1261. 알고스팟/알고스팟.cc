#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;

int rx[4]={0,0,1,-1,};
int ry[4]={1,-1,0,0};
int INF=987654321;
int n,m;
int maze[101][101];
int wall[101][101];
void bfs()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            wall[i][j]=INF;
        }
    }

    queue<tuple<int,int,int>>q;
    q.push(make_tuple(0,0,0));
    wall[0][0]=0;
    while(!q.empty())
    {
        int fx=get<0>(q.front());
        int fy=get<1>(q.front());
        int cnt=get<2>(q.front());

        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=fx+rx[i];
            int y=fy+ry[i];
            int flag=0;
            if(maze[x][y]==1) flag=1;
            if(x<0||y<0||x==n||y==m)continue;

            if(wall[x][y]>cnt+flag)
            {
                wall[x][y]=cnt+flag;
                q.push(make_tuple(x,y,cnt+flag));
            }
        }

    }
}
int main()
{
    cin >>m>>n;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%1d",&maze[i][j]);
        }

    }
    bfs();
    cout<<wall[n-1][m-1];
    return 0;
}