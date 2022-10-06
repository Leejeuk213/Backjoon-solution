#include<stdio.h>
int num[12];
int max=-1000000010;
int roop;
int solve;
int min=1000000010;
int operator[4];
void bsp(int result,int depth)
{
    if(depth==roop)
    {
        if(min>result)
        min=result;
        if(max<result)
        max=result;
        return;
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            if(operator[i]>0)
            {
                operator[i]--;
                if(i==0)
                {
                    bsp(result+num[depth],depth+1);
                }
                else if(i==1)
                {
                    bsp(result-num[depth],depth+1);
                }
                else if(i==2)
                {
                    bsp(result*num[depth],depth+1);
                }
                else
                {
                    bsp(result/num[depth],depth+1);
                }
                 operator[i]++;
            }
        }
    }
}
int main()
{
    scanf("%d",&roop);
    for(int i=0;i<roop;i++)
    {
        scanf("%d",&num[i]);
    }
    scanf("%d %d %d %d",&operator[0],&operator[1],&operator[2],&operator[3]);
    bsp(num[0],1);
    printf("%d\n%d",max,min);
}