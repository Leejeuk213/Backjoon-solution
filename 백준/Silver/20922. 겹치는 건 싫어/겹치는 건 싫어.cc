#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int k,n;
vector<int>v;
int ans=0;
int cnt=0;
    int ridx=0;
    int target=0;
    map<int,int>m;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n>>k;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >>num;
        v.push_back(num);
        if(m[v[i]]==k)
            {
               while(m[v[i]]==k)
               {
                    m[v[target++]]--;
                    cnt--;
               }
            }
            m[v[i]]=m[v[i]]+1;
            cnt++;
            if(ans<cnt)
            {
                ans=cnt;
            }
    }
    cout <<ans;
    return 0;
}