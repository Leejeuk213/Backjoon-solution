#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string str;

int main()
{
    cin >> str;
    string ans="";
    for(int i=0;i<str.size();i++)
    {
        int check=1;
        if(str[i]=='M')
        {
            int cnt=0;
            while(str[i]=='M')
            {
                cnt++;
                i++;
                if(i==str.size())
                {
                    check=0;
                    for(int j=0;j<cnt;j++)
                    {
                        ans=ans+'1';
                    }
                }
            }
            if(check)
            {
                ans=ans+'5';
                for(int j=0;j<cnt;j++)
                {
                    ans=ans+'0';
                }
            }
        }
        else
        {
            ans=ans+'5';
        }
    }
    cout<<ans<<"\n";
    ans="";
    for(int i=0;i<str.size();i++)
    {
        int check=1;
        if(str[i]=='M')
        {
            int cnt=0;
            while(str[i]=='M')
            {
                cnt++;
                i++;
                if(i==str.size())
                {
                    check=0;
                    ans=ans+'1';
                    for(int j=0;j<cnt-1;j++)
                    {
                        ans=ans+'0';
                    }
                    break;
                }
            }
            if(check)
            {
                ans=ans+'1';
                for(int j=0;j<cnt-1;j++)
                {
                    ans=ans+'0';
                }
                i--;
            }
        }
        else if(str[i]=='K')
        {
            ans=ans+'5';
        }
    }
    cout<<ans;
    return 0;
}