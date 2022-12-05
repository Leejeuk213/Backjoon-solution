#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> box;
vector<int> crane;
int n;
int m;
int ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        crane.push_back(num);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int num;
        scanf("%d",&num);
        box.push_back(num);
    }
    sort(crane.begin(),crane.end(),greater<int>());
    sort(box.begin(),box.end(),greater<int>());
    if(box[0]>crane[0])
    {
        printf("-1");
        return 0;
    }
    while(!box.empty())
    {
        ans++;
        for(int i=0;i<crane.size();i++)
        {
            for(int j=0;j<box.size();j++)
            {
                if(box[j]<=crane[i])
                {
                    box.erase(box.begin()+j);
                    break;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}