#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
char area[101][101];
int visit[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n;
int nor_cnt=0;
int spe_cnt=0;
void bsp(int x,int y)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visit[x][y]=1;
    char temp=area[x][y];
    while(!q.empty())
    {
        int rx=q.front().first;
        int ry=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x2=rx+dx[i];
            int y2=ry+dy[i];
            if(x2<0||y2<0||x2>=n||y2>=n)
            {
                continue;
            }
            if(area[x2][y2]==temp&&visit[x2][y2]!=1)
            {
                visit[x2][y2]=1;
                q.push(make_pair(x2,y2));
            }
            
        }
    }
}
void sbsp(int x,int y)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visit[x][y]=1;
    char temp=area[x][y];
    while(!q.empty())
    {
        int rx=q.front().first;
        int ry=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x2=rx+dx[i];
            int y2=ry+dy[i];
            if(x2<0||y2<0||x2>=n||y2>=n)
            {
                continue;
            }
            if(temp=='R'||temp=='G')
            {
                if(area[x2][y2]=='R'||area[x2][y2]=='G')
                {
                    if(visit[x2][y2]!=1)
                    {
                        visit[x2][y2]=1;
                        q.push(make_pair(x2,y2));
                    }
                }
            }
            else if(temp=='B')
            {
                if(area[x2][y2]==temp&&visit[x2][y2]!=1)
                {
                    visit[x2][y2]=1;
                    q.push(make_pair(x2,y2));
                }
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",area[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visit[i][j]!=1)
            {
                bsp(i,j);
                nor_cnt++;  
            }
        }
    }
    memset(visit,0,sizeof(visit));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visit[i][j]!=1)
            {
                sbsp(i,j);
                spe_cnt++;  
            }
        }
    }
    printf("%d %d",nor_cnt,spe_cnt);
    return 0;
}