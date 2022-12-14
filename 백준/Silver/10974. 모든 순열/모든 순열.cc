#include<iostream>
#include<vector>
using namespace std;
int n;
int check[9];
vector<int> v;
void dfs(int depth)
{
    if(depth==n)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        return;
    }   
    for(int i=1;i<=n;i++)
    {
        if(check[i]==0)
        {
            check[i]=1;
            v.push_back(i);
            dfs(depth+1);
            check[i]=0;
            v.pop_back();
        }
    }
}
int main()
{
    cin >>n;
    dfs(0);
    return 0;
}