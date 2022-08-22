#include <stdio.h>

int vunhae(int num)
{
if(num==1)
{
    return 0;
}
    for (int i=2; i<=num;i++)
    {
        if(num%i==0)
        {
            printf("%d\n",i);
            vunhae(num/i);
            break ;
        }
    }
}
int main()
{


int num;
scanf("%d",&num);

if(num==1)
{
    return 0;
}

vunhae(num);

return 0;
}