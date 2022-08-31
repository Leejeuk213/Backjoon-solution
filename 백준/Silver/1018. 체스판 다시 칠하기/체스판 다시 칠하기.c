#include<stdio.h>
#define small(x,y)x<y?x:y
int main()
{
    int a,b,count,count2,min=2500;
    char chess[50][51];
    scanf("%d %d",&a,&b);
    for(int i=0;i<a;i++)
        scanf("%s",chess[i]);
    for(int i=0;i<a-7;i++)
        for(int j=0;j<b-7;j++)
        {
            count=0,count2=0;
            for(int h=i;h<i+8;h++)
                for(int k=j;k<j+8;k++)
                {
                    if((h+k)%2==0)
                    {
                        if(chess[h][k]=='W')
                            count++;
                        else
                            count2++;                        
                    }
                    else
                    {
                        if(chess[h][k]=='B')
                            count++;
                        else
                            count2++;
                    }
                }
            min=small(min,count);
            min=small(min,count2);
        }
    printf("%d",min);
    return 0;
}