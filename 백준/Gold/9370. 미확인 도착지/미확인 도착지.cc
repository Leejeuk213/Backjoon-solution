#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int INF = 987654321;
vector<pair<int,int>> v[2001];
vector<vector<int>> d(3, vector<int>(2001));
vector <int> l;
vector <int> ansg;
vector <int> ansh;
vector<int> ans;
int n,m,t,s,g,h;
void dijk(int start,int z)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>q;
    q.push(make_pair(0,start));
    d[z][start]=0;
    while(!q.empty())
    {
        int distance = q.top().first;
        int current = q.top().second;
        q.pop();
        if(d[z][current]<distance) continue;

        for(int i=0;i<v[current].size();i++)
        {
            int next = v[current][i].first;
            int nextdistance = distance + v[current][i].second;

            if(d[z][next]>nextdistance)
            {
                d[z][next] = nextdistance ;
                q.push(make_pair(nextdistance,next));
            } 
        }
    }
}
int main()
{
    int roop;
    cin >>roop;
    while(roop--)
    {
        fill(d.begin(), d.end(), vector<int>(2001, INF));
        ans.clear();
        for(int i=0;i<2001;i++) v[i].clear();
        l.clear();
        ansg.clear();
        ansh.clear();
        cin >>n>>m>>t;
        cin >>s>>g>>h;
        int gh;
        for(int i=0;i<m;i++)
        {
            int z,x,c;
            cin >>z>>x>>c;
            if((z==g&&x==h)||(z==h&&x==g)) gh = c; // gh 거리
            v[z].push_back(make_pair(x,c));
            v[x].push_back(make_pair(z,c));
        }
        for(int i=0;i<t;i++)
        {
            int num;
            cin >>num;
            l.push_back(num);
        }
        sort(l.begin(),l.end());
        dijk(s,0);
        dijk(g,1);
        dijk(h,2);
        
        for(int i=0;i<t;i++)
        {
            ansg.push_back(d[0][l[i]] - gh - d[0][g]);
            ansh.push_back(d[0][l[i]] - gh - d[0][h]);
        }
            
        for(int i=0;i<t;i++)
        {
            if(d[1][l[i]]==ansh[i] || d[2][l[i]]==ansg[i]) ans.push_back(l[i]);
        }
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}