#include<stdio.h>
#include<queue>
#include<stack>
using namespace std;
queue <int> q;
stack <int> s;
int su,du;
int cnt[100001]={0,};
int visit[100001]={0,};
int ans[100001]={0,};
void tracking(int index)
{
    s.push(index);
    if(index==su)
    {
        return;
    }
    tracking(ans[index]);
}
void bsp()
{
    q.push(su);
    cnt[su]=0;
    visit[su]=1;
    while(!q.empty())
    {
        int x=q.front();
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
            if(s1==du)
            {
                cnt[s1]=cnt[x]+1;
                ans[s1]=x;
                return ;
            }
            else
            {
                if(cnt[s1]==0&&visit[s1]!=1)
                {
                    q.push(s1);   
                    cnt[s1]=cnt[x]+1;
                    visit[s1]=1;
                    ans[s1]=x;
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
        printf("0\n");
        printf("%d",su);
        return 0;
    }
    bsp();
    printf("%d\n",cnt[du]);
    tracking(du);
    while(!s.empty())
    {
        printf("%d ",s.top());
        s.pop();
    }
    return 0;
}