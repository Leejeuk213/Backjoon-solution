#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
priority_queue<int,vector<int>,greater<int>>q2;
vector<pair<int,int>>v;
int n;
long long ans=0;
int main()
{   
    cin >>n;
    for(int i=0;i<n;i++)
    {
        int e,w;
        cin >>e>>w;
        v.push_back(make_pair(w,e));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        q2.push(v[i].second);
        ans=ans+v[i].second;
        if(v[i].first<q2.size())
        {
            ans=ans-q2.top();
            q2.pop();
        }
    }
    cout<<ans;
    return 0;
}