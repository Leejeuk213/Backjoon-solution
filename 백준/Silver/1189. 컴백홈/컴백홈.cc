#include<iostream>
#include<vector>
using namespace std;
int r,c,k;
int ans=0;
int rx[4]={0,0,-1,1};
int ry[4]={-1,1,0,0};
char graph[6][6];
int check[6][6];
void dfs(int x,int y,int depth)
{
    if(graph[x][y]=='h')
    {
        if(depth==k-1)
        {
            ans++;
        }
        return;
    }
    for(int i=0;i<4;i++)
    {
        int cx=x+rx[i];
        int cy=y+ry[i];
        if(cx<0||cy<0||cx>=r||cy>=c||graph[cx][cy]=='T'||check[cx][cy]==1)
        {
            continue;
        }
        check[cx][cy]=1;
        dfs(cx,cy,depth+1);
        check[cx][cy]=0;    
    }
}
int main()
{
    cin>>r>>c>>k;
    for(int i=0;i<r;i++)
    {
        cin>>graph[i];
    }
    graph[0][c-1]='h';
    check[r-1][0]=1;
    dfs(r-1,0,0);
    cout<<ans;
    return 0;
}