#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int>> num;
int main()
{
    int ans=0;
    int roop;
    scanf("%d",&roop);
    for(int i=0;i<roop;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        num.push_back(make_pair(v,u));
    }
    sort(num.begin(),num.end());
    ans=1;
    int time=num[0].first;
    for(int i=1;i<roop;i++)
    {
        if(num[i].second>=time)
        {
            ans++;
            time=num[i].first;        
        }
    }
    printf("%d",ans);
    return 0;
}