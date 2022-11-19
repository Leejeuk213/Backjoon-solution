#include<iostream>
#include<algorithm>
#include<queue>
int max(int a,int b)
{
    if(a>=b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
using namespace std;
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int set=1001;
    int one=1001;
    for(int i=0;i<k;i++)
    {
        int q,w;
        scanf("%d %d",&q,&w);
        if(q<set)
        {
            set=q;
        }
        if(w<one)
        {
            one=w;
        }
    }
    if(n%6==0)
    {
        printf("%d",max(set*(n/6),one*n));
    }
    else
    {
        printf("%d",max(one*n,max(set*((n/6)+1),set*(n/6)+one*(n%6))));
    }
    return 0;
}