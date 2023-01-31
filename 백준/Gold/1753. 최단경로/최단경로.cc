#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int,int>>v[20001];
vector<int>d(20001,987654321);
int n,m;
int start;
void dijk()
{
    priority_queue<pair<int,int>,vector<pair<int ,int>>,greater<>>pq;
    d[start]=0;
    pq.push(make_pair(0,start));
    while (!pq.empty())
    {
        int current =pq.top().second;
        int distance =pq.top().first;
        //cout<<current<<" "<<distance<<"\n";
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
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n>>m>>start;
    for(int i=0;i<m;i++)
    {
        int q,w,e;
        cin >>q>>w>>e;
        v[q].push_back(make_pair(w,e));
    }
    dijk();
    for(int i=1;i<=n;i++)
    {
        if(d[i]==987654321) cout<<"INF"<<"\n";
        else cout<<d[i]<<"\n";
    }
    return 0;
}