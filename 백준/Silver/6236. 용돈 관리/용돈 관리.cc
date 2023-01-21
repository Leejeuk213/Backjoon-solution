#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
vector<int>v;
int ans;
int sum=0;
int main()
{
    cin >>n>>m;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >>num;
        v.push_back(num);
        sum=sum+num;
    }
    int left=1;
    int ans=sum;
    int right=sum;
    int cnt=0;
    int result;
    while(left<=right)
    {
        cnt=1;
        int check=0;
        int mid=(left+right)/2;
        int have=mid;
        for(int i=0;i<v.size();i++)
        {
            if(mid<v[i])
            {
                check=1;
                break;
            }
            if(v[i]>have)
            {
                have=mid;
                cnt++;
            }
            have=have-v[i];
            if(cnt>m)
            {
                break;
            }
        }
        if(cnt>m||check)
        {
            left=mid+1;
        }
        else
        {
            ans=mid;
            right=mid-1;
        }
    }
    cout <<ans;

    return 0;
}