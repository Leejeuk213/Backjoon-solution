#include<stdio.h>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>>nq;
priority_queue<int,vector<int>,less<int>>pq;
int n;
int max(int a,int b)
{
    if(a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int r;
        scanf("%d",&r);
        if(r<=0)
        {
            nq.push(r);
        }
        else
        {
            pq.push(r);
        }
    }
    long long ans=0;
    while(!nq.empty())
    {
        int temp1=nq.top();
        int temp2;
        nq.pop();
        if(nq.empty()==1)
        {
            ans=ans+temp1;
            break;
        }
        else
        {
            temp2=nq.top();
        }
        ans=ans+max(temp1*temp2,temp1+temp2);
        nq.pop();
    }
    while(!pq.empty())
    {
        int temp1=pq.top();
        int temp2;
        pq.pop();
        if(pq.empty()==1)
        {
            ans=ans+temp1;
            break;
        }
        else
        {
            temp2=pq.top();
        }
        ans=ans+max(temp1*temp2,temp1+temp2);
        pq.pop();
    }
    printf("%lld",ans);
    return 0;
}