#include<stdio.h>
#include<string.h>
char d[500000][21];
char sortedd[500000][21];
char b[500000][21];
char sortedb[500000][21];
char db[500000][21];
int cnt=0;
void merge(char data[][21],char sorteddata[][21],int left,int mid,int right)
{
    int iidx=left;
    int kidx=left;
    int jidx=mid+1;
    while(iidx<=mid&&jidx<=right)
    {
        if(strcmp(data[iidx],data[jidx])<=0)
        {
            strcpy(sorteddata[kidx++],data[iidx++]);
        }
        else
        {
            strcpy(sorteddata[kidx++],data[jidx++]);
        }
    }
    if(iidx<=mid)
    {
        for(int i=iidx;i<=mid;i++)
        {
            strcpy(sorteddata[kidx++],data[i]);
        }
    }
    else
    {
        for(int i=jidx;i<=right;i++)
        {
            strcpy(sorteddata[kidx++],data[i]);
        }
    }
    for(int i=left;i<=right;i++)
    {
        strcpy(data[i],sorteddata[i]);
    }
}
void mergesort(char data[][21],char sorteddata[][21],int left,int right)
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
void vinary(char data[],int first,int last)
{
    int mid;
    while(first<=last)
    {
        mid=(first+last)/2;
        if(strcmp(d[mid],data)==0)
        {          
            strcpy(db[cnt++],data);
            return;
        }
        else if(strcmp(d[mid],data)>0)
        {
            last=mid-1;
        }
        else
        {
            first=mid+1;
        }
    }
    return;
}
int main()
{
    int roop1,roop2;
    scanf("%d %d",&roop1,&roop2);
    for(int i=0;i<roop1;i++)
    {
        scanf("%s",d[i]);
    }
    mergesort(d,sortedd,0,roop1-1);
    for(int i=0;i<roop2;i++)
    {
        scanf("%s",b[i]);
    }
    mergesort(b,sortedb,0,roop2-1);
    for(int i=0;i<roop2;i++)
    {
        vinary(b[i],0,roop1-1);
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
    {
        printf("%s\n",db[i]);
    }
    return 0;
}