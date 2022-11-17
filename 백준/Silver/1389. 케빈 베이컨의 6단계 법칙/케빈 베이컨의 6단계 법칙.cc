#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> a[101];
int visited[101];
queue<int> b;
int n,m,first;
int cnt=1;
int sum[101]={0,};
int ans[101]={0,};
void bfs(int index)
{
    visited[index]=1;
    b.push(index);
    while(!b.empty())
    {
        int i=b.front(); b.pop();
        for(int j=a[i].size()-1;j>=0;j--)
        {
            if(visited[a[i][j]]!=1)
            {
                visited[a[i][j]]=1;
                
                b.push(a[i][j]);
                sum[a[i][j]]=sum[i]+1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans[index]=ans[index]+sum[i];
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        sort(a[i].begin(),a[i].end());
    }
    for(int i=1;i<=n;i++)
    {
        bfs(i);
        for(int j=1;j<=n;j++)
        {
            ans[i]=ans[i]+sum[j];
        }
        memset(visited,0,sizeof(visited));
        memset(sum,0,sizeof(sum));
    }
    int small=100000000;
    int small_idx=0;
    for(int i=1;i<=n;i++)
    {   
        if(small>ans[i])
        {
            small=ans[i];
            small_idx=i;
        }
    }
    printf("%d",small_idx);
    return 0;
}