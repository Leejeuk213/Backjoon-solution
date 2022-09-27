#include<stdio.h>
int n,m;
int check[1000];
int result[1000];

void dps(int depth)
{
    if(depth==m)
    {
        for(int i=0;i<m;i++)
        {
            printf("%d ",result[i]);
        }
        printf("\n");
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(check[i]==0)
            {
                result[depth]=i;
                check[i]=1;
                dps(depth+1);
                check[i]=0;
            }
        }
    }
}
int main()
{
   
   scanf("%d %d",&n,&m);
   dps(0);
    return 0;
}