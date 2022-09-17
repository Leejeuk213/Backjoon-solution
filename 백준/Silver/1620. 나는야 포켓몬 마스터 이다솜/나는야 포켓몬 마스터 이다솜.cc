#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char data[100001][21];
typedef struct {

    int num;
    char data[21];
}mon;
mon monster[100000];
mon sortedmonster[100000];
void merge(int left,int mid,int right)
{
    int iidx=left;
    int kidx=left;
    int jidx=mid+1;
    while(iidx<=mid&&jidx<=right)
    {
        if(strcmp(monster[iidx].data,monster[jidx].data)<=0)
        {
            sortedmonster[kidx].num=monster[iidx].num;
            strcpy(sortedmonster[kidx++].data,monster[iidx++].data);
        }
        else
        {
            sortedmonster[kidx].num=monster[jidx].num;
            strcpy(sortedmonster[kidx++].data,monster[jidx++].data);
        }
    }
    if(iidx<=mid)
    {
        for(int i=iidx;i<=mid;i++)
        {
            sortedmonster[kidx].num=monster[i].num;
            strcpy(sortedmonster[kidx++].data,monster[i].data);
        }
    }
    else
    {
        for(int i=jidx;i<=right;i++)
        {
            sortedmonster[kidx].num=monster[i].num;
            strcpy(sortedmonster[kidx++].data,monster[i].data);
        }
    }
    for(int i=left;i<=right;i++)
    {
        monster[i].num=sortedmonster[i].num;
            strcpy(monster[i].data,sortedmonster[i].data);
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
int vinary(char data[],int first,int last)
{
    int mid; 
    while(first<=last)
    {
        mid=(first+last)/2;
        if(strcmp(monster[mid].data,data)==0)
        {
            return monster[mid].num;
        }
        else if(strcmp(monster[mid].data,data)>0)
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
    int roop1,roop2;
    scanf("%d %d",&roop1,&roop2);
    for(int i=0;i<roop1;i++)
    {
        scanf("%s",monster[i].data);
        monster[i].num=i+1;
        strcpy(data[i+1],monster[i].data);
    }
    mergesort(0,roop1-1);
    for(int i=0;i<roop2;i++)
    {
        char haha[21];
        int num1;
        scanf("%s",haha);
        if(isdigit(haha[0]))
        {
            num1=atoi(haha);
            printf("%s\n",data[num1]);
        }
        else
        {
            int index=vinary(haha,0,roop1-1);
            printf("%d\n",index);
        }
    }
    return 0;
}