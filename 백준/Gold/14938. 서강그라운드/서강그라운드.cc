#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int space[101];
vector<pair<int,int>> v[101];
int n,m,r;
int d[101];
int INF=987654321;
int ans=0;
void dijk(int start)
{
    priority_queue<pair<int,int>>pq;
    pq.push(make_pair(0,start));
    d[start]=0;
    while(!pq.empty())
    {
        int distance=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(d[cur]<distance) continue;

        for(int i=0;i<v[cur].size();i++)
        {
            int next=v[cur][i].first;
            int nextdistance = distance + v[cur][i].second;

            if(d[next]>nextdistance)
            {
                d[next]=nextdistance;
                pq.push(make_pair(nextdistance,next));
            }
        }
    }
}
int main()
{
    cin>> n>>m>>r;
    for(int i=1;i<=n;i++)cin>>space[i];

    for(int i=0;i<r;i++)
    {
        int j,k,l;
        cin >>j>>k>>l;
        v[j].push_back(make_pair(k,l));
        v[k].push_back(make_pair(j,l));
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)d[j]=INF;
        int sum=0;
        dijk(i);

        for(int j=1;j<=n;j++)
        {
            if(j==i)
            {
                sum=sum+space[j];
                continue;
            }
            if(d[j]<=m)
            {
                sum=sum+space[j];
            }
        }
        ans=max(ans,sum);
    }
    cout <<ans;
    return 0;
}