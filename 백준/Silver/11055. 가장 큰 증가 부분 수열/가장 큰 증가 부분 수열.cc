#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int ans=0;
vector<int>v;
int dp[1001];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
        dp[i]=v[i];
    }
    ans=dp[0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[j]<v[i])
            {
                dp[i]=max(dp[i],dp[j]+v[i]);
            }
            ans=max(ans,dp[i]);
        }
    }
    cout<<ans;
    return 0;
}