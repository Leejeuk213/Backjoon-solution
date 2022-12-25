#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int n,l,r;
vector<pair<int,int>>list;
int con[51][51];
int ans=0;
int check[51][51];
int sum=0;
int change=0;
int rx[4]={0,0,1,-1};
int ry[4]={1,-1,0,0};
queue<pair<int,int>>o_q;
int cut(int a,int b)
{
    if(a>=b)
    {
        return a-b;
    }
    return b-a;
}
void bfs(int f_x,int f_y)
{
    queue<pair<int,int>>q;
    q.push(make_pair(f_x,f_y));
    list.push_back(make_pair(f_x,f_y));
    sum=0;
    check[f_x][f_y]=1;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        sum=sum+con[x][y];
        q.pop();
        for(int i=0;i<4;i++)
        {
            int cx=x+rx[i];
            int cy=y+ry[i];
            if(cx<0||cy<0||cx==n||cy==n)
            {
                continue;
            }
            int cutnum=cut(con[x][y],con[cx][cy]);
            if(check[cx][cy]==0&&cutnum>=l&&cutnum<=r)
            {
                check[cx][cy]=1;
                change=1;
                q.push(make_pair(cx,cy));
                list.push_back(make_pair(cx,cy));
            }
        }
    }
}
int main()
{
    cin>>n>>l>>r;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>con[i][j];
        }
    }
    while(1)
    {
        memset(check,0,sizeof(check));
        change=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(check[i][j]==0)
                {
                    sum=0;
                    list.clear();
                    bfs(i,j);
                    if(change)
                    {
                        for(int k=0;k<list.size();k++)
                        {
                            con[list[k].first][list[k].second]=sum/list.size();
                        }
                    }
                }
            }
        }
        if(change)
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    cout<<ans;
    return 0;
}