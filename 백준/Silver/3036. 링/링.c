#include<stdio.h>
int uq(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return uq(b,a%b);
    }
}
int num[100];
int main()
{
    int roop;
    scanf("%d",&roop);
    for(int i=0;i<roop;i++)
    {
        scanf("%d",&num[i]);
    }
    for(int i=0;i<roop-1;i++)
    {
        int sol=uq(num[0],num[i+1]);
        printf("%d/%d\n",num[0]/sol,num[i+1]/sol);
    }
    return 0;
}