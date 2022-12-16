#include<iostream>
#include<string.h>
using namespace std;
long long ans=987654321;
int n;
int town[11][11];
int check[11];
int start_index=0;
void dfs(int depth,long long sum,int index)
{
    if(depth==n)
    {
        if(ans>sum)
        {
            ans=sum;
        }
        return ;
    }
    if(depth==n-1)
    {
        if(town[index][start_index]!=0)
        {
            dfs(depth+1,sum+town[index][start_index],start_index);
        }
        return;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(check[i]==0&&town[index][i]!=0)
            {
                check[index]=1;
                dfs(depth+1,sum+town[index][i],i);
                check[index]=0;
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >>town[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        start_index=i;
        for(int j=0;j<n;j++)
        {
            if(town[i][j]!=0)
            {
                memset(check,0,sizeof(check));
                check[i]=1;
                dfs(1,town[i][j],j);
            }
        }
    }
    cout<<ans;
    return 0;
}