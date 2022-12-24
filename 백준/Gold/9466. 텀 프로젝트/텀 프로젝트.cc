#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
int check[100001];
int st[100001];
vector<int>temp;
vector<int>ans;
int dfs(int x)
{
    if(check[x]==1)
    {
        return x;
    }
    check[x]=1;
    int y=dfs(st[x]);
    temp.push_back(x);
    if(x==y)
    {
        for(int i=0;i<temp.size();i++)
        {
            ans.push_back(temp[i]);
        }
    }
    return y;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        memset(check,0,sizeof(check));
        ans.clear();
        for(int j=1;j<=m;j++)
        {
            cin>>st[j];
        }
        for(int j=1;j<=m;j++)
        {
            if(check[j]==0)
            {
                dfs(j);
                temp.clear();
            }
        }
        cout<<m-ans.size()<<"\n";
    }
}