#include<iostream>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int n;
int ok=1;
int graph[101];
int check[101];
int anscheck[101];
vector<int>ans;
vector<int>top;
vector<int>bot;
void dfs(int index)
{
    check[index]=1;
    top.push_back(index);
    bot.push_back(graph[index]);
    if(check[graph[index]]==0)
    {
        dfs(graph[index]);
    }
    return;
}
int main()
{
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        cin>>graph[i];
    }
    for(int i=1;i<=n;i++)
    {
        top.clear();
        bot.clear();
        memset(check,0,sizeof(check));
        ok=1;
        dfs(i);
        sort(top.begin(),top.end());
        sort(bot.begin(),bot.end());
        for(int j=0;j<top.size();j++)
        {
            if(top[j]!=bot[j])
            {
                ok=0;
            }
        }
        if(ok)
        {
            for(int j=0;j<top.size();j++)
            {
                if(anscheck[top[j]]==0)
                {
                    anscheck[top[j]]=1;
                    ans.push_back(top[j]);
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}