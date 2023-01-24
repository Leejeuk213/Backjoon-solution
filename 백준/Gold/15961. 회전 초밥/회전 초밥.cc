#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,d,k,c;
int v[3003001];
int m[3001];
int ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n>>d>>k>>c;
    m[c]=987654321;
    for(int i=0;i<n;i++)
    {
        cin >>v[i];
        if(i<k-1)
        {
            v[n+i]=v[i];
        }
    }
    int cnt=1;
    for(int i=0;i<k;i++)
    {
        if(m[v[i]]==0)
        {
            cnt++;
        }
        m[v[i]]++;
        ans=max(ans,cnt);
    }

    for(int i=1;i<n;i++)
    {
        m[v[i-1]]--;
        if(m[v[i-1]]==0)
        {
            cnt--;
        }

        if(m[v[k+i-1]]==0)
        {
            cnt++;
        }
        m[v[k+i-1]]++;

        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}