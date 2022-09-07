#include<stdio.h>

int num[10001]={0,};


int main()
{

int roop;
int sol;
scanf("%d %d",&roop,&sol);

for(int i=0;i<roop;i++)
{
    int val;
    scanf("%d",&val);
    num[val]++; 
}
int so=0;
for(int i=10000;i>=0;i--)
{
    for(int j=0; j<num[i];j++)
    {
        so++;
        if(so==sol)
        {
            printf("%d",i);
            return 0;
        }
    }
}

return 0;
}