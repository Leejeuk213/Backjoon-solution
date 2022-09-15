#include<stdio.h>
int num[1000001];
int orinum[1000001];
int sortednum[1000001];

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
int vinary(int sol,int first, int last)
{
    int mid=(first+last)/2;
         if(num[mid]==sol)
        {          
            return mid;
        }
        else if(num[mid]>sol)
        {
            return vinary(sol,first,mid-1);             
        }
        else
        {
            return vinary(sol,mid+1,last);               
        }       
}
    
int main()
{
    int roop;
    scanf("%d",&roop);
    for(int i=0; i<roop;i++)
    {
        scanf("%d",&num[i]);
        orinum[i]=num[i];
    }
    mergesort(0,roop-1);
    int k=1;
    int subroop=roop;
    for(int i=1;i<roop;i++)
    {
        while(num[i-1]==num[i])
        {
            i++;
            subroop--;
        }
        num[k++]=num[i];
    }  
     for(int i=0; i<roop;i++)
    {
        printf("%d ",vinary(orinum[i],0,subroop-1));
    }   
    return 0;
}