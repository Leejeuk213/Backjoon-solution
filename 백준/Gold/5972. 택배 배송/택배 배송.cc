#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
vector<pair<int,int>>v[50001];
vector<int>cow(50001,987654321);
int ans=0;
void dijk(int start)
{
    priority_queue<pair<int,int>>pq;
    pq.push(make_pair(start,0));
    cow[start]=0;
    while (!pq.empty())
    {
        int current=pq.top().first;
        int distance=pq.top().second;

        if(distance<0)distance=-distance;

        pq.pop();

        if(cow[current]<distance)continue;

        for(int i=0;i<v[current].size();i++)
        {
            int next=v[current][i].first;
            int nextdistance=distance+v[current][i].second;
            if(cow[next]>nextdistance)
            {
                cow[next]=nextdistance;
                pq.push(make_pair(next,-nextdistance));
            }
        }
    }
    
    return ;
}
int main()
{
    cin >>n>>m;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<m;i++)
    {
        int j,k,l;
        cin >>j>>k>>l;
        v[j].push_back(make_pair(k,l));
        v[k].push_back(make_pair(j,l));
    }

    dijk(1);
    cout<<cow[n];

    return 0;
}