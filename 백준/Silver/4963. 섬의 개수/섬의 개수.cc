#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int w,h;
int space[51][51];
int check[51][51];
int rx[8]={0,0,1,-1,1,1,-1,-1};
int ry[8]={1,-1,0,0,1,-1,-1,1};
void dfs(int x,int y)
{
    check[x][y]=1;
    for(int i=0;i<8;i++)
    {
        int cx=x+rx[i];
        int cy=y+ry[i];
        if(cx<0||cy<0||cx>=w||cy>=h)
        {
            continue;
        }
        if(check[cx][cy]==0&&space[cx][cy]==1)
        {
            check[cx][cy]=1;
            dfs(cx,cy);
        }
    }
}
int main()
{
    while(1)
    {
        cin>>h>>w;
        int ans=0;
        memset(space,0,sizeof(space));
        memset(check,0,sizeof(check));
        if(w==0&&h==0)
        {
            break;
        }
        for(int i=0;i<w;i++)
        {
            for(int j=0;j<h;j++)
            {
                cin>>space[i][j];
            }
        }
        for(int i=0;i<w;i++)
        {
            for(int j=0;j<h;j++)
            {
                if(check[i][j]==0&&space[i][j]==1)
                {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}