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
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n >>m;

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
    sort(v.begin(),v.end());
    while(m--)
    {
        int num;
        cin >>num;
        int result=lower_bound(v.begin(),v.end(),num)-v.begin();
        
        cout<<z[v[result]]<<"\n";
    }

    return 0; 
}