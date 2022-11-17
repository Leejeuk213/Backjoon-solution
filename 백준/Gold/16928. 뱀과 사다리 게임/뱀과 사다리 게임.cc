#include<iostream>
#include<queue>
#include<map>
using namespace std;
int cnt[101];
queue<int> q;
map<int,int> snake;
map<int,int> ladder;
int n,m;
void bsp()
{
    q.push(1);
    cnt[1]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=1;i<=6;i++)
        {
            int dx=x+i;
            if(dx>100)
            {
                continue;
            }
            if(snake.count(dx)==0&&ladder.count(dx)==0)
            {
                if(cnt[dx]==0)
                {
                    cnt[dx]=cnt[x]+1;
                    q.push(dx);
                }
                else if (cnt[dx]>cnt[x]+1)
                {
                    cnt[dx]=cnt[x]+1;
                    q.push(dx);
                }
            }  
            else if(snake.count(dx)!=0)
            {
                if(cnt[snake[dx]]==0)
                {
                    cnt[snake[dx]]=cnt[x]+1;
                    q.push(snake[dx]);
                }
                else if (cnt[snake[dx]]>cnt[x]+1)
                {
                    cnt[snake[dx]]=cnt[x]+1;
                    q.push(snake[dx]);
                }
            }
            else if(ladder.count(dx)!=0)
            {
                if(cnt[ladder[dx]]==0)
                {
                    cnt[ladder[dx]]=cnt[x]+1;
                    q.push(ladder[dx]);
                }
                else if (cnt[ladder[dx]]>cnt[x]+1)
                {
                    cnt[ladder[dx]]=cnt[x]+1;
                    q.push(ladder[dx]);
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int num1;
        int num2;
        cin>>num1>>num2;
        ladder[num1]=num2;
    }
    for(int i=0;i<m;i++)
    {
        int num1;
        int num2;
        cin>>num1>>num2;
        snake[num1]=num2;
    }
    bsp();
    cout <<cnt[100];
}