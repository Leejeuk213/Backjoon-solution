#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    for(int i=0;i<test;i++)
    {
        int roop;
        scanf("%d",&roop);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int j=0;j<roop;j++)
        {
            int x,r;
            scanf("%d %d",&x,&r);
            q.push(make_pair(x,r));
        }
        int handler=100001;
        int ans=0;
        for(int j=0;j<roop;j++)
        {
            int ry=q.top().first;
            int rx=q.top().second;
            q.pop();
            if(handler>rx)
            {
                handler=rx;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}