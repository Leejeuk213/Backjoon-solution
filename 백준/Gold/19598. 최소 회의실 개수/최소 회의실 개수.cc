#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
priority_queue<int,vector<int>,greater<int>>q2;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,r;
        scanf("%d %d",&x,&r);
        q.push(make_pair(x,r));
    }
    int ans=0;
    while(!q.empty())
    {
        int x=q.top().first;
        int y=q.top().second;
        q.pop();
        if(q2.empty())
        {
            ans++;
            q2.push(y);
        }
        else
        {
            if(x<q2.top())
            {
                ans++;
                q2.push(y);
            }
            else
            {
                q2.pop();
                q2.push(y);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
