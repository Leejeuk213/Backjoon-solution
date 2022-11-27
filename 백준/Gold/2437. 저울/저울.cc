#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>>q;
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        q.push(num);
    }
    int i=1;
    while(!q.empty())
    {
        if(i<q.top())
        {
            break;
        }
        i=i+q.top();
        q.pop();
    }
    printf("%d",i);
    return 0;
}