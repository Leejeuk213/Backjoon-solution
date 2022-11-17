#include<stdio.h>
#include<stack>
using namespace std;
int oper[10];
int cut(int a, int b)
{
    if(a>=b)
    {
        return a-b;
    }
    else{
        return b-a;
    }
}
int find(int obj)
{
    if(obj==0)
    {
        if(oper[0]!=1)
        {
            return 1;
        }
        else
        return 0;
    }
    int len=0;
    while(obj>0)
    {
        if(oper[obj%10]!=1)
        {
            len++;
        }
        else
        {
            return 0;
        }
        obj=obj/10;
    }
    return len;
}
int main()
{
    int obj;
    int roop;
    int ans;
    scanf("%d %d",&obj,&roop);
    for(int i=0;i<roop;i++)
    {
        int num;
        scanf("%d",&num);
        oper[num]=1;
    }
    ans=cut(100,obj);
    for(int i=0;i<1000000;i++)
    {
        int len=find(i);
        if(len>0)
        {
            if(ans>cut(obj,i)+len)
            {
                ans=cut(obj,i)+len;
            }
        }
    }
    printf("%d",ans);
    return 0;
}