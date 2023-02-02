#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int INF=987654321;
int n,e;
vector<pair<int,int>>v[801];
vector<int>d(801,INF);
int ans=0;
int v1,v2;

void dijk(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push(make_pair(0,start));
    d[start]=0;
    while(!pq.empty())
    {
        int current=pq.top().second;
        int distance=pq.top().first;
        pq.pop();
        if(d[current]<distance)continue;

        for(int i=0;i<v[current].size();i++)
        {
            int next=v[current][i].first;
            int nextdistance=distance+v[current][i].second;
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
    cin >>n>>e;

    for(int i=0;i<e;i++)
    {
        int j,k,l;
        cin >>j>>k>>l;
        v[j].push_back(make_pair(k,l));
        v[k].push_back(make_pair(j,l));
    }
    cin >>v1>>v2;

    bool flag1,flag2;
    flag1=true;
    flag2=true;

    dijk(1);
    int route1=d[v1];
    int route2=d[v2];
    if(route1==INF)flag1=false;
    if(route2==INF)flag2=false;

    d.assign(801,INF);
    dijk(v2);
    if(flag1==true)route1+=d[v1];
    if(flag2==true)route2+=d[v1];

    d.assign(801,INF);
    dijk(v2);
    if(flag1==true)route1+=d[n];

    d.assign(801,INF);
    dijk(v1);
    if(flag2==true)route2+=d[n];


    ans=min(route1,route2);
    if(ans>=INF)cout<<"-1";
    else
    cout <<ans;
    return 0;
}