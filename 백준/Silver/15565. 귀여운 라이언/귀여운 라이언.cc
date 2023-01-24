#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int n,k;
vector<int>v;
int ans=987654321;
map <int,int> m;
int main()
{
    cin >>n>>k;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >>num;
        v.push_back(num);
    } 
    int start=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        m[v[i]]++;
        cnt++;
        if(m[1]==k)
        {
            ans=min(ans,cnt);
            while(1)
            {
                m[v[start++]]--;
                if(start==n)
                {
                    break;
                }
                cnt--;
                if (m[1]==k-1 && v[start]==1)
                {
                    break;
                }
            }
        }
    }
    if(ans==987654321)
    {
        cout<<-1;
        return 0;
    }
    cout<<ans;
    return 0;
}