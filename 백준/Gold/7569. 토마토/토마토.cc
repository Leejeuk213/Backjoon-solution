#include<stdio.h>
#include<algorithm>
#include<tuple>
#include<queue>
using namespace std;
int dz[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,1,-1};
int n,m,h;
int tomato[101][101][101];
int cnt[101][101][101];
int visit[101][101][101];
int find()
{
    int max=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(max<cnt[i][j][k])
                {
                    max=cnt[i][j][k];
                }
            }
        }
    }
    return max;
}
int ok()
{
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(tomato[i][j][k]==0)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
void bfs(int x, int y, int z)
{
    queue<tuple<int,int,int>>q;
    cnt[z][x][y]=0;
    visit[z][x][y]=1;
    q.push(make_tuple(z,x,y));
    while(!q.empty())
    {
        int rx=get<1>(q.front());  
        int ry=get<2>(q.front());  
        int rz=get<0>(q.front());   
        q.pop();
        for(int i=0;i<6;i++)
        {
            int x2=rx+dx[i];
            int y2=ry+dy[i];
            int z2=rz+dz[i];
            if(z2<0||x2<0||y2<0||z2>=h||x2>=n||y2>=m||tomato[z2][x2][y2]==-1)
            {
                continue;
            }
            if(tomato[z2][x2][y2]==0)
            {
                tomato[z2][x2][y2]=1;
                cnt[z2][x2][y2]=cnt[rz][rx][ry]+1;
                q.push(make_tuple(z2,x2,y2));
                visit[z2][x2][y2]=1;
                continue;
            }
            else if(tomato[z2][x2][y2]==1)
            {
                if(cnt[z2][x2][y2]==0)
                {
                    cnt[z2][x2][y2]=cnt[rz][rx][ry]+1;
                    q.push(make_tuple(z2,x2,y2));
                }
                else if(cnt[z2][x2][y2]>cnt[rz][rx][ry]+1)
                {
                    cnt[z2][x2][y2]=cnt[rz][rx][ry]+1;
                    q.push(make_tuple(z2,x2,y2));
                }
            }
        }
    }

}
int main()
{
    scanf("%d %d %d",&m,&n,&h);
    int allcheck=1;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                scanf("%d",&tomato[i][j][k]);
                if(tomato[i][j][k]==0)
                {
                    allcheck=0;
                }
            }
        }
    }
    if(allcheck==1)
    {
        printf("0");
        return 0;
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(tomato[i][j][k]==1&&visit[i][j][k]!=1)
                {
                    bfs(j,k,i);
                }
            }
        }
    }
    /*for(int l=0;l<h;l++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                printf("%d ",cnt[l][j][k]);
                
            }
            printf("\n");
        }
    }*/
    if(ok()==1)
    {
        printf("%d",find());
    }
    else
    {
        printf("-1");
    }
    return 0;
}