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
    int j=1;
    long long ans=0;
    while(!q.empty())
    {
        int temp=q.top()-(j-1);
        if(temp<0)
        {
            j++;
            q.pop();
            continue;
        }
        else
        {
            ans=ans+temp;
            j++;
            q.pop();
        }
    }
    printf("%lld",ans);
    return 0;
}