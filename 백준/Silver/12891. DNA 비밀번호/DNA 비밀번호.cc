#include<iostream>
#include<map>
#include<string>
using namespace std;

int s,p;
string first;
map<char,int> com_m;
map<char,int> m;
int ans=0;
int main()
{
    cin >>s>>p;
    cin >>first;
    cin >>com_m['A'];
    cin >>com_m['C'];
    cin >>com_m['G'];
    cin >>com_m['T'];
    for(int i=0;i<p;i++)
    {
        m[first[i]]++;
    }
    if(m['A']>=com_m['A']&&m['C']>=com_m['C']&&m['G']>=com_m['G']&&m['T']>=com_m['T'])
    {
        ans++;
    }
    for(int i=1;i<=s-p;i++)
    {
        m[first[i-1]]--;
        m[first[p-1+i]]++;
        if(m['A']>=com_m['A']&&m['C']>=com_m['C']&&m['G']>=com_m['G']&&m['T']>=com_m['T'])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}