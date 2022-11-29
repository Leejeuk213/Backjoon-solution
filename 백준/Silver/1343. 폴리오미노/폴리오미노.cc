#include<iostream>
#include<string>
using namespace std;
string str;
int main()
{
    cin >>str;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='.')
        {
            continue;
        }
        if(i+3<=str.size()-1)
        {
            if(str[i]=='X'&&str[i+1]=='X'&&str[i+2]=='X'&&str[i+3]=='X')
            {
                str[i]='A';
                str[i+1]='A';
                str[i+2]='A';
                str[i+3]='A';
                i=i+3;
                continue;
            }
            else if(str[i]=='X'&&str[i+1]=='X'&&str[i+2]=='.')
            {
                str[i]='B';
                str[i+1]='B';
                i=i+2;
                continue;
            }
        }
        if(i+3>str.size()-1&&i+1<=str.size()-1)
        {
            if(str[i]=='X'&&str[i+1]=='X')
            {
                str[i]='B';
                str[i+1]='B';
                i=i+1;
                continue;
            }
        }
    }
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='X')
        {
            printf("-1");
            return 0;
        }
    }
    cout<<str;
    return 0;
}