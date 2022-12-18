#include<iostream>
#include<queue>
using namespace std;
int n,m;
long long ans=0;
priority_queue<long long,vector<long long>,greater<long long>>q;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;
        q.push(num);
    }
    for(int i=0;i<m;i++)
    {
        long long num1=q.top();
        q.pop();
        long long num2=q.top();
        q.pop();
        q.push(num1+num2);
        q.push(num1+num2);
    }
    while(!q.empty())
    {
        ans=ans+q.top();
        q.pop();
    }
    cout<<ans;
    return 0;
}