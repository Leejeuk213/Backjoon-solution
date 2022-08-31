#include<stdio.h>

int main()
{
    int sol[10000]={0,};
    int k;
    int arr[10]={0,};
    int l=0;
    for(int i=666;l<10000;i++)
{
    k=i;
    int m=0;
    while(k>0)
    {
        arr[m]=k%10;
        k=k/10;
        m++;
    }
    for(int j=0;j<m-1;j++)
    {
        if(arr[j]==6&&arr[j]==arr[j+1]&&arr[j+1]==arr[j+2])
        {
            sol[l]=i;
            l++;
            break;
        }
    }

}
int num;
scanf("%d",&num);
printf("%d",sol[num-1]);
}