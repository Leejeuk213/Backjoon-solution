#include <stdio.h>

int main()
{

int num;
scanf("%d",&num);
int obj=0;
for(int i=num;i>0;i--)
{
    if(i>=100000)
    {
        if((i+(i/100000)+(i/10000)%10+(i/1000)%10+(i/100)%10+(i/10)%10+i%10)==num)
        obj=i;
    }
    else if(i>=10000)
    {
        if((i+(i/10000)+(i/1000)%10+(i/100)%10+(i/10)%10+i%10)==num)
        obj=i;
    }
    else if(i>=1000)
    {
        if((i+(i/1000)+(i/100)%10+(i/10)%10+i%10)==num)
        obj=i;
    }
    else if(i>=100)
    {
        if((i+(i/100)+(i/10)%10+i%10)==num)
        obj=i;
    }
    else if(i>=10)
    {
        if((i+(i/10)+i%10)==num)
        obj=i;
    }
    else if(i>=1)
    {
        if(2*i==num)
        {
            obj=i;
        }
    }
}

printf("%d",obj);
}