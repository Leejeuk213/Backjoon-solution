#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int cnt=0;
int check[101][101];
int space[101][101];
int n;
int rx[4]={0,0,-1,1};
int ry[4]={1,-1,0,0};
int ans=0;
void dfs(int x,int y,int height)
{
    check[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int cx=x+rx[i];
        int cy=y+ry[i];
        if(cx<0||cy<0||cx>=n||cy>=n)
        {
            continue;
        }
        if(check[cx][cy]==0&&space[cx][cy]>height)
        {
            check[cx][cy]=1;
            dfs(cx,cy,height);
        }
    }
}
int main()
{
    cin >>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>space[i][j];
        }
    }
    for(int k=0;k<=100;k++)
    {
        cnt=0;
        memset(check,0,sizeof(check));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(check[i][j]==0&&space[i][j]>k)
                {
                    cnt++;
                    dfs(i,j,k);
                }
            }
        }
        if(ans<cnt)
        {
            ans=cnt;
        }
    }
    cout<<ans;
    return 0;
}