#include <stdio.h>
#include <string.h>


int main()
{

int roop;
scanf("%d",&roop);
int cnt=0;
int num;
for(int i=0; i<roop; i++)
{
    scanf("%d",&num);
    int cnt2=0;
    if (num<=1)
    {
        continue;
    }
    for (int j=2;j<=num;j++)
    {
        if(num%j==0)
        {
            cnt2++;
        }
    }
    if(cnt2==1)
    {
        cnt++;
    }
}
printf("%d",cnt);
return 0;
}