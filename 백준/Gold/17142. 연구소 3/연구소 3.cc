#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int n,m;
int check[51][51];
int originalspace[51][51];
int rx[4]{0,0,-1,1};
int ry[4]{1,-1,0,0};
int minans=987654321;
int maxans=0;
int backcheck[51][51];
vector<pair<int,int>>vsunit;
int bfs()
{
    int cnt=0;
    int vscheck[51][51];
    memset(check,0,sizeof(check));
    memset(vscheck,0,sizeof(vscheck));
    int tempspace[51][51]; //tempspace 초기화 및 생성
    memset(tempspace,0,sizeof(tempspace));
    queue<pair<int,int>>q;
    maxans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(originalspace[i][j]==2)
            {
                tempspace[i][j]=-1;
            }
            else
            {
                tempspace[i][j]=originalspace[i][j];
            }
        }
    }
    for(int i=0;i<vsunit.size();i++)    //큐에 바이러스들 넣고 돌릴 준비
    {
        q.push(make_pair(vsunit[i].first,vsunit[i].second));
        vscheck[vsunit[i].first][vsunit[i].second]=1;
        check[vsunit[i].first][vsunit[i].second]=1;
        tempspace[vsunit[i].first][vsunit[i].second]=0;
    }
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(vscheck[x][y]==0)
        {
            maxans=max(maxans,tempspace[x][y]);
        }
        for(int i=0;i<4;i++)
        {
            int cx=x+rx[i];
            int cy=y+ry[i];
            if(cx<0||cy<0||cx==n||cy==n)
            {
                continue;
            }
            if(check[cx][cy]==0&&tempspace[cx][cy]==0)
            {
                tempspace[cx][cy]=tempspace[x][y]+1;
                check[cx][cy]=1;
                q.push(make_pair(cx,cy));
            }
            else if(check[cx][cy]==0&&tempspace[cx][cy]==-1)
            {
                tempspace[cx][cy]=tempspace[x][y]+1;
                vscheck[cx][cy]=1;
                check[cx][cy]=1;
                q.push(make_pair(cx,cy));
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vscheck[i][j]==0&&tempspace[i][j]==0)
            {
                return 0;
            }
        }
    }
    return 1;
}
void back(int depth,int index_i,int index_j)
{
    int i;
    int j;
    if(depth==m)
    {
        if(bfs())
        {
            minans=min(minans,maxans);
        }
        return;
    }
    for(i=index_i;i<n;i++)
    {
        for(j=index_j;j<n;j++)
        {
            if(originalspace[i][j]==2&&backcheck[i][j]==0)
            {
                backcheck[i][j]=1;
                vsunit.push_back(make_pair(i,j));
                back(depth+1,i,j);
                backcheck[i][j]=0;
                vsunit.pop_back();
            }
        }
        index_j=0;
    }
    return;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>originalspace[i][j];
        }
    }
    back(0,0,0);
    if(minans==987654321)
    {
        cout<<"-1";
        return 0;
    }
    cout<<minans;
    return 0;
}