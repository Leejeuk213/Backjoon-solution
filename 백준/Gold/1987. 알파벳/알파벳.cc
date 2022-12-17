#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
char board[21][21];
int r,c;
int ans=0;
int rx[4]={0,0,1,-1};
int ry[4]={1,-1,0,0};
map<char,int>m;
void back(int cnt,int cx,int cy)
{
    if(cnt>ans)
    {
        ans=cnt;
    }
    for(int k=0;k<4;k++)
    {
        int x=cx+rx[k];
        int y=cy+ry[k];
        if(x<0||y<0||x>=r||y>=c||m[board[x][y]]==1)
        {
            continue;
        }
        m[board[x][y]]=1;
        back(cnt+1,x,y);
        m[board[x][y]]=0;
    }  
    return ;
}
int main()
{
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        cin>>board[i];
    }
    m[board[0][0]]=1;
    back(1,0,0);
    cout<<ans;
    return 0;
}