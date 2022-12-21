#include<iostream>
#include<queue>
#include<vector>
using namespace std;
long long ans=987654321;
int check[1000001];
int f,s,g,u,d;
void bfs(int height)
{
    check[height]=1;
    queue<pair<long long,long long>>q;
    q.push(make_pair(height,0));
    while(!q.empty())
    {
        int x=q.front().first;
        long long cnt=q.front().second;
        if(x==g)
        {
            if(ans>cnt)
            {
                ans=cnt;
            }
            break;
        }
        q.pop();
        int x_up=x+u;
        int x_down=x-d;
        if(x_up<=f&&check[x_up]==0)
        {
            check[x_up]=1;
            q.push(make_pair(x_up,cnt+1));
        }
        if(x_down>0&&check[x_down]==0)
        {
            check[x_down]=1;
            q.push(make_pair(x_down,cnt+1));
        }
    }
}
int main()
{
    cin>>f>>s>>g>>u>>d;
    bfs(s);
    if(ans==987654321)
    {
        cout<<"use the stairs";
    }
    else
    {
        cout<<ans;
    }
    return 0;
}