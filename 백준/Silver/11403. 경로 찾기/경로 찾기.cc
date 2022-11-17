#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int n;
vector <int> graph[101];
int visited[101]={0,};
int floyd[101][101]={0,};
void dps(int index,int origin)
{
    if(visited[index]==1)
    {
        return;
    }
    visited[index]=1;
    for(int i=0;i<graph[index].size();i++)
    {
        floyd[origin][graph[index][i]]=1;
        if(visited[graph[index][i]]!=1)
        {
            dps(graph[index][i],origin);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&floyd[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(floyd[i][j]==1)
            {
                graph[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        dps(i,i);
        memset(visited,0,sizeof(visited));
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",floyd[i][j]);
        }
        printf("\n");
    }
    return 0;
}