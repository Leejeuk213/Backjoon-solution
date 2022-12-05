#include<stdio.h>
#include<vector>
#include<algorithm>
int n,k;
using namespace std;
vector<int> v;
vector<int> v2;
long long ans=0;
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        v.push_back(num);
    }
    for(int i=0;i<n-1;i++)
    {
        v2.push_back(v[i+1]-v[i]);
    }
    sort(v2.begin(),v2.end());
    for(int i=0;i<n-k;i++)
    {
        ans=ans+v2[i];
    }
    printf("%lld",ans);
    return 0;
}