#include<iostream>
#include<queue>
using namespace std;
long long ans=0;
priority_queue<int,vector<int>,greater<int>>n_b;
priority_queue<int>p_b;
int n,m;
int max_index=0;
int max_num=0;
void solve()
{
    if(max_index>0)
    {
        int temp=p_b.top();
        p_b.pop();
        int cnt=1;
        while(!p_b.empty()&&cnt<m)
        {
            p_b.pop();
            cnt++;
        }
        ans=ans+temp;
    }
    else
    {
        int temp=(n_b.top())*-1;
        n_b.pop();
        int cnt=1;
        while(!n_b.empty()&&cnt<m)
        {
            n_b.pop();
            cnt++;
        }
        ans=ans+temp;
    }
    int cnt=0;
    while(!p_b.empty())
    {
        int temp=p_b.top();
        cnt=1;
        p_b.pop();
        while(!p_b.empty()&&cnt<m)
        {
            p_b.pop();
            cnt++;
        }
        ans=ans+temp*2;
    }
    while(!n_b.empty())
    {
        int temp=n_b.top()*-1;
        cnt=1;
        n_b.pop();
        while(!n_b.empty()&&cnt<m)
        {
            n_b.pop();
            cnt++;
        }
        ans=ans+temp*2;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >>num;
        int temp=0;
        if(num<0)
        {
            temp=num*-1;
            if(temp>max_num)
            {
                max_num=temp;
                max_index=-1;
            }
            n_b.push(num);
        }
        else
        {
            if(num>max_num)
            {
                max_num=num;
                max_index=1;
            }
            p_b.push(num);
        }
    }
    solve();
    cout<<ans;
    return 0;
}