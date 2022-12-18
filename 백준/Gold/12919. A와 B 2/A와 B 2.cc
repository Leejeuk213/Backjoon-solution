#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int>m;
string start;
string desty;
void back(string str)
{
    if(str.size()==start.size())
    {
        if(str==start)
        {
            cout<<'1';
            exit(0);
        }
        return;
    }
    if(m[str]==1)
    {
        return;
    }
    m[str]=1;
    if(str[str.size()-1]=='A')
    {
        if(str[0]=='A')
        {
            str.pop_back();
            back(str);
        }
        else
        {
            str.pop_back();
            back(str);
            str.push_back('A');
            for(int j=0;j<str.size()/2;j++)
            {
                char temp=str[j];
                str[j]=str[str.size()-1-j];
                str[str.size()-1-j]=temp;
            }
            str.pop_back();
            back(str);

        }
    }
    else
    {
        if(str[0]=='A')
        {
            cout<<'0';
            exit(0);
        }
        for(int j=0;j<str.size()/2;j++)
        {
            char temp=str[j];
            str[j]=str[str.size()-1-j];
            str[str.size()-1-j]=temp;
        }
        str.pop_back();
        back(str); 
    }
}
int main()
{
    cin>>start>>desty;
    back(desty);
    cout<<'0';
    return 0;
}