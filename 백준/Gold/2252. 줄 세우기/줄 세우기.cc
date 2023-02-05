#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m;
vector <int> v[32001];
int cnt[32001];
vector<int>ans;

void solve()
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==0)
        {
            ans.push_back(i);
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++)
        {
            cnt[v[x][i]]--;
            if(cnt[v[x][i]]==0)
            {
                q.push(v[x][i]);
                ans.push_back(v[x][i]);
            }
        }
    }
}
int main()
{
    cin >>n>>m;

    for(int i=0;i<m;i++)
    {
        int q,w;
        cin >>q>>w;
        v[q].push_back(w);
        cnt[w]++;
    }
    solve();
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}