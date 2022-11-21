#include<stdio.h>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>>q;
int n,l;

int main()
{
    scanf("%d %d",&n,&l);
    for(int i=0;i<n;i++)
    {
        int r;
        scanf("%d",&r);
        q.push(r);
    }
    int ans=0;
    while(!q.empty())
    {
        int temp=q.top();
        int len=1;
        ans++;
        q.pop();
        while(len<=l&&!q.empty())
        {
            len=len+q.top()-temp;
            if(len>l)
            {
                break;
            }
            temp=q.top();
            q.pop();
        }
    }
    printf("%d",ans);
    return 0;

}