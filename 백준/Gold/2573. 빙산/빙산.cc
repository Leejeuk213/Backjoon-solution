#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int n,m;
int ans=0;
int space[301][301];
int visit[301][301];
int solvevisit[301][301];
int rx[4]={0,0,1,-1};
int ry[4]={1,-1,0,0};

int check()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(space[i][j]) return 0;
        }
    }
    return 1;
}

void bfs(int fx, int fy)
{
    queue<pair<int,int>>q;
    visit[fx][fy]=1;
    q.push(make_pair(fx,fy));

    while(!q.empty())
    {
        int qx=q.front().first;
        int qy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=qx+rx[i];
            int y=qy+ry[i];
            if(x<0||y<0||x==n||y==m) continue;

            if(visit[x][y]==0&&space[x][y]!=0)
            {
                visit[x][y]=1;
                q.push(make_pair(x,y));
            }
        }
    }
}
int count()
{
    int cnt=0;
    memset(visit,0,sizeof(visit));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visit[i][j]==0&&space[i][j]!=0)
            {
                cnt++;
                bfs(i,j);

                if(cnt>=2) return 1;
            }
        }
    }
    return 0;
}

int solve()
{

    while(1)
    {
        ans++;
        memset(solvevisit,0,sizeof(solvevisit));
        if(check()) return 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int temp=0;
                if(space[i][j])
                {
                    solvevisit[i][j]=1;
                    for(int k=0;k<4;k++)
                    {
                        int x=i+rx[k];
                        int y=j+ry[k];
                        if(x<0||y<0||x==n||y==m||solvevisit[x][y]) continue;

                        if(space[x][y]==0) temp++;
                    }
                    space[i][j]=space[i][j]-temp;
                    if(space[i][j]<0)space[i][j]=0;
                }
            }
        }
        if(count())
        {
            return 0;
        }
    }

    return 0;
}
int main()
{
    cin >>n>>m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >>space[i][j];
        }
    }

    if(solve()) cout<<"0";
    else cout<<ans;

    return 0;
}