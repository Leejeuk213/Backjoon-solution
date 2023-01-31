#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int,int>>a[1001];
vector<int>d(1001,987654321);

int n,m;
int start,desti;
void dijk()
{
    priority_queue<pair<int,int>>pq;
    pq.push(make_pair(start,0));
    d[start]=0;
    while (!pq.empty())
    {
        int current=pq.top().first;
        int distance=-pq.top().second;
        pq.pop();
        
        if(d[current]<distance)continue;

        for(int i=0;i<a[current].size();i++)
        {
            int next=a[current][i].first;
            int nextdistance= distance+a[current][i].second;
            if(d[next]>nextdistance)
            {
                d[next]=nextdistance;
                pq.push(make_pair(next,-nextdistance));
            }
        }
    }
    
}
int main()
{
    cin >>n>>m;
    for(int i=0;i<m;i++)
    {
        int j,k,l;
        cin >>j>>k>>l;
        a[j].push_back(make_pair(k,l));
    }
    cin >>start>>desti;
    dijk();
    cout<<d[desti];
    return 0;
}