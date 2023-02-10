#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

int dis[11];
int n;
int ans=987654321;
vector<int> v[11];
int visited[11];
void bfs()
{
    vector<int>input1;
    vector<int>input2;
    int check1[11];
    int check2[11];
    memset(check1,0,sizeof(check1));
    memset(check2,0,sizeof(check2));
    int sum1=0;
    int sum2=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==1) 
        {
            input1.push_back(i);
            sum1+=dis[i];
        }
        else 
        {
            input2.push_back(i);
            sum2+=dis[i];
        }
    }
    queue<int>q;
    queue<int>q2;
    q.push(input1[0]);
    q2.push(input2[0]);
    while(!q.empty())
    {
        int x=q.front();
        check1[x]=1;
        q.pop();
        for(int i=0;i<v[x].size();i++)
        {
            if(visited[v[x][i]]==1&&check1[v[x][i]]==0)
            {
                q.push(v[x][i]);
                check1[v[x][i]]=1;
            }
        }
    }
    while(!q2.empty())
    {
        int x=q2.front();
        check2[x]=1;
        q2.pop();
        for(int i=0;i<v[x].size();i++)
        {
            if(visited[v[x][i]]==0&&check2[v[x][i]]==0)
            {
                q2.push(v[x][i]);
                check2[v[x][i]]=1;
            }
        }
    }

    for(int i=0;i<input1.size();i++)
    {
        if(check1[input1[i]]!=1)return ;
    }
    for(int i=0;i<input2.size();i++)
    {
        if(check2[input2[i]]!=1)return ;

    }
    ans=min(ans,abs(sum1-sum2));
    return ;
}
void back(int depth,int x)
{
    if(depth==n/2)
    {
        return ;
    }
    for(int i=x;i<=n;i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            bfs();
            back(depth+1,i+1);
            visited[i]=0;
        }
    }

}
int main()
{
    cin >>n;
    for(int i=1;i<=n;i++) cin>>dis[i];

    for(int i=1;i<=n;i++)
    {
        int s;
        cin >>s;
        for(int j=0;j<s;j++)
        {
            int a;
            cin >>a;
            v[i].push_back(a);
        }
    }
    back(0,1);
    if(ans==987654321) cout<<"-1";
    else
    cout <<ans;

    return 0;
}