#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> a[1001];
int visited[1001];
queue<int> b;
int n,m,first;
void dfs(int index)
{
    if(visited[index]==1)
    {
        return;
    }
    visited[index]=1;
    printf("%d ",index);
    int i=index;
        for(int j=0;j<a[i].size();j++)
        {
            if(visited[a[i][j]]!=1)
            {
                dfs(a[i][j]);
            }
        }
}
void bfs(int index)
{
    if(visited[index]==1)   
    {
        return;
    }
    visited[index]=1;
    b.push(index);
    while(!b.empty())
    {
        int i=b.front(); b.pop();
        printf("%d ",i);
        for(int j=0;j<a[i].size();j++)
        {
            if(visited[a[i][j]]!=1)
            {
                visited[a[i][j]]=1;
                b.push(a[i][j]);
            }
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&m,&first);
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

    dfs(first);
    memset(visited,0,sizeof(visited));
    printf("\n");
    bfs(first);
    return 0;
}