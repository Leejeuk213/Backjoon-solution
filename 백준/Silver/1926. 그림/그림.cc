#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n,m;
int paper[501][501];
int check[501][501];
int maxcnt=0;
int anscnt=0;
int maxans=0;
priority_queue<int>ans;
int rx[4]{0,0,-1,1};
int ry[4]{1,-1,0,0};
void bfs(int f_x,int f_y)
{
    maxcnt=1;
    queue<pair<int,int>>q;
    check[f_x][f_y]=1;
    q.push(make_pair(f_x,f_y));
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int cx=x+rx[i];
            int cy=y+ry[i];
            if(cx<0||cy<0||cx==n||cy==m)
            {
                continue;
            }
            if(check[cx][cy]==0&&paper[cx][cy]==1)
            {
                check[cx][cy]=1;
                q.push(make_pair(cx,cy));
                maxcnt++;
            }
        }
    }
}

int main()
{
    cin >>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>paper[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(paper[i][j]==1&&check[i][j]==0)
            {
                bfs(i,j);
                anscnt++;
                maxans=max(maxans,maxcnt);
            }
        }
    }
    cout<<anscnt<<"\n";
    cout<<maxans;
    return 0;
}