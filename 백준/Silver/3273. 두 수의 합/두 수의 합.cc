#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,x;
vector<int>a;
int ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >>num;
        a.push_back(num);
    }
    cin >>x;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
    {
        for(int j=i+1;j<a.size();j++)
        {
            if(a[i]+a[j]==x)
            {
                ans++;
                break;
            }
            else if(a[i]+a[j]>x)
            {
                break;
            }
        }
    }
    cout <<ans;
    return 0;
}