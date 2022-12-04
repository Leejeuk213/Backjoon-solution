#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
queue<pair<int,int>>q;
vector<int> v;
int sum=0;
int main()
{
    for(int i=0;i<9;i++)
    {
        int num;
        scanf("%d",&num);
        v.push_back(num);
        sum=sum+num;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<8;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(sum-v[i]-v[j]==100)
            {
                q.push(make_pair(i,j));
            }
        }
    }
    int first=q.front().first;
    int second=q.front().second;
    for(int i=0;i<9;i++)
    {
        if(i!=first&&i!=second)
        {
            printf("%d\n",v[i]);
        }
    }
    return 0;
}