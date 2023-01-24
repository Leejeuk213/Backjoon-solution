#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> v;
int check[100001];
long long ans=0;
int main()
{
    cin >>n;
    int start=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >>num;
        v.push_back(num);
        if(check[num]==1)
        {
            while(1)
            {
                if(v[start]==v[i])
                {
                    cnt--;
                    check[v[start++]]--;
                    break;
                }
                cnt--;
                check[v[start++]]--;
            }
        }
        cnt++;
        check[num]++;
        ans=ans+cnt;
    }
    cout <<ans;

    return 0;
}