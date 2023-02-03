#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m;
int INF=987654321;
vector<pair<int,int>>v[1001];
vector<int> d(1001,INF);
vector<int>route_cnt(1001);
vector<int>beforeroute(1001);
int start,desti;
vector<int>ans;
void dijk()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push(make_pair(0,start));
    d[start]=0;
    route_cnt[start]=1;
    while(!pq.empty())
    {
        int distance=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(cur==desti)break;
        if(d[cur]<distance) continue;

        for(int i=0;i<v[cur].size();i++)
        {
            int next=v[cur][i].first;
            int nextdistance = distance + v[cur][i].second;

            if(d[next]>nextdistance)
            {
                d[next]=nextdistance;
                pq.push(make_pair(nextdistance,next));
                route_cnt[next]=route_cnt[cur]+1;
                beforeroute[next]=cur;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n>>m;
    for(int i=0;i<m;i++)
    {
        int j,k,l;
        cin >>j>>k>>l;
        v[j].push_back(make_pair(k,l));
    }

    cin>>start >>desti;
    dijk();
    cout<<d[desti]<<"\n";
    cout<<route_cnt[desti]<<"\n";

    int before=desti;
    while(before)
    {
        ans.push_back(before);
        before=beforeroute[before];
    }

    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";

    return 0;
}