#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
int ans=0;
vector<int>v;

void solve()
{
    int fidx=0;
    int ridx=0;
    while(fidx<n)
    {
        int sum=v[fidx];
        for(int i=ridx+1;i<n;i++)
        {
            sum=sum+v[i];
            if(sum==m)
            {
                //cout <<sum-v[i]<<" "<<v[i]<<"\n";
                ans++;
            }
            sum=sum-v[i];
        }
        fidx++;
        ridx=fidx;
    }
    return ;
}

int main()
{
    cin >>n>>m;
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