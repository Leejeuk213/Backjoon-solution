#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;
int tomato[1005][1005];
int cnt[1005][1005];
queue<pair<int,int>>q;
int find()
{
    int max=0;
    
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(max<cnt[j][k])
                {
                    max=cnt[j][k];
                }
            }
        }
    return max;
}
void bfs()
{  
    int x=q.front().first;
    int y=q.front().second;
    cnt[x][y]=0;

    while(!q.empty())
    {
        int rx=q.front().first;  
        int ry=q.front().second; 
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x2=rx+dx[i];
            int y2=ry+dy[i];
            if(x2<0||y2<0||x2>=n||y2>=m||tomato[x2][y2]==-1)
            {
                continue;
            }
            if(tomato[x2][y2]==0)
            {
                if(cnt[x2][y2]==0)
                {
                    cnt[x2][y2]=cnt[rx][ry]+1;
                    q.push(make_pair(x2,y2));
                }
                else if(cnt[x2][y2]>cnt[rx][ry]+1)
                {
                    cnt[x2][y2]=cnt[rx][ry]+1;
                    q.push(make_pair(x2,y2));             
                }              
                continue;
            }
        }
    }
    return ;
}
int main()
{
    scanf("%d %d",&m,&n);
    int allcheck=1;
    
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                scanf("%d",&tomato[j][k]);
                if(tomato[j][k]==0)
                {
                    allcheck=0;
                }
                if(tomato[j][k]!=-1)
                {
                    cnt[j][k]=10000000;
                }
                if(tomato[j][k]==1)
                {
                    q.push(make_pair(j,k));
                    cnt[j][k]=0;
                }
            }
        }
    if(allcheck==1)
    {
        printf("0");
        return 0;
    }
    bfs();
    if(find()==10000000)
    {
        printf("-1");
    }
    else
    {
        printf("%d",find());
    }
    return 0;
}