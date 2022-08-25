#include<stdio.h>

int main()
{

int num[105];

int roop;
int obj;
scanf("%d %d",&roop,&obj);
int max=0;;
for(int i=0;i<roop;i++)
{
    scanf("%d",&num[i]);
}
for(int i=0;i<roop-2;i++)
{
    for(int j=i+1;j<roop-1;j++)
    {
        for(int k=j+1;k<roop;k++)
        {
            if(num[i]+num[j]+num[k]<=obj)
            {
                if(num[i]+num[j]+num[k]>max)
                {
                    max=num[i]+num[j]+num[k];
                }
            }
        }
    }
}
printf("%d",max);
}