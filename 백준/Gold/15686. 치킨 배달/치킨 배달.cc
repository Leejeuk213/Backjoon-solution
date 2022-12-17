#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int ans=987654321;
int town[51][51];
int check[51][51];
vector<pair<int,int>>v;
int cut(int x,int y,int z)
{
    int num1=v[z].first;
    int num2=v[z].second;
    int ans1=0;
    int ans2=0;
    if(num1>=x)
    {
        ans1=num1-x;
    }
    else
    {
        ans1=x-num1;
    }
    if(num2>=y)
    {
        ans2=num2-y;
    }
    else
    {
        ans2=y-num2;
    }
    return ans1+ans2;
}
void counting()
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int temp=987654321;
            if(town[i][j]==1)
            {
                for(int k=0;k<v.size();k++)
                {
                    temp=min(temp,cut(i,j,k));
                }
                sum=sum+temp;
            }
            if(ans<sum)
            {
                return;
            }
        }
    }
    if(ans>sum)
    {
        ans=sum;
    }
    return ;
}
void back(int depth,int index)
{
    if(depth==m)
    {
        counting();
        return;
    }
    for(int i=index;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(check[i][j]==0&&town[i][j]==2)
            {
                check[i][j]=1;
                v.push_back(make_pair(i,j));
                back(depth+1,i);
                v.pop_back();
                check[i][j]=0;
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>town[i][j];
        }
    }
    back(0,0);
    cout<<ans;
    return 0;
}