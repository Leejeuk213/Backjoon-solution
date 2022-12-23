#include<iostream>
#include<vector>
using namespace std;
int ans[100001];
vector<int>v[100001];
int check[100001];
int n;
void dfs(int x)
{
    check[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        if(check[v[x][i]]==0)
        {
            check[v[x][i]]=1;
            ans[v[x][i]]=x;
            dfs(v[x][i]);
        }
    }
}
int main()
{
    cin >>n;
    for(int i=0;i<n-1;i++)
    {
        int q,w;
        cin >>q>>w;
        v[q].push_back(w);
        v[w].push_back(q);
    }
    for(int i=1;i<=n;i++)
    {
        if(check[i]==0)
        {
            dfs(i);
        }
    }
    for(int i=2;i<=n;i++)
    {
        cout<<ans[i]<<"\n";
    }
    return 0; 
}