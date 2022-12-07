#include<iostream>
#include<string>
int n;
using namespace std;
char str[51][51];
int rx[4]={-1,0,0,1};
int ry[4]={0,-1,1,0};
int maxn=0;
void swap(int x,int y,int c_x,int c_y)
{
    char temp=str[x][y];
    str[x][y]=str[c_x][c_y];
    str[c_x][c_y]=temp;
}
void check(int x,int y,int c_x,int c_y)
{
    swap(x,y,c_x,c_y);
    //행
    char temp=str[x][0];
    int cnt=0;
    for(int j=0;j<n;j++)
    {
        if(temp!=str[x][j])
        {
            temp=str[x][j];
            cnt=1;
        }
        else
        {
            cnt++;
            if(maxn<cnt)
            {
                maxn=cnt;
            }
        }
    }
    //열
    temp=str[0][y];
    cnt=0;
    for(int j=0;j<n;j++)
    {
        if(temp!=str[j][y])
        {
            temp=str[j][y];
            cnt=1;
        }
        else
        {
            cnt++;
            if(maxn<cnt)
            {
                maxn=cnt;
            }
        }
    }
    swap(c_x,c_y,x,y);
}
void start()
{
    //행
    for(int i=0;i<n;i++)
    {
        char temp=str[i][0];
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(temp!=str[i][j])
            {
                temp=str[i][j];
                cnt=1;

            }
            else
            {
                cnt++;
                if(maxn<cnt)
                {
                    maxn=cnt;
                }
            }
        }
    }
    //열
    for(int i=0;i<n;i++)
    {
        char temp=str[0][i];
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(temp!=str[j][i])
            {
                temp=str[j][i];
                cnt=1;

            }
            else
            {
                cnt++;
                if(maxn<cnt)
                {
                    maxn=cnt;
                }
            }
        }
    }
}
void solve()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<4;k++)
            {
                int x=i+rx[k];
                int y=j+ry[k];
                if(x<0||y<0||x>=n||y>=n)
                {
                    continue;
                }
                if(str[i][j]!=str[x][y])
                {
                    check(i,j,x,y);
                }
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",str[i]);
    }
    start();
    solve();
    printf("%d",maxn);
    return 0;
}