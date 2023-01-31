#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


int n,m,k,x;
vector<int>v[300001];
int visit[300001];
vector<int>ans;
void bfs(int start)
{
    queue<pair<int,int>>q;
    q.push(make_pair(start,0));
    visit[start]=1;
    while(!q.empty())
    {
        int current=q.front().first;
        int cnt=q.front().second;
        if(cnt==k)ans.push_back(current);
        q.pop();
        for(int i=0;i<v[current].size();i++)
        {
            int next=v[current][i];
            if(visit[next]==0)
            {
                visit[next]=1;
                q.push(make_pair(next,cnt+1));
            }
        }
    }
    return ;
}

int main()
{
    cin >>n>>m>>k>>x;
    for(int i=0;i<m;i++)
    {
        int q,w;
        cin >>q>>w;
        v[q].push_back(w);
    }
    bfs(x);
    if(ans.size()==0)cout<<"-1";
    else{
        sort(ans.begin(),ans.end());
        for(auto a:ans)
        {
            cout<<a<<"\n";
        }
    }
    return 0;
}