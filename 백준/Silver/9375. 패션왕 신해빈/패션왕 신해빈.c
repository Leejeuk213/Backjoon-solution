#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cnt1=1; 
typedef struct node{
    char cloth[21];
    int  cnt;
    struct node * next;
};
struct node * hash[1000];
int stringtonum(char * s)
{
    int b=0;
    while(*s)
    {
        b=b+*s;
        s++;
    }
    return b%1000;
}
void chaining(char * a, char * b)
{
    struct node * newnode=malloc(sizeof(struct node));
    strcpy(newnode->cloth,a);
    int num=stringtonum(b);
    
    if(hash[num]==NULL)
    {
        newnode->cnt=1;
        hash[num]=newnode;
        hash[num]->next=NULL;
    }
    else
    {
        newnode->next=hash[num]->next;
        newnode->cnt=hash[num]->cnt++;
        hash[num]->next=newnode;
        
    }
}
int main()
{
    int roop;
    scanf("%d",&roop);
    for(int i=0;i<roop;i++)
    {
        int roop2;
        scanf("%d",&roop2);
        for(int j=0;j<roop2;j++)
        {
            char a[21];
            char b[21];
            scanf("%s",a);
            scanf("%s",b);
            chaining(a,b);
        }
        for(int k=0;k<1000;k++)
        {
            if(hash[k]!=NULL)
            {
                cnt1=(hash[k]->cnt+1)*cnt1;
                hash[k]=NULL;
            }
        }
        printf("%d\n",cnt1-1);
        cnt1=1;
    }
    return 0;
}