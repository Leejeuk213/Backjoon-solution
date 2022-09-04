#include<stdio.h>

int num[1000]={0,};

void swap( int * a , int * b)
{

    int num= *a;
    *a=*b;
    *b=num;
}

int main()
{


int roop;
scanf("%d",&roop);
for(int i=0;i<roop;i++)
{

    scanf("%d",&num[i]);
}

for(int i=0; i<roop;i++)
{
    for(int j=0;j<roop-i-1;j++)
    {
        if(num[j]>num[j+1])
        {
          swap(&num[j],&num[j+1]);
            //int ex=num[j];
            //num[j]=num[j+1];
            //num[j+1]=ex;
        }
    }
}
for(int i=0;i<roop;i++)
{
    printf("%d\n",num[i]);
}
return 0;
}