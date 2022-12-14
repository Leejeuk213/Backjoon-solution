#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int n,k;
vector<int> v[10001];
vector<int> ans;
int maxans=0;
int check[10001];
int cnt=0;
void dfs(int index)
{
    for(int i=0;i<v[index].size();i++)
    {
        if(check[v[index][i]]==0)
        {
            check[v[index][i]]=1;
            cnt++;
            dfs(v[index][i]);
        }
    }
}
int main()
{
    cin >>n>>k;
    for(int i=0;i<k;i++)
    {
        int q,w;
        cin >>q>>w;
        v[w].push_back(q);
    }
    for(int i=1;i<=n;i++)
    {
        memset(check,0,sizeof(check));
        check[i]=1;
        dfs(i);
        if(maxans<cnt+1)
        {
            maxans=cnt+1;
            ans.clear();
            ans.push_back(i);
        }
        else if(maxans==cnt+1)
        {
            ans.push_back(i);
        }
        cnt=0;
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}