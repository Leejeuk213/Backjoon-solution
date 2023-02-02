#include<vector>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int n;
int cnt=1;
int cave[126][126];
int ans[126][126];
int rx[4]={0,0,1,-1};
int ry[4]={1,-1,0,0};
int INF=987654321;
void solve()
{
    memset(ans,0,sizeof(ans));

    queue<pair<int,int>>q;
    q.push(make_pair(0,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[i][j]=INF;
        }
    }
    ans[0][0]=cave[0][0];
    while(!q.empty())
    {
        int fx=q.front().first;
        int fy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=fx+rx[i];
            int y=fy+ry[i];
            if(x<0||y<0||x==n||y==n) continue;

            if(ans[x][y]>cave[x][y]+ans[fx][fy])
            {
                ans[x][y]=ans[fx][fy]+cave[x][y];
                q.push(make_pair(x,y));
            }
        }
    }

}
int main()
{

    while(1)
    {
        cin >>n;

        if(n==0)return 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >>cave[i][j];
            } 
        }       
        solve();
        cout<<"Problem "<<cnt<<": "<<ans[n-1][n-1]<<"\n";
        cnt++;
    }

    return 0;
}