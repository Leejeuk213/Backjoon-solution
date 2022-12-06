#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
stack<pair<int,int>>s;
int n;
int ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);    
        while(!s.empty()&&s.top().second>y)
        {
            ans++;
            s.pop();
        }
        if(!s.empty()&&s.top().second==y)
        {
            ;
        }
        else
        {
            s.push(make_pair(x,y));
        }
    }
    while(!s.empty())
    {
        if(s.top().second>0)
        {
        ans++;
        }
        s.pop();
    }
    printf("%d",ans);
    return 0;
}