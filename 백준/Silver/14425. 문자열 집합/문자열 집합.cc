#include<stdio.h>
#include<string.h>
char a[10000][501];
char sorteda[10000][501];
char b[10000][501];
int cnt=0;
void merge(int left,int mid, int right)
{
    int iidx=left;
    int kidx=left;
    int jidx=mid+1;
    while(iidx<=mid&&jidx<=right)
    {
        if(strcmp(a[iidx],a[jidx])<=0)
        {
            strcpy(sorteda[kidx++],a[iidx++]);
        }
        else
        {
            strcpy(sorteda[kidx++],a[jidx++]);
        }
    }
    if(iidx<=mid)
    {
        for(int i=iidx;i<=mid;i++)
        {
            strcpy(sorteda[kidx++],a[i]);
        }
    }
    else
    {
        for(int i=jidx;i<=right;i++)
        {
            strcpy(sorteda[kidx++],a[i]);
        }
    }
    for(int i=left;i<=right;i++)
    {
        strcpy(a[i],sorteda[i]);
    }
}
void mergesort(int left, int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        mergesort(left,mid);
        mergesort(mid+1,right);
        merge(left,mid,right);
    }
}
void vinary(char s[],int first,int last)
{
    while(first<=last)
    {
        int mid=(first+last)/2;
        if(strcmp(a[mid],s)==0)
        {
            cnt++;
            return;
        }
        else if(strcmp(a[mid],s)>0)
        {
            last=mid-1;
        }
        else
        {
            first=mid+1;
        }
    }
}
int main()
{
    int roop,roop2;    
    scanf("%d %d",&roop,&roop2);
    for(int i=0;i<roop;i++)
    {
        scanf("%s",a[i]);
    }
    mergesort(0,roop-1);
for(int i=0;i<roop2;i++)
    {
        scanf("%s",b[i]);
        vinary(b[i],0,roop-1);
    }
    printf("%d",cnt);
return 0;
}