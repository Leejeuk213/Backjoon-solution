#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char,int>m;
string str;
int n;
int main()
{
    cin >>n;
    cin>>str;
    int ans=1;
    char start=str[0];
    char before=str[0];
    for(int i=1;i<str.size();i++)
    {
        if(start==str[i])
        {
            if(before!=str[i])
            {
                before=str[i];
            }
        }
        else
        {
           if(before!=str[i])
           {
                before=str[i];
                ans++;
           }
        }
    }
    printf("%d",ans);
    return 0;
}