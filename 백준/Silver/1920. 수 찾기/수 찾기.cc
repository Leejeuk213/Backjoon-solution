#include<stdio.h>
#include<string.h>

int num[100000]={0,};
int sortednum[100000]={0,};

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
void vinary(int sol, int len)
{
    int first=0;
    int last=len-1;
    int mid=(first+last)/2;

    while(first<=last)
    {
        mid=(first+last)/2;
        if(num[mid]==sol)
        {
            printf("1\n");
            return;
        }
        else{
            if(num[mid]>sol)
            {
                last=mid-1;
            }
            else{
                first=mid+1;
            }
        }

    }
printf("0\n");
return;
}
int main()
{


int roop;
scanf("%d",&roop);
for(int i=0;i<roop;i++)
{

    scanf("%d",&num[i]);
}

mergesort(0,roop-1);
int roop2;
scanf("%d",&roop2);
for(int i=0;i<roop2;i++)
{
    int b;
    scanf("%d",&b);
    vinary(b,roop);
}
return 0;
}