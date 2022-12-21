#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int ans=0;
int n;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end(),greater<int>());
    while(!v.empty())
    {
        if(ans==1440)
        {
            ans=-1;
            break;
        }
        if(v.size()==1)
        {
            v[0]=v[0]-1;
            ans++;
            if(v[0]==0)
            {
                v.erase(v.begin());
            }
        }
        else
        {
            for(int i=0;i<2;i++)
            {
                v[i]=v[i]-1;
            }
            for(int i=1;i>=0;i--)
            {
                if(v[i]==0)
                {
                    v.erase(v.begin()+i);
                }
            }
            ans++;
        }
        sort(v.begin(),v.end(),greater<int>());
    }
    cout<<ans;
    return 0;
}