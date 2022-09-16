#include<stdio.h>
int num[500000];
int sortednum[500000];
int checknum[500000];
void merge(int left, int mid, int right)
{
    int iidx=left;
    int kidx=left;
    int jidx=mid+1;
    while(iidx<=mid&&jidx<=right)
    {
        if(num[iidx]<num[jidx])
        {
            sortednum[kidx++]=num[iidx++];
        
        }
        else if(num[iidx]==num[jidx])
        {
           
           sortednum[kidx++]=num[iidx++];
            
        }
        else if(num[iidx]>num[jidx])
        {
           
            sortednum[kidx++]=num[jidx++];
            
        }
    }
    if(iidx<=mid)
    {
        for(int i=iidx;i<=mid;i++)
        {
           
            sortednum[kidx++]=num[i];
           
        }
    }
    else
    {
        for(int i=jidx;i<=right;i++)
        {
           
            sortednum[kidx++]=num[i];
            
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
void vinary(int sol, int len, int first)
{
    int mid;
    int last=len-1;
    while(first<=last)
    {
        mid=(first+last)/2;
    if(num[mid]==sol)
    {
        printf("1 ");
        return;
    }
    else if(num[mid]>sol)
    {
        last=mid-1;
    }
    else
    {
        first=mid+1;
    }
    }
    printf("0 ");
    return;
}
int main()
{
    int roop;

    scanf("%d",&roop);
    for(int i=0; i<roop;i++)
    {
        scanf("%d",&num[i]);
    }
    mergesort(0,roop-1);
  int roop2;
    scanf("%d",&roop2);
    for(int i=0; i<roop2;i++)
    {
        scanf("%d",&checknum[i]);
        vinary(checknum[i],roop,0);
    }
   return 0;
}