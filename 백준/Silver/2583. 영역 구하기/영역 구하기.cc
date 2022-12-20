#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int cnt=0;
int check[101][101];
int space[101][101];
int m,n,k;
int rx[4]={0,0,-1,1};
int ry[4]={1,-1,0,0};
vector<int>ans;
void dfs(int x,int y)
{
    check[x][y]=1;
    cnt++;
    for(int i=0;i<4;i++)
    {
        int cx=x+rx[i];
        int cy=y+ry[i];
        if(cx<0||cy<0||cx>=n||cy>=m)
        {
            continue;
        }
        if(check[cx][cy]==0&&space[cx][cy]==0)
        {
            check[cx][cy]=1;
            dfs(cx,cy);
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    memset(space,0,sizeof(check));
    for(int i=0;i<k;i++)
    {
        int x1,x2,y1,y2;
        cin>>y1>>x1>>y2>>x2;
        for(int j=x1;j<x2;j++)
        {
            for(int k=y1;k<y2;k++)
            {
                space[j][k]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cnt=0;
            if(check[i][j]==0&&space[i][j]==0)
            {
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}