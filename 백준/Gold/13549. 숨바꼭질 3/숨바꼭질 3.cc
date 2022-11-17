#include<stdio.h>
#include<queue>
using namespace std;
queue <int>q;
int su,du;
int cnt[100001]={0,};
int visit[100001]={0,};
void bsp()
{
    q.push(su);
    cnt[su]=0;
    while(!q.empty())
    {
        int x=q.front();
        visit[x]=1;
        q.pop();
        for(int i=0;i<3;i++)
        {
            int s1;
            if(x>du)
            {
                s1=x-1;
                i=2;
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
                if(s1==du)
                {
                    if(cnt[s1]==0&&visit[s1]==0)
                    {
                        if(s1==x*2)
                        {
                            cnt[s1]=cnt[x];     
                            visit[s1]=1;
                          //  printf("%d %d %d\n",s1,x,cnt[s1]);
                        }
                        else
                        {
                            visit[s1]=1;
                            cnt[s1]=cnt[x]+1;
                          //  printf("%d %d %d\n",s1,x,cnt[s1]);
                        }
                    }
                    else if(cnt[s1]!=0)
                    {
                        if(s1==x*2&&cnt[s1]>cnt[x])
                        {
                            cnt[s1]=cnt[x];
                           // printf("%d %d %d\n",s1,x,cnt[s1]);
                        }
                        else if(s1!=x*2&&cnt[s1]>cnt[x]+1)
                        {
                            cnt[s1]=cnt[x]+1;
                           // printf("%d %d %d\n",s1,x,cnt[s1]);
                        }
                    }
                }
                else
                {
                    if(cnt[s1]==0&&visit[s1]!=1)
                    {
                        if(s1==x*2)
                        {
                            q.push(s1);  
                            visit[s1]=1; 
                            cnt[s1]=cnt[x];
                            //printf("%d %d %d\n",s1,x,cnt[s1]);
                        }
                        else
                        {
                            q.push(s1);   
                            visit[s1]=1;
                            cnt[s1]=cnt[x]+1;
                            //printf("%d %d %d\n",s1,x,cnt[s1]);
                        }
                    }
                    else if(cnt[s1]!=0)
                    {
                        if(cnt[s1]>cnt[x])
                        {
                            if(s1==x*2)
                            {
                                q.push(s1);  
                                cnt[s1]=cnt[x];
                                //printf("%d %d %d\n",s1,x,cnt[s1]);
                            }
                            else
                            {
                                q.push(s1);
                                cnt[s1]=cnt[x]+1;
                               // printf("%d %d %d\n",s1,x,cnt[s1]);
                            }
                        }
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
    bsp();
    printf("%d",cnt[du]);
}