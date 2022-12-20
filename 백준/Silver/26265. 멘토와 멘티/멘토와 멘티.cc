#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct compare{

    bool operator()(pair<string,string>a,pair<string,string> b)
    {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        return a.first>b.first;
    }
};
priority_queue<pair<string,string>,vector<pair<string,string>>,compare>q;
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a;
        string b;
        cin>>a>>b;
        q.push(make_pair(a,b));
    }
    for(int i=0;i<n;i++)
    {
        cout<<q.top().first<<" "<<q.top().second<<"\n";
        q.pop();
    }
    return 0;
}
