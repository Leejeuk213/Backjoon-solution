#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
vector<int>v;
int n,m;
map<int,string> z;
int main()
{
    cin >>n >>m;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<n;i++)
    {
        string a;
        int b;
        cin >>a>>b;
        if(z.count(b)==1)
        {
            continue;
        }
        v.push_back(b);
        z[b]=a;
    }

    while(m--)
    {
        int num;
        cin >>num;

        int left=0;
        int right=v.size()-1;
        int mid=(left+right)/2;
        int result;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(v[mid]<num)
            {
                //cout<<"small"<<z[v[mid]]<<"\n";
                left=mid+1;
            }
            else
            {
                //cout<<"big"<<z[v[mid]]<<"\n";
                result=mid;
                right=mid-1;
            }
        }
        cout<<z[v[result]]<<"\n";
    }

    return 0; 
}