#include<stdio.h>
#include<string.h>
char num[1001][1001];
char sortednum[1001][1001];
void merge(int left,int mid, int right)
{
    int kidx=left;
    int iidx=left;
    int jidx=mid+1;
    while(iidx<=mid&&jidx<=right)
    {
        if(strcmp(num[iidx],num[jidx])<=0)
        {
            strcpy(sortednum[kidx++],num[iidx++]);
        }
        else
        {
            strcpy(sortednum[kidx++],num[jidx++]);
        }
    }
    if(iidx<=mid)
    {
        for(int i=iidx;i<=mid;i++)
        {
             strcpy(sortednum[kidx++],num[i]);
        }
    }
    else
    {
        for(int i=jidx;i<=right;i++)
        {
             strcpy(sortednum[kidx++],num[i]);
        }
    }
    for(int i=left;i<=right;i++)
    {
         strcpy(num[i],sortednum[i]);
    }
}

void mergesort(int left,int right)
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
/*void quicksort(int left, int right)
{
    int l=left;
    int r=right;
    int pivot=(left+right)/2;
    while(left<=right)
    {
        while(strcmp(data[left],data[pivot])<0)
        {
            left++;
        }
        while(strcmp(data[right],data[pivot])>0)
        {
            right--;
        }
        if(left<=right)
        {
            char temp[1001];
            strcpy(temp,data[left]);
            strcpy(data[left],data[right]);
            strcpy(data[right],temp);
            left++;
            right--;
        }
    }
    if(l<right)
    {
        quicksort(l,right);
    }
    if(r>left)
    {
        quicksort(left,r);
    }
}*/
int main()
{
    char a[1001];
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++)
    {
        strncpy(num[i],a+i,strlen(a));       
    }
    mergesort(0,strlen(a)-1);
    for(int i=0;i<strlen(a);i++)
    {
        printf("%s\n",num[i]);
        
    }
}