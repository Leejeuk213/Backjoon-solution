#include<stdio.h>
#include<math.h>
double find(int a,int b)
{
    if(a>b)
    {
        return a-b;
    }
    else{
        return b-a;
    }
}
int main()
{

    int x1,y1,r1,x2,y2,r2;
    int roop;
    scanf("%d",&roop);
    for(int i=0;i<roop;i++)
    {
        scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
        double dis=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        if(x1==x2&&y1==y2&&r1==r2)
        {
            printf("-1\n");
        }
        else if(dis==r1+r2||find(r1,r2)==dis)
        {
            printf("1\n");
        }
        else if(find(r1,r2)<dis&&dis<r1+r2)
        {
            printf("2\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}