#include <stdio.h>
#include <string.h>

int whoisbig(int a,int b, int c)
{
int big=0;
if(a>b)
{
    big=a;
}
else if(b>a)
{
    big=b;
}
if(big<c)
{
    big=c;
}
return big;
}
int main()
{
int a,b,c;
scanf("%d %d %d",&a,&b,&c);
if((a==b))
{
    if(a==c)
    {
    printf("%d",10000+a*1000);
    return 0;
    }
    else{
        printf("%d",1000+a*100);
        return 0;
    }
}
else if(a==c)
{
    printf("%d",1000+a*100);
    return 0;
}
else if(b==c)
{
    printf("%d",1000+b*100);
    return 0;
}
else{
    printf("%d",whoisbig(a,b,c)*100);
}
return 0;
}