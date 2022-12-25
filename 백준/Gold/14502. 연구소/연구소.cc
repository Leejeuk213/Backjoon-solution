#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int n,m;
int check[9][9];
int originalspace[9][9];
int rx[4]{0,0,-1,1};
int ry[4]{1,-1,0,0};
int maxans=0;
int backcheck[9][9];
vector<pair<int,int>>vs;
vector<pair<int,int>>wall;
void bfs()
{
    int cnt=0;
    memset(check,0,sizeof(check));
    int tempspace[9][9]; //tempspace 초기화 및 생성
    queue<pair<int,int>>q;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            tempspace[i][j]=originalspace[i][j];
        }
    }

    for(int i=0;i<wall.size();i++)  //백트래킹으로 만든 벽 넣기
    {
        tempspace[wall[i].first][wall[i].second]=1;
    }

    for(int i=0;i<vs.size();i++)    //큐에 바이러스들 넣고 돌릴 준비
    {
        q.push(make_pair(vs[i].first,vs[i].second));
    }

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
            if(check[cx][cy]==0&&tempspace[cx][cy]==0)
            {
                tempspace[cx][cy]=2;
                check[cx][cy]=1;
                q.push(make_pair(cx,cy));
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(tempspace[i][j]==0)
            {
                cnt++;
            }
        }
    }
    maxans=max(maxans,cnt);
    return;
}

void back(int depth,int index_i)
{
    if(depth==3)
    {
        bfs();
        return;
    }
    for(int i=index_i;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(originalspace[i][j]==0&&backcheck[i][j]==0)
            {
                backcheck[i][j]=1;
                wall.push_back(make_pair(i,j));
                back(depth+1,i);
                backcheck[i][j]=0;
                wall.pop_back();
            }
        }
    }
    return;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>originalspace[i][j];
            if(originalspace[i][j]==2)
            {
                vs.push_back(make_pair(i,j));
            }
        }
    }
    back(0,0);
    cout<<maxans;
    return 0;
}