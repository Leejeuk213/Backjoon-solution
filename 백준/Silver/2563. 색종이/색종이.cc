#include<iostream>
#include<vector>
using namespace std;
int n;
int paper[101][101];
int ans=0;
int main()
{
    cin >>n;
    for(int i=0;i<n;i++)
    {
        int num1,num2;
        cin>>num1>>num2;
        for(int j=num1;j<num1+10;j++)
        {
            for(int k=num2;k<num2+10;k++)
            {
                paper[j][k]=1;
            }
        }
    }
    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=100;j++)
        {
            if(paper[i][j]==1)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}