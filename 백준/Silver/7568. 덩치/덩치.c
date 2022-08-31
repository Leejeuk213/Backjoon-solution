#include<stdio.h>
#include<stdlib.h>

struct people{

    int height;
    int weight;
     struct people * next;
     int idx;
    
};
int main()
{
   struct people * head = malloc(sizeof(struct people));
   struct people * tail = malloc(sizeof(struct people));
   head=NULL;
   tail=NULL;
int roop;
scanf("%d",&roop);
for(int i=0; i<roop; i++)
{
    struct people * next = malloc(sizeof(struct people));
    int height;
    int weight;
    scanf("%d %d",&height,&weight);
    next->height=height;
    next->weight=weight;
    next->next=NULL;
    next->idx=roop;
    if(head==NULL)
    {
        head=next;        
    }
    else
    {       
        tail->next=next;
    }
    tail=next;
}
struct people * cur = malloc(sizeof(struct people));
cur=head;
struct people * cur_one = malloc(sizeof(struct people));
cur_one=head;
for(int i=0;i<roop;i++)
{
    struct people * cur_two = malloc(sizeof(struct people));
        cur_two=head;
    for(int j=0;j<roop;j++)
    {

        if((cur_two->height>cur_one->height)&&(cur_two->weight>cur_one->weight))
        {
            
        }
        else{
            cur_one->idx=cur_one->idx-1;
        }
        cur_two=cur_two->next;
    }
    cur_one=cur_one->next;
}
for(int i=0;i<roop;i++)
{
    printf("%d ",cur->idx+1);
    cur=cur->next;
}
    return 0;
}