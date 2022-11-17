#include<stdio.h>
int num[64][64];
void div(int x,int y, int size)
{
    int check=1;
    if(size==0)
    {
        return;
    }
    for(int i=x;i<x+size;i++)
    {
        for(int j=y;j<y+size;j++)
        {
            if(num[i][j]!=num[x][y])
            {
                check=0;
            }
        }
    }
    if(check==1)
    {
        printf("%d",num[x][y]);
        return;
    }
    printf("(");
    div(x,y,size/2);
    div(x,y+size/2,size/2);
    div(x+size/2,y,size/2);
    div(x+size/2,y+size/2,size/2);
    printf(")");
}
int main()
{
    int roop;
    scanf("%d",&roop);
    for(int i=0;i<roop;i++)
    {
        for(int j=0;j<roop;j++)
        {
            scanf("%1d",&num[i][j]);
        }
    }
    div(0,0,roop);
    return 0;
}