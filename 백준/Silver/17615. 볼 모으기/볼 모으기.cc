#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string str;
int main()
{
    int n;
    cin >> n >> str;
    int sw=0;
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    int cnt4=0;
    // R LEFT
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='B')
        {
            sw=1;
        }
        if(sw&&str[i]=='R')
        {
            cnt1++;
        }
    }
    sw=0;
    // R RIGHT
    for(int i=str.size()-1;i>=0;i--)
    {
        if(str[i]=='B')
        {
            sw=1;
        }
        if(sw&&str[i]=='R')
        {
            cnt2++;
        }
    }
    sw=0;
    // B LEFT
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='R')
        {
            sw=1;
        }
        if(sw&&str[i]=='B')
        {
            cnt3++;
        }
    }
    sw=0;
    // B RIGHT
    for(int i=str.size()-1;i>=0;i--)
    {
        if(str[i]=='R')
        {
            sw=1;
        }
        if(sw&&str[i]=='B')
        {
            cnt4++;
        }
    }
    cout<<min(cnt1,min(cnt2,min(cnt3,cnt4)));
    return 0;
}