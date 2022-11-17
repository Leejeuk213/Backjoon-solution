#include<stdio.h>
int n;
using namespace std;

int ans[3]={0,};
int paper[2200][2200];
int check(int x,int y,int index)
{
    int c=paper[x][y];
    for(int i=x;i<index+x;i++)
    {
        for(int j=y;j<index+y;j++)
        {
            if(paper[i][j]!=paper[x][y])
            {
                return 0;
            }
        }
    }
    return 1;
}
void find(int x,int y,int n)
{
    if(check(x,y,n))
    {
        ans[paper[x][y]+1]++;
        return;
    }
    int div=n/3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            find(x+div*i,y+div*j,div);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&paper[i][j]);
        }
    }
    find(0,0,n);
    for(int i=0;i<=2;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}