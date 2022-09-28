#include <stdio.h>
int main()
{
    
    int num;
    while(1)
    {
        scanf("%d",&num);
        int n[5]={0,};
        int i=0;
        if(num==0)
        {
            return 0;
        }
        while(num!=0)
        {
            n[i++]=num%10;
            num=num/10;
        }
        if(i==1)
        {
            printf("yes\n");
            continue;
        }
        for(int j=0;j<i;j++)
        {
            if(i-j-1<j)
            {
                printf("yes\n");
                break;
            }
            if(n[j]!=n[i-j-1])
            {
                printf("no\n");
                break;
            }
        }
    }
}