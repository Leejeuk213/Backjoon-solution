#include<stdio.h>

int main()
{
    int roop;
    long long num[101][10];
    scanf("%d",&roop);
    num[1][0]=0;
    num[1][1]=1;
    num[1][2]=1;
    num[1][3]=1;
    num[1][4]=1;
    num[1][5]=1;
    num[1][6]=1;
    num[1][7]=1;
    num[1][8]=1;
    num[1][9]=1;
    for(int i=2;i<=roop;i++)
    {
        for(int j=0;j<10;j++)
        {   
            if(j-1<0)
            {
                num[i][j]=(num[i-1][j+1])%1000000000;
                
            }
            else if(j+1==10)
            {
                num[i][j]=(num[i-1][j-1])%1000000000;
            }
            else
            {
            num[i][j]=(num[i-1][j-1]+num[i-1][j+1])%1000000000;
            }
        }
    }
    int sum=0;
    for(int i=0;i<10;i++)
    {
        sum=(sum+num[roop][i])%1000000000;
        //printf("%d ",num[roop][i]);
    }
   // printf("\n");
    printf("%d",sum);
    return 0;
}