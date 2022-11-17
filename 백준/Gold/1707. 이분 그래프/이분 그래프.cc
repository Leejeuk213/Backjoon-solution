#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int v,e;
vector<int>graph[20001];
int color[20001]={0,};
int visit[20001]={0,};
int bfs(int index)
{
    queue<int> q;
    q.push(index);
    visit[index]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<graph[x].size();i++)
        {
            if(visit[graph[x][i]]==0)
            {
                visit[graph[x][i]]=1;
                if(color[x]==0)
                {
                    color[graph[x][i]]=1;
                }
                else
                {
                    color[graph[x][i]]=0;
                }
                q.push(graph[x][i]);
            }
            else if(visit[graph[x][i]]==1)
            {
                if(color[x]==color[graph[x][i]])
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
int main()
{
    int k;
    scanf("%d",&k);

    for(int i=0;i<k;i++)
    {
        scanf("%d %d",&v,&e);
        int ans=0;
        for(int j=0;j<e;j++)
        {
            int num1,num2;
            scanf("%d %d",&num1,&num2);
            graph[num1].push_back(num2);
            graph[num2].push_back(num1);
        }
        for(int k=1;k<=v;k++)
        {
            sort(graph[k].begin(),graph[k].end());
        }
        for(int j=1;j<=v;j++)
        {
            ans=bfs(j);
            if(ans==0)
            {
                break;
            }
        }
        if(ans==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        for(int k=1;k<=v;k++)
        {
            graph[k].clear();
        }
        memset(visit,0,sizeof(visit));
        memset(color,0,sizeof(color));
    }
    return 0;
}