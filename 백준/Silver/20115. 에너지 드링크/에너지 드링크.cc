#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<double> q;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        double num;
        scanf("%lf",&num);
        q.push(num);
    }
    double ans=q.top();
    //printf("%lf\n",ans);
    q.pop();
    while(!q.empty())
    {
        ans=ans+(q.top())/2.0;
        //printf("%lf\n",ans);
        q.pop();
    }
    printf("%lf",ans);
    return 0;
}