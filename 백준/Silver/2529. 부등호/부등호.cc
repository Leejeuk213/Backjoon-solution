#include<iostream>
#include<string>
using namespace std;
int n;
int check[10];
string str;
string ans;
string minstr;
long long minnum=99999999999;
long long maxnum=0;
string maxstr;
void solve(int depth)
{
    if(depth==n+1)
    {
        if(maxnum<stoll(ans))
        {
            maxnum=stoll(ans);
            maxstr=ans;
        }
        if(minnum>stoll(ans))
        {
            minnum=stoll(ans);
            minstr=ans;
        }
        return ;
    }
    if(depth==0)
    {
        for(int i=0;i<=9;i++)
        {
            check[i]=1;
            ans.push_back(i+'0');
            solve(1);
            ans.pop_back();
            check[i]=0;
        }
    }
    for(int i=0;i<=9;i++)
    {
        char *temp=&ans[depth-1];
        int num=atoi(temp);
        if(check[i]==0)
        {
            if(str[depth-1]=='>')
            {
                if(num>i)
                {
                    check[i]=1;
                    ans.push_back(i+'0');
                    solve(depth+1);
                    ans.pop_back();
                    check[i]=0;
                }
            }
            else
            {
                if(num<i)
                {
                    check[i]=1;
                    ans.push_back(i+'0');
                    solve(depth+1);
                    ans.pop_back();
                    check[i]=0;
                }
            }
        }
    }
}
int main()
{
    cin >>n;
    for(int i=0;i<n;i++)
    {
        char a;
        cin >>a;
        str.push_back(a);
    }
    solve(0);
    cout<<maxstr<<"\n";
    cout<<minstr<<"\n";
    return 0;
}