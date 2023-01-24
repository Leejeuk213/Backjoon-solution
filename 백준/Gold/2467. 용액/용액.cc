#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
pair<long long,long long>ans;
vector<pair<long long ,long long>>p;
long long sum=999999999999;
int main()
{
    cin >>n;

    for(int i=0;i<n;i++)
    {
        long long num;
        cin >>num;

        //양수면 1 음수면 0
        if(num<0)
        {
            p.push_back(make_pair(num*-1,0));
        }
        else
        {
            p.push_back(make_pair(num,1));
        }
    }
    sort(p.begin(),p.end());
    for(int i=0;i<p.size()-1;i++)
    {
        long long a=p[i].first;
        long long b=p[i+1].first;
        if(p[i].second==0)
        {
            a=a*-1;
        }
        if(p[i+1].second==0)
        {
            b=b*-1;
        }
        long long present_sum=a+b;
        if(present_sum<0)
        {
            present_sum=present_sum*-1;
        }
        if(sum>present_sum)
        {
            sum=present_sum;
            if(a<=b)
            {
                ans.first=a;
                ans.second=b;
            }
            else
            {
                ans.first=b;
                ans.second=a;
            }
        }
    }
    cout<<ans.first<<" "<<ans.second;
    return 0;
}