#include<iostream>
#include<vector>
using namespace std;
int n,x;
int ans=0;
int cnt=0;
vector<int>v;
void solve()
{
    int fidx=1;
    int ridx=x;
    int sum=0;
    for(int i=0;i<=x-1;i++)
    {
        sum=sum+v[i];
    }
    ans=sum;
    cnt=1;
    while(ridx<n)
    {
        sum=sum-v[fidx-1];
        sum=sum+v[ridx];
        if(ans==sum)
        {
            cnt++;
        }
        if(ans<sum)
        {
            ans=sum;
            cnt=1;
        }
        fidx++;
        ridx++;
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >>num;
        v.push_back(num);
    }
    solve();
    if(ans==0)
    {
        cout<<"SAD";
    }
    else
    {
        cout<<ans<<"\n"<<cnt;
    }
    return 0;
}