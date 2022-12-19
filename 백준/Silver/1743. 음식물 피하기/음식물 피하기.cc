#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
vector<pair<int,int>>v;
int rx[4]={0,0,-1,1};
int ry[4]={1,-1,0,0};
int check[101][101];
int n;
int m;
int k;
int maxnum=0;
int cnt=0;
int tonro[101][101];
void dfs(int x,int y)
{
    check[x][y]=1;
    cnt++;
    for(int i=0;i<4;i++)
    {
        int cx=x+rx[i];
        int cy=y+ry[i];
        if(check[cx][cy]==0&&tonro[cx][cy]==1)
        {
            check[cx][cy]=1;
            dfs(cx,cy);
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
        int q,w;
        cin>>q>>w;
        v.push_back(make_pair(q,w));
        tonro[q][w]=1;
    }
    for(int i=0;i<v.size();i++)
    {
        cnt=0;
        if(check[v[i].first][v[i].second]==0)
        dfs(v[i].first,v[i].second);
        if(maxnum<cnt)
        {
            maxnum=cnt;
        }
    }
    cout<<maxnum;
    return 0;
}