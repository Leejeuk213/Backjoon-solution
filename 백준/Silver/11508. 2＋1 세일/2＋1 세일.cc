#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int> q;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        q.push(num);
    }
    int j=0;
    long long ans=0;
    while(!q.empty())
    {
        j++;
        if(j==3)
        {
            j=0;
            q.pop();
            continue;
        }
        else
        {
            ans=ans+q.top();
            q.pop();
        }
    }
    printf("%lld",ans);
    return 0;
}