#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<vector>
using namespace std;
priority_queue<pair<int,char>>q;
string str[10];
vector<char> v[9];
map<char,int>m;
map<char,int>cnt;
int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin >>str[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<str[i].size();j++)
        {
            v[str[i].size()-j].push_back(str[i][j]);
        }
    }
    int k=9;
    for(int i=8;i>=1;i--)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cnt[v[i][j]]=cnt[v[i][j]]+(int)pow(10,i-1);
            //cout <<v[i][j]<<" "<<cnt[v[i][j]]<<"\n";
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<str[i].size();j++)
        {
            q.push(make_pair(cnt[str[i][j]],str[i][j]));
        }
    }
    while(!q.empty())
    {
        char a=q.top().second;
        q.pop();
        if(m.count(a)==0)
        {
            m[a]=k;
           // cout <<a<<" "<<k<<"\n";
            k--;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<str[i].size();j++)
        {
            ans=ans+pow(10,str[i].size()-j-1)*m[str[i][j]];
            //printf("%d\n",ans);
        }
    }
    printf("%d",ans);
    return 0;
}