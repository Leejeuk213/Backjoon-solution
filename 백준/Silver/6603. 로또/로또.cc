#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int num[14];
int check[14];
int siz;
int cnt=0;
void solve(int depth,int index)
{
    if(depth==6)
    {
        for(int i=0;i<siz;i++)
        {
            if(check[i]==1)
            {
                printf("%d ",num[i]);
                cnt++;
                if(cnt==6)
                {
                    cnt=0;
                    printf("\n");
                    return;
                }
            }
        }
    }
    for(int i=0;i<siz;i++)
    {
        if(check[i]==1||index>i)continue;
        check[i]=1;
        solve(depth+1,i);
        check[i]=0;
    }
}
int main()
{
    while(1)
    {
        scanf("%d",&siz);
        if(siz==0)
        {
            break;
        }
        for(int i=0;i<siz;i++)
        {
            scanf("%d",&num[i]);
        }
        solve(0,0);
        memset(check,0,sizeof(check));
        memset(num,0,sizeof(num));
        printf("\n");
    }
    return 0;
}