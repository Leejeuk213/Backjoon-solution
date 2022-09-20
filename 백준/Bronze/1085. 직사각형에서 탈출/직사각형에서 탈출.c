#include<stdio.h>
int whoissmall(int a, int b)
{
    if(a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
int main()
{
int x,y,w,h;
scanf("%d %d %d %d",&x,&y,&w,&h);
printf("%d",whoissmall(whoissmall(x,w-x),whoissmall(y,h-y)));
}