#include<stdio.h>
#include<queue>
using namespace std;
queue <int>q;
int su,du;
int cnt[100001]={0,};
int miny=0;
int cmp=0;
void bsp(int s, int d)
{
    q.push(s);
    cnt[s]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<3;i++)
        {
            int s1;
            if(x>d)
            {
                s1=x-1;
            }
            else
            {
                if(i==0)
                {
                    s1=x-1;           
                }
                else if(i==1)
                {
                    s1=x+1;           
                }
                else
                {
                    s1=x*2;
                }
            }
            if(s1<0||s1>100000)
            {
                continue;
            }
            
            else
            {
                if(s1==d)
                {
                    if(cnt[s1]==0)
                    {
                        cnt[s1]=cnt[x]+1;
                        miny=1;
                        cmp=cnt[s1];
                    }
                    else
                    {
                        if(cmp==cnt[x]+1)
                        {
                           miny++;
                        }
                    }
                }
                else
                {
                    if(cnt[s1]==0)
                    {
                        q.push(s1);   
                        //printf("%d %d\n",x,s1);
                        cnt[s1]=cnt[x]+1;
                    }
                    
                }
            }
        }
    }

}
int main()
{
    scanf("%d %d",&su,&du);
    if(su==du)
    {
        printf("0");
        return 0;
    }
    bsp(su,du);
    printf("%d",cnt[du]);
}