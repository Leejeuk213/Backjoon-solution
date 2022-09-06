#include<stdio.h>
#include<string.h>

int num[1000000]={0,};
int sortednum[1000000]={0,};

void swap( int * a , int * b)
{

    int num= *a;
    *a=*b;
    *b=num;
}

void merge(int left, int mid, int right)
{
    int iidx=left;
    int ridx=mid+1;
    int cidx=left;
    while(iidx<=mid&&ridx<=right)
    {
        if(num[iidx]<=num[ridx])
        {
            sortednum[cidx++]=num[iidx++];
        }
        else
        {
            sortednum[cidx++]=num[ridx++];
        }
    }
    if(iidx>mid)
    {
        for(int i=ridx;i<=right;i++)
        {
            sortednum[cidx++]=num[i];
        }
    }
    else{
        for(int i= iidx;i<=mid; i++)
        {
            sortednum[cidx++]=num[i];
        }
    }
    for(int i=left;i<=right;i++)
    {
        num[i]=sortednum[i];
    }
}
void mergesort(int left, int right)
{
int mid;
if(left<right)
{
    mid=(left+right)/2;

    mergesort(left,mid);
    mergesort(mid+1,right);
    merge(left,mid,right);
}
}


int main()
{


int roop;
scanf("%d",&roop);
for(int i=0;i<roop;i++)
{

    scanf("%d",&num[i]);
}
if(roop==1)
{
    printf("%d",num[0]);
    return 0;
}
mergesort(0,roop-1);

for(int i=0;i<roop;i++)
{
printf("%d\n",sortednum[i]);
}
return 0;
}