#include<stdio.h>
#include<math.h>
int num[500001]={0,};
int sortednum[500001]={0,};
int num2[8001]={0,};
void merge(int left, int mid, int right)
{
int iidx=left;
int jidx=mid+1;
int kidx=left;

while(iidx<=mid&&jidx<=right)
{
    if(num[iidx]<=num[jidx])
    {
        sortednum[kidx++]=num[iidx++];
    }
    else
    {
        sortednum[kidx++]=num[jidx++];
    }

}
if(iidx>mid)
{
    for(int i=jidx;i<=right;i++)
    {
        sortednum[kidx]=num[i];
        kidx++;
    }
}
else
{
    for(int i=iidx;i<=mid;i++)
    {
        sortednum[kidx]=num[i];
        kidx++;
    }

}
for(int i=left;i<=right;i++)
{
    num[i]=sortednum[i];
}
}
void mergearray(int left, int right)
{
    int mid ;
    if(left<right)
    {
        mid=(left+right)/2;
        mergearray(left,mid);
        mergearray(mid+1,right);
        merge(left,mid,right);
    }
}
int findmax()
{
    int max=0;
    for(int i=0;i<=8000;i++)
    {
        if(num2[i]>max)
        {
            max=num2[i];
        }
    }
    return max;
}
int main()
{
    int roop;
    int cnt=0;
    double sol=0;
    scanf("%d",&roop);
    for(int i=0;i<roop;i++)
    {
        scanf("%d",&num[i]);
        num2[num[i]+4000]++;
        sol=sol+num[i];
    }
    mergearray(0,roop-1);
    double a=sol/roop;
    if(a>0)
    {
        printf("%d\n",(int)(a+0.5));
    }
    else
    {
         printf("%d\n",(int)(a-0.5));
    }
printf("%d\n",num[roop/2]);
int max;
for(int i=0;i<=8000;i++)
{
    if(num2[i]==findmax())
    {
        max=i;
        cnt++;
        if(cnt==2)
        {
            printf("%d\n",i-4000);
            break ;
        }
        
    }
}
    if(cnt!=2)
    {
    printf("%d\n",max-4000);
    }
    printf("%d",num[roop-1]-num[0]);
    return 0;
}