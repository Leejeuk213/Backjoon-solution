#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int check[10001];
vector<int> ans;
vector<int> v;
void dfs(int depth)
{
    if(depth==m)
    {
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return;
    }   
    for(int i=0;i<n;i++)
    {
        if(check[v[i]]==0)
        {
            check[v[i]]=1;
            ans.push_back(v[i]);
            dfs(depth+1);
            check[v[i]]=0;
            ans.pop_back();
        }
    }
}
int main()
{
    cin >>n>>m;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    dfs(0);
    return 0;
}