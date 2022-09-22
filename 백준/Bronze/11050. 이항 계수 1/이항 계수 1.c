#include<stdio.h>
int fact(int a)
{
    if(a==0)
    {
        return 1;
    }
    return a*fact(a-1);
}
int ihang(int n,int k)
{
if(k>n||k<0)
{
    return 0;
}
else
{
    return fact(n)/(fact(k)*fact(n-k));
}
}
int main()
{
    int k,n;
    scanf("%d %d",&n,&k);
    printf("%d",ihang(n,k));
}