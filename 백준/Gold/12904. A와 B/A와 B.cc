#include<iostream>
#include<string>
using namespace std;
string start;
string desty;

int main()
{
    cin>>start>>desty;
    while(desty.size()!=start.size())
    {
        if(desty[desty.size()-1]=='A')
        {
            desty.pop_back();
            continue;
        }
        else
        {
            desty.pop_back();
            for(int i=0;i<desty.size()/2;i++)
            {
                char temp=desty[i];
                desty[i]=desty[desty.size()-1-i];
                desty[desty.size()-1-i]=temp;
            }
        }
    }
    if(desty==start)
    {
        cout<<'1';
    }
    else
    {
        cout<<'0';
    }
    return 0;
}