#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int a,j;
int ans=0;
int check[1000001];
char str[1000001];
vector<pair<int,char>>v;
int main()
{
    cin>>a>>j;
    for(int i=1;i<=a;i++)
    {
        cin >>str[i];
    }
    for(int i=0;i<j;i++)
    {
        char temp;
        int num;
        cin >>temp>>num;
        v.push_back(make_pair(num,temp));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        if(check[v[i].first]==0&&v[i].first<=a)
        {
            if(v[i].second=='S')
            {
                check[v[i].first]=1;
                ans++;
            }
            else if(v[i].second=='M'&&(str[v[i].first]=='M'||str[v[i].first]=='L'))
            {
                check[v[i].first]=1;
                ans++;
            }
            else if(v[i].second=='L'&&str[v[i].first]=='L')
            {
                check[v[i].first]=1;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}