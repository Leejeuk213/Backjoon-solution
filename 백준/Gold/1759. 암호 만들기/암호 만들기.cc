#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string ans;
string str;
int check[16];
int n,k;
void solve(int depth)
{
    if(depth==n)
    {
        int mo=0;
        int ja=0;
        int ok=1;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]=='a'||ans[i]=='e'||ans[i]=='i'||ans[i]=='o'||ans[i]=='u')mo++;
            else ja++;
        }
        if(mo>=1&&ja>=2&&ok)
        {
            cout<<ans<<"\n";
        }
        return ;
    }
    for(int i=0;i<k;i++)
    {
        if(check[i]==0&&str[i]>ans[ans.size()-1])
        {
            check[i]=1;
            ans.push_back(str[i]);
            solve(depth+1);
            check[i]=0;
            ans.pop_back();
        }
    }
}
int main()
{
    cin >>n >>k;
    for(int i=0;i<k;i++)
    {
        char a;
        cin >>a;
        str.push_back(a);
    }
    sort(str.begin(),str.end());
    for(int i=0;i<k;i++)
    {
        if(check[i]==0)
        {
            check[i]=1;
            ans.push_back(str[i]);
            solve(1);
            check[i]=0;
            ans.pop_back();
        }
        
    }
    return 0;
}