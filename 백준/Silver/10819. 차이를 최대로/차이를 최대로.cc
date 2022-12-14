#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int check[9];
int n;
int ans=0;
vector<int> v;
void back(int depth,int sum,int before)
{
    if(depth==n-1)
    {
        if(ans<sum)
        {
            ans=sum;
        }
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(check[i]==0)
        {
            check[i]=1;
            int temp=before-v[i];
            if(temp<0)
            {
                temp=temp*-1;
            }
            back(depth+1,sum+temp,v[i]);
            check[i]=0;
        }
    }
}
int main()
{
    cin >>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >>num;
        v.push_back(num);
    }
    for(int i=0;i<n;i++)
    {
        check[i]=1;
        back(0,0,v[i]);
        memset(check,0,sizeof(check));
    }
    cout<<ans;
    return 0;
}