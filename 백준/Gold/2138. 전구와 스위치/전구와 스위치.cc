#include<stdio.h>
#include<algorithm>
using namespace std;
int uncorrect[100001];
int uncorrect2[100001];
int correct[100001];
int n;
int ans=0;
int ans2=1;
void check()
{
    for(int i=0;i<n;i++)
    {
        if(uncorrect2[i]!=correct[i])
        {
            ans2=987654321;
        }
        if(uncorrect[i]!=correct[i])
        {
            ans=987654321;
        }
    }
    return;
}
void sw(int a,int b,int c)
{
    if(uncorrect[a]==0)
    {
        uncorrect[a]=1;
    }
    else
    {
        uncorrect[a]=0;
    }

    if(uncorrect[b]==0)
    {
        uncorrect[b]=1;
    }
    else
    {
        uncorrect[b]=0;
    }

    if(uncorrect[c]==0)
    {
        uncorrect[c]=1;
    }
    else
    {
        uncorrect[c]=0;
    }
    return;
}
void sw2(int a,int b,int c)
{
    if(uncorrect2[a]==0)
    {
        uncorrect2[a]=1;
    }
    else
    {
        uncorrect2[a]=0;
    }

    if(uncorrect2[b]==0)
    {
        uncorrect2[b]=1;
    }
    else
    {
        uncorrect2[b]=0;
    }

    if(uncorrect2[c]==0)
    {
        uncorrect2[c]=1;
    }
    else
    {
        uncorrect2[c]=0;
    }
    return;
}
void on()
{
    for(int i=1;i<n-1;i++)
    {
        if(uncorrect[i-1]!=correct[i-1])
        {
            sw(i-1,i,i+1);
            ans++;
        }
    }
    if(uncorrect[n-2]!=correct[n-2])
    {
        if(uncorrect[n-2]==0)
        {
            uncorrect[n-2]=1;
        }
        else
        {
            uncorrect[n-2]=0;
        }
        if(uncorrect[n-1]==0)
        {
            uncorrect[n-1]=1;
        }
        else
        {
            uncorrect[n-1]=0;
        }
        ans++;
    }
    return ;
}
void on2()
{
    if(uncorrect2[0]==0)
    {
        uncorrect2[0]=1;
    }
    else
    {
        uncorrect2[0]=0;
    }
    if(uncorrect2[1]==0)
    {
        uncorrect2[1]=1;
    }
    else
    {
        uncorrect2[1]=0;
    }
    for(int i=1;i<n-1;i++)
    {
        if(uncorrect2[i-1]!=correct[i-1])
        {
            sw2(i-1,i,i+1);
            ans2++;
        }
    }
    if(uncorrect2[n-2]!=correct[n-2])
    {
        if(uncorrect2[n-2]==0)
        {
            uncorrect2[n-2]=1;
        }
        else
        {
            uncorrect2[n-2]=0;
        }
        if(uncorrect2[n-1]==0)
        {
            uncorrect2[n-1]=1;
        }
        else
        {
            uncorrect2[n-1]=0;
        }
        ans2++;
    }
    return ;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%1d",&uncorrect[i]);
        uncorrect2[i]=uncorrect[i];
    }
    for(int i=0;i<n;i++)
    {
        scanf("%1d",&correct[i]);
    }
    on();
    on2();
    check();
    if(ans==987654321&&ans2==987654321)
    {
        printf("-1");
        return 0;
    }
    printf("%d",min(ans,ans2));
    return 0;
}   