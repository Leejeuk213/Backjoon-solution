#include<stdio.h>
int main()
{
    int i=1;
    while(1)
    {
        int l,p,v;
        scanf("%d %d %d",&l,&p,&v);
        if(l==0&&p==0&&v==0)
        {
            break;
        }
        if(v%p>l)
        printf("Case %d: %d\n",i,l*(v/p)+l);
        else
        printf("Case %d: %d\n",i,l*(v/p)+v%p);
        i++;
    }
    return 0;
}