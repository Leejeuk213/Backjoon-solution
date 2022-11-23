#include<stdio.h>
int input[51][51];
int correct[51][51];
int n,k;
int ans=0;
int iscorrect()
{  
    int cnt=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(input[i][j]!=correct[i][j])
            {
                return 0;
            }
        }
    }
    return cnt;
}
int change(int x,int y)
{
    int check=0;
    if(x+2>=n||y+2>=k||input[x][y]==correct[x][y])
    {
        return check;
    }
    for(int i=x;i<=x+2;i++)
    {
        for(int j=y;j<=y+2;j++)
        {
            if(input[i][j]==0)
            {
                input[i][j]=1;
            }
            else if(input[i][j]==1)
            {
                input[i][j]=0;
            }
        }
    }
    return 1;
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            scanf("%1d",&input[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            scanf("%1d",&correct[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(change(i,j))
            {
                ans++;
            }
            if(iscorrect())
            {
                printf("%d",ans);
                return 0;
            }
        }
    }
    printf("-1");
    return 0;
}