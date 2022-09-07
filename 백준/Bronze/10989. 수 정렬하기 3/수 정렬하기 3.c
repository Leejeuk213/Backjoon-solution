#include<stdio.h>

int num[10001]={0,};


int main()
{

int roop;
scanf("%d",&roop);

for(int i=1;i<=roop;i++)
{
    int val;
    scanf("%d",&val);
    num[val]++; 
}

for(int i=1;i<=10000;i++)
{
    for(int j=0;j<num[i];j++)
    {
        printf("%d\n",i);
    }
}

return 0;
}