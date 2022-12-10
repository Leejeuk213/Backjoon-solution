#include<stdio.h>
using namespace std;
int n;
int cnt=0;
int ss[1000]={0,};
int num;
int strike;
int ball;
void solve(int nu,int s,int b)
{
    int num1=nu/100;
    int num2=(nu/10)%10;
    int num3=nu%10;
    for(int i=123;i<1000;i++)
    {
        int cs=0;
        int cb=0;
        if(i/100==num1){cs++;}
        if((i/10)%10==num2){cs++;}
        if(i%10==num3){cs++;}
        if(i/100!=num1&&(i/100==num2||i/100==num3)){cb++;}
        if((i/10)%10!=num2&&((i/10)%10==num1||(i/10)%10==num3)){cb++;}
        if(i%10!=num3&&(i%10==num1||i%10==num2)){cb++;}
        if(cs!=s||cb!=b||(i/10)%10==0||i%10==0||i/100==(i/10)%10||(i/10)%10==i%10||i/100==i%10){ss[i]=0;}
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=123;i<1000;i++)
    {
        ss[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&num,&strike,&ball);
        solve(num,strike,ball);
    }
    for(int i=123;i<1000;i++)
    {
        if(ss[i]==1)
        {
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}