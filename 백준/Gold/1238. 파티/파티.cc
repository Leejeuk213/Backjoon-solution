#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int INF=987654321;
vector<pair<int,int>>v[1001];
vector<int> d(1001,INF);
int ans=0;
vector <int> d2(1001,INF); // 집에 돌아가는 길
int n,m,x;
void dijk(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
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
            int nextdistance = distance+ v[cur][i].second;

            if(d[next]>nextdistance)
            {
                d[next]=nextdistance;
                pq.push(make_pair(nextdistance,next));
            }
        }
    }
    return ;
}
int main()
{
    cin >>n>>m>>x;

    for(int i=0;i<m;i++)
    {
        int j,k,l;
        cin >>j>>k>>l;
        v[j].push_back(make_pair(k,l));
    }
    dijk(x);
    for(int i=1;i<=n;i++)d2[i]=d[i];

    for(int i=1;i<=n;i++)
    {
        d.assign(1001,INF);
        dijk(i);
        ans=max(ans,d[x]+d2[i]);
    }
    cout<<ans;
    return 0;
}