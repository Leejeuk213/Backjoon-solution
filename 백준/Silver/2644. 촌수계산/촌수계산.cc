#include<iostream>
#include<vector>
using namespace std;
vector<int>v[101];
int check[101];
int n;
int m;
int x,y;
void dfs(int depth,int index)
{
    if(index==y)
    {
        cout<<depth;
        exit(0);
    }
    for(int i=0;i<v[index].size();i++)
    {
        if(check[v[index][i]]==0)
        {
            check[v[index][i]]=1;
            dfs(depth+1,v[index][i]);
        }
    }
}
int main()
{
    cin>>n>>x>>y>>m;
    for(int i=0;i<m;i++)
    {
        int q,w;
        cin>>q>>w;
        v[q].push_back(w);
        v[w].push_back(q);
    }
    dfs(0,x);
    cout<<"-1";
    return 0;
}