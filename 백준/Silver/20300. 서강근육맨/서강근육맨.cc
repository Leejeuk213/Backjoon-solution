#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long> v;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        long long num;
        scanf("%lld",&num);
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    long long ans=0;
    if(n%2==1)
    {
        ans=v[v.size()-1];
        for(int i=0;i<(v.size()-1)/2;i++)
        {
            ans=max(ans,v[i]+v[v.size()-2-i]);
        }
    }
    else
    {
        for(int i=0;i<v.size()/2;i++)
        {
            ans=max(ans,v[i]+v[v.size()-i-1]);
        }
    }
    printf("%lld",ans);
    return 0;
}