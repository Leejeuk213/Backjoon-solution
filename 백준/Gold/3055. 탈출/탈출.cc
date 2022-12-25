#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<tuple>
using namespace std;
int rx[4]={0,0,-1,1};
int r,c;
int ry[4]={1,-1,0,0};
string g[1001];
int n;
int check[1001][1001];
vector<pair<int,int>>f;
void bfs(int f_x,int f_y)
{
    queue<pair<int,int>>fire;
    queue<tuple<int,int,int>>q;
    for(int i=0;i<f.size();i++)
    {
        fire.push(make_pair(f[i].first,f[i].second));
    }
    q.push(make_tuple(f_x,f_y,0));
    check[f_x][f_y]=1;
    while(!q.empty())
    {
        int roop=fire.size();
        for(int i=0;i<roop;i++) // 불 작업
        {
            int xx=fire.front().first;
            int yy=fire.front().second;
            fire.pop();
            for(int j=0;j<4;j++)
            {
                int cx=xx+rx[j];
                int cy=yy+ry[j];
                if(cx<0||cy<0||cx>=r||cy>=c)
                {
                    continue;
                }
                if(g[cx][cy]=='.')
                {
                    g[cx][cy]='*';
                    fire.push(make_pair(cx,cy));
                }
            }
        }
        int roop2=q.size();
        for(int k=0;k<roop2;k++)
        {
            int x=get<0>(q.front());
            int y=get<1>(q.front());
            int cnt=get<2>(q.front());
            q.pop();
            for(int i=0;i<4;i++)
            {
                int cx=x+rx[i];
                int cy=y+ry[i];
                if(cx<0||cy<0||cx>=r||cy>=c)
                {
                    continue;
                }
                if(g[cx][cy]=='D')
                {
                    cout<<cnt+1<<"\n";
                    return ;
                }
                if(check[cx][cy]==0&&g[cx][cy]=='.')
                {
                    check[cx][cy]=1;
                    q.push(make_tuple(cx,cy,cnt+1));
                }
            }
        }
    }
    cout<<"KAKTUS"<<"\n";
    return ;
}
int main()
{
    cin>>r>>c;
    int f_x;
    int f_y;
    for(int i=0;i<r;i++)
    {
        cin>>g[i];
    }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(g[i][j]=='S')
                {
                    f_x=i;
                    f_y=j;
                    g[i][j]='.';
                }
                else if(g[i][j]=='*')
                {
                    f.push_back(make_pair(i,j));
                }
            }
        }
    bfs(f_x,f_y);
    return 0;
}