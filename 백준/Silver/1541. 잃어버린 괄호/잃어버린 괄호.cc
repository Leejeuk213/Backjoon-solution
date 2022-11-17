#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int checkminus=0;
string input;
string handler;
int ans=0;
int main()
{
    cin >>input;
    for(int i=0;i<=input.size();i++)
    {
        if(input[i]=='+'||input[i]=='-'||i==input.size())
        {
            if(checkminus==1)
            {
                ans=ans-stoi(handler);
                handler="";
            }
            else
            {
                ans=ans+stoi(handler);
                handler="";
            }
        }
        else
        {
            handler=handler+input[i];
            //cout<<handler<<"\n";
        }
        if(input[i]=='-')
        {
            checkminus=1;
        }
    }
    printf("%d",ans);
    return 0;
}