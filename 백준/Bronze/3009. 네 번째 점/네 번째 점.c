#include<stdio.h>

int main()
{
    int xx,yy;
int x[3],y[3];
scanf("%d %d %d %d %d %d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]);
if(x[0]==x[1])
{
     xx=x[2];
}
else if(x[1]==x[2])
{
     xx=x[0];
}
else if(x[0]==x[2])
{
     xx=x[1];
}
if(y[0]==y[1])
{
     yy=y[2];
}
else if(y[1]==y[2])
{
     yy=y[0];
}
else if(y[0]==y[2])
{
     yy=y[1];
}
printf("%d %d",xx,yy);
}