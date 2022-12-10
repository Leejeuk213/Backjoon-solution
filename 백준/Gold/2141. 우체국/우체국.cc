#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<pair<long long,long long>> v;
long long sum=0;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        long long num1,num2;
        scanf("%lld %lld",&num1,&num2);
        v.push_back(make_pair(num1,num2));
        sum=sum+num2;
    }
    long long cur=0;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        cur=cur+v[i].second;
        if(cur>=(sum+1)/2)
        {
            printf("%lld",v[i].first);
            return 0;
        }
    }
    return 0;
}