#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
queue <pair<int,int>>q;
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ix=0;
int maze[101][101];
int visited[101][101];
int cnt[101][101];

void bsp(int x_,int y_)
{
    q.push(make_pair(x_,y_));
    cnt[x_][y_]=1;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
           int x2=x+dx[i];
           int y2=y+dy[i];
            if(x2>n||y2>m||x2==0||y2==0)
            {
                continue;
            }
            else
            {
                if(maze[x2][y2]==1)
                {
                    //printf("0 %d %d\n",x2,y2);
                    if(cnt[x2][y2]==0)
                    {
                       // printf("1 %d %d\n",x2,y2);
                        cnt[x2][y2]=cnt[x][y]+1;
                        q.push(make_pair(x2,y2));
                    }
                    else
                    {
                        if(cnt[x2][y2]>cnt[x][y]+1)
                        {
                         //   printf("2 %d %d\n",x2,y2);
                            cnt[x2][y2]=cnt[x][y]+1;
                            q.push(make_pair(x2,y2));
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<101;i++)
    {
        memset(cnt[i],0,sizeof(cnt[i]));
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%1d",&maze[i][j]);
        }
    }
    bsp(1,1);
    printf("%d",cnt[n][m]);
    return 0;
}