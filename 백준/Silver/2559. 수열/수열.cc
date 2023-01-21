#include<iostream>
#include<vector>
using namespace std;

int k,n;
vector<int>v;
int ans=0;

void solve()
{
    int fidx=1;
    int ridx=k;
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum=sum+v[i];
    }
    ans=sum;
    while(ridx<n)
    {
        sum=sum-v[fidx-1];
        sum=sum+v[ridx];
        if(sum>ans)
        {
            ans=sum;
        }
        fidx++;
        ridx++;
    }
}
int main()
{
    cin >>n>>k;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >>num;
        v.push_back(num);
    }
    solve();
    cout <<ans;
    return 0;
}