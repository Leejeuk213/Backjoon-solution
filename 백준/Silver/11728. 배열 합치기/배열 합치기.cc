#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
vector<int>a;
vector<int>b;
vector<int>ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n>>m;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >>num;
        a.push_back(num);
    }

    for(int i=0;i<m;i++)
    {
        int num;
        cin >>num;
        b.push_back(num);
    }
    int aidx=0;
    int bidx=0;
    while(ans.size()<n+m)
    {
        if(aidx==a.size()||bidx==b.size())
        {
            for(int i=aidx;i<a.size();i++)
            {
                ans.push_back(a[i]);
            }
            for(int i=bidx;i<b.size();i++)
            {
                ans.push_back(b[i]);
            }
            break;
        }
        if(a[aidx]>=b[bidx])
        {
            ans.push_back(b[bidx]);
            bidx++;
        }
        else
        {
            ans.push_back(a[aidx]);
            aidx++;
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}