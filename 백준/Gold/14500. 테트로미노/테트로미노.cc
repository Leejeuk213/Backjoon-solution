#include<stdio.h>
#include<string.h>
int n,m;
int paper[501][501];
int ans=0;
void tet1() //일자
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-3;j++)
        {
            if(ans<paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i][j+3])
            {
                ans=paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i][j+3];
            }
        }
    }
    for(int i=0;i<n-3;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ans<paper[i][j]+paper[i+1][j]+paper[i+2][j]+paper[i+3][j])
            {
                ans=paper[i][j]+paper[i+1][j]+paper[i+2][j]+paper[i+3][j];
            }
        }
    }
    return ;
}
void tet2() // 정사각형
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(ans<paper[i][j]+paper[i+1][j]+paper[i][j+1]+paper[i+1][j+1])
            {
                ans=paper[i][j]+paper[i+1][j]+paper[i][j+1]+paper[i+1][j+1];
            }
        }
    }
    return ;
}
void tet3() //3*1
{
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(ans<paper[i][j]+paper[i+1][j]+paper[i+2][j]+paper[i+2][j+1])
            {
                ans=paper[i][j]+paper[i+1][j]+paper[i+2][j]+paper[i+2][j+1];
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            if(ans<paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i-1][j+2])
            {
                ans=paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i-1][j+2];
            }
        }
    }
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(ans<paper[i][j]+paper[i][j+1]+paper[i+1][j+1]+paper[i+2][j+1])
            {
                ans=paper[i][j]+paper[i][j+1]+paper[i+1][j+1]+paper[i+2][j+1];
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            if(ans<paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i+1][j])
            {
                ans=paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i+1][j];
            }
        }
    }
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(ans<paper[i][j]+paper[i+1][j]+paper[i+2][j]+paper[i][j+1])
            {
                ans=paper[i][j]+paper[i+1][j]+paper[i+2][j]+paper[i][j+1];
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            if(ans<paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i+1][j+2])
            {
                ans=paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i+1][j+2];
            }
        }
    }
    for(int i=2;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(ans<paper[i][j]+paper[i][j+1]+paper[i-1][j+1]+paper[i-2][j+1])
            {
                ans=paper[i][j]+paper[i][j+1]+paper[i-1][j+1]+paper[i-2][j+1];
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            if(ans<paper[i][j]+paper[i+1][j]+paper[i+1][j+1]+paper[i+1][j+2])
            {
                ans=paper[i][j]+paper[i+1][j]+paper[i+1][j+1]+paper[i+1][j+2];
            }
        }
    }
    return ;
}
void tet4()  // 2*2 
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            if(ans<paper[i][j]+paper[i][j+1]+paper[i-1][j+1]+paper[i-1][j+2])
            {
                ans=paper[i][j]+paper[i][j+1]+paper[i-1][j+1]+paper[i-1][j+2];
            }
        }
    }
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(ans<paper[i][j]+paper[i+1][j]+paper[i+1][j+1]+paper[i+2][j+1])
            {
                ans=paper[i][j]+paper[i+1][j]+paper[i+1][j+1]+paper[i+2][j+1];
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            if(ans<paper[i][j]+paper[i][j+1]+paper[i+1][j+1]+paper[i+1][j+2])
            {
                ans=paper[i][j]+paper[i][j+1]+paper[i+1][j+1]+paper[i+1][j+2];
            }
        }
    }
    for(int i=2;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(ans<paper[i][j]+paper[i-1][j]+paper[i-1][j+1]+paper[i-2][j+1])
            {
                ans=paper[i][j]+paper[i-1][j]+paper[i-1][j+1]+paper[i-2][j+1];
            }
        }
    }
    return;
}
void tet5() //1 *3
{
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(ans<paper[i][j]+paper[i+1][j]+paper[i+2][j]+paper[i+1][j+1])
            {
                ans=paper[i][j]+paper[i+1][j]+paper[i+2][j]+paper[i+1][j+1];
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            if(ans<paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i-1][j+1])
            {
                ans=paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i-1][j+1];
            }
        }
    }
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(ans<paper[i+1][j]+paper[i+1][j+1]+paper[i+2][j+1]+paper[i][j+1])
            {
                ans=paper[i+1][j]+paper[i+1][j+1]+paper[i+2][j+1]+paper[i][j+1];
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            if(ans<paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i+1][j+1])
            {
                ans=paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i+1][j+1];
            }
        }
    }
    return;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&paper[i][j]);
        }
    }
    tet1();
    tet2();
    tet3();
    tet4();
    tet5();
    printf("%d",ans);
    return 0;
}