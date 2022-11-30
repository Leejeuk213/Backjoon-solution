#include<iostream>
#include<string>
using namespace std;
string str;
int n,k;
int main()
{
    cin >>n>>k;
    cin>>str;
    int ans=0;
    for(int i=0;i<str.size();i++)
    {
        int noteat=1;
        if(str[i]=='P')
        {
            for(int j=k;j>=1;j--)
            {
                if(str[i-j]=='H'&&i-j>=0)
                {
                    str[i-j]='O';
                    ans++;
                    noteat=0;
                    break;
                }
            }
            if(noteat)
            {
                for(int j=1;j<=k;j++)
                {
                    if(str[i+j]=='H'&&i+j<n)
                    {
                        str[i+j]='O';
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}