#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
vector<int>sensor;
priority_queue<int,vector<int>,greater<int>>q;
int n,k;
int ans=0;
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        sensor.push_back(num);
    }
    sort(sensor.begin(),sensor.end());
    for(int i=0;i<n-1;i++)
    {
        q.push(sensor[i+1]-sensor[i]);
    }
    for(int i=0;i<n-k;i++)
    {
        ans=ans+q.top();
        q.pop();
    }
    printf("%d",ans);
    return 0; 
}