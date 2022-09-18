#include<stdio.h>
#include<string.h>
int a[200000];
int sorteda[200000];
int b[200000];
int sortedb[200000];
void merge(int data[],int sorteddata[],int left,int mid,int right)
{
    int iidx=left;
    int kidx=left;
    int jidx=mid+1;
    while(iidx<=mid&&jidx<=right)
    {
        if(data[iidx]<=data[jidx])
        {
            sorteddata[kidx++]=data[iidx++];
        }
        else
        {
           sorteddata[kidx++]=data[jidx++];
        }
    }
    if(iidx<=mid)
    {
        for(int i=iidx;i<=mid;i++)
        {
            sorteddata[kidx++]=data[i];
        }
    }
    else
    {
        for(int i=jidx;i<=right;i++)
        {
            sorteddata[kidx++]=data[i];
        }
    }
    for(int i=left;i<=right;i++)
    {
        data[i]=sorteddata[i];
    }
}
void mergesort(int data[],int sorteddata[],int left,int right)
{
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        mergesort(data,sorteddata,left,mid);
        mergesort(data,sorteddata,mid+1,right);
        merge(data,sorteddata,left,mid,right);
    }
}
int vinary(int data[],int sol,int first,int last)
{
    int mid;
    
    while(first<=last)
    {
        mid=(first+last)/2;
        if(data[mid]==sol)
        {          
            
            return 1;
        }
        else if(data[mid]>sol)
        {
            last=mid-1;
        }
        else
        {
            first=mid+1;
        }
    }
    return 0;
}
int removedata(int data[],int first,int last)
{
    int k=0;
    int roop=last;
    for(int i=first;i<last;i++)
    {
        if(data[i]==data[i+1])
        {
        i++;
        roop--;
        }
        data[k++]=data[i];
    }
return roop;
}
int main()
{
    int roop1,roop2;
    scanf("%d %d",&roop1,&roop2);
    for(int i=0;i<roop1;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,sorteda,0,roop1-1);
    roop1=removedata(a,0,roop1);
    for(int i=0;i<roop2;i++)
    {
        scanf("%d",&b[i]);
    }
    mergesort(b,sortedb,0,roop2-1);
     roop2=removedata(b,0,roop2);
     int cnt1=0;
     int cnt2=0;
     int dd=0;
     int bb=0;
    for(int i=0;i<roop1;i++)
    {
       dd= vinary(b,a[i],0,roop2-1);
       cnt1+=dd;
    }
    for(int i=0;i<roop2;i++)
    {
       bb= vinary(a,b[i],0,roop1-1);
       cnt2+=bb;
    }
    printf("%d",(roop1-cnt1)+(roop2-cnt2));
    return 0;
}