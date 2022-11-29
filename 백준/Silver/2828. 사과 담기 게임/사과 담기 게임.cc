#include<stdio.h>
int n,m,j;
int apple[21];
int main()
{
    scanf("%d %d %d",&n,&m,&j);
    for(int i=0;i<j;i++)
    {
        scanf("%d",&apple[i]);
    }
    int ans=0;
    int now=1;
    for(int i=0;i<j;i++)
    {
        if(now-1+m==apple[i]||now==apple[i])
        {
            continue;
        }
        else if(now-1+m<apple[i])
        {
            while(1)
            {
                if(now<=apple[i]&&apple[i]<=now-1+m)
                {
                    break;
                }
                now++;
                ans++;
            }
        }
        else if(now-1+m>apple[i])
        {
            while(1)
            {
                if(now<=apple[i]&&apple[i]<=now-1+m)
                {
                    break;
                }
                now--;
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}