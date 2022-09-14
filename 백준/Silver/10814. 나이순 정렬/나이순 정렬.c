#include<stdio.h>
#include<string.h>
int num[100000];
int sortednum[100000];
char name[100000][101];
char sortedname[100000][101];

void merge(int left, int mid, int right)
{
    int iidx=left;
    int kidx=left;
    int jidx=mid+1;
    while(iidx<=mid&&jidx<=right)
    {
        if(num[iidx]<num[jidx])
        {
            sortednum[kidx]=num[iidx];
            strcpy(sortedname[kidx++],name[iidx++]);
        }
        else if(num[iidx]==num[jidx])
        {
           sortednum[kidx]=num[iidx];
            strcpy(sortedname[kidx++],name[iidx++]);
        }
        else if(num[iidx]>num[jidx])
        {
            sortednum[kidx]=num[jidx];
            strcpy(sortedname[kidx++],name[jidx++]);
        }
    }
    if(iidx<=mid)
    {
        for(int i=iidx;i<=mid;i++)
        {
            sortednum[kidx]=num[i];
            strcpy(sortedname[kidx++],name[i]);
        }
    }
    else
    {
        for(int i=jidx;i<=right;i++)
        {
            sortednum[kidx]=num[i];
            strcpy(sortedname[kidx++],name[i]);
        }
    }
    for(int i=left;i<=right;i++)
    {
        num[i]=sortednum[i];
        strcpy(name[i],sortedname[i]);
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
    for(int i=0; i<roop;i++)
    {
        scanf("%d %s",&num[i],name[i]);
    }
    mergesort(0,roop-1);
    for(int i=0; i<roop;i++)
    {
        printf("%d %s\n",num[i],name[i]);
    }
    return 0;
}