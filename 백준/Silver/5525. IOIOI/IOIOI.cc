#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
string d;
int main()
{   
    int O;
    int size;
    cin>>O;
    cin>>size;
    cin>>d;
    int ioi_cnt=0;
    for(int i=0;i<size;i++)
    {
        int cnt=0;
        if(d[i]=='O')
        {
            continue;
        }
        else
        {
            while(d[i+1]=='O'&&d[i+2]=='I')
            {
                cnt++;
                if(cnt==O)
                {
                    ioi_cnt++;
                    cnt--;
                }
                i=i+2;
            }
        }

    }
    cout<<ioi_cnt;
    return 0;
}