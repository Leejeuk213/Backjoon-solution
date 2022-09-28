#include <stdio.h>
#include<stdlib.h>
int k,n;
long long num[10001];
int compare(const * a, const * b)
{
    long long num1=*(long long *)a;
    long long num2=*(long long *)b;
    if(num1>num2)
    {
        return 1;
    }
    else if(num1<num2)
    {
        return -1;
    }
    else{
        return 0;
    }
}
int possible(int a)
{
    int cnt=0;
    for(int i=0;i<k;i++)
    {
        cnt=cnt+num[i]/a;
    }
    //printf("%d %d\n",cnt ,a);
    if(cnt>=n)
    {
        return 1;
    }
    else
    {
    return 0;
    }
}
long long vinary(long long low, long long high)
{
    long long ans=0;
    while(low<=high)
    {
        long long mid=(low+high)/2;
        if(possible(mid))
        {
            if(mid>=ans)
            {
                ans=mid;
               // printf("%d\n",ans);
            }
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}

int main()
{
    
    scanf("%d %d",&k,&n);
    for(int i=0;i<k;i++)
    {
        scanf("%lld",&num[i]);
    }
    qsort(num,k,sizeof(long long),compare); 
    long long b=vinary(1,num[k-1]);
    printf("%lld",b);
    return 0;
}