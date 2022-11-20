#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>jem;
priority_queue<long long>jem_ans;
priority_queue<long long,vector<long long>,greater<long long>>bag;
int main()
{
    int n,k;
    long long ans=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        long long q,w;
        scanf("%lld %lld",&q,&w);
        jem.push(make_pair(q,w));
    }
    for(int i=0;i<k;i++)
    {
        long long f;
        scanf("%lld",&f);
        bag.push(f);
    }
    while(!bag.empty())
    {
        long long bag_temp=bag.top();
        bag.pop();
        while(jem.top().first<=bag_temp&&!jem.empty())
        {
            jem_ans.push(jem.top().second);
            jem.pop();
        }
        if(!jem_ans.empty())
        {
            ans=ans+jem_ans.top();
            jem_ans.pop();
        }
    }
    printf("%lld",ans);
    return 0;
}