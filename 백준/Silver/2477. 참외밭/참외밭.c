#include<stdio.h>
typedef struct node
{
    int count;
    int num;
};

int main()
{
    int num[6];
    int num2[6];
struct node a[5];
int size;
int fullsize=1;
int solsize=1;
a[1].count=0;
a[2].count=0;
a[3].count=0;
a[4].count=0;
scanf("%d",&size);
int index;
int len;
for(int i=0;i<6;i++)
{
    scanf("%d %d",&index,&len);
    num[i]=index;
    num2[i]=len;
    a[index].count++;
    a[index].num=len;
}
   
//cd 중간
    if(num[1]==num[5])
    {
        a[num[5]].num=num2[5];
        a[num[0]].num=num2[0];
    }
for(int i=0;i<=2;i++)
{
    if(num[i]==num[i+2]&&num[i+1]==num[i+3])
    {
        a[num[i+1]].num=num2[i+1];
        a[num[i+2]].num=num2[i+2];
        break;
    }
}   
    if(num[0]==num[2]&&num[1]==num[5])
    {
        a[num[0]].num=num2[0];
        a[num[1]].num=num2[1];
    }
    else if(num[5]==num[3]&&num[4]==num[0])
    {
        a[num[4]].num=num2[4];
        a[num[5]].num=num2[5];
    }
for(int i=1;i<=4;i++)
{
    if(a[i].count==1)
    {
        fullsize=fullsize*a[i].num;
    }
    else
    {
        solsize=solsize*a[i].num;
    }
}
printf("%d",(fullsize-solsize)*size);
return 0;
}