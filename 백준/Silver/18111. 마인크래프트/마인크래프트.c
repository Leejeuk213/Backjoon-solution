#include<stdio.h>

int tail[500][500];
int big=0;
int sum=0;
int main()
{
    int n,m,b;
    scanf("%d %d %d",&n,&m,&b);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&tail[i][j]);
            if(big<=tail[i][j])
            {
                big=tail[i][j];
            }
            sum=sum+tail[i][j];
        }
    }
    int time_ans=100000000;
    int height_ans=0;
    for(int k=0;k<=big;k++)
    {
        int time=0;
        int height=k;
        int use=b;
        int test[n][m];
        if(sum+b<k*n*m)
        {
            break;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                test[i][j]=tail[i][j];
                if(test[i][j]>k)
                {
                    while(test[i][j]!=k)
                    {
                        test[i][j]--;
                        use++;
                        time=time+2;
                    }
                }
                else if(test[i][j]<k)
                {
                     while(test[i][j]!=k)
                    {
                        test[i][j]++;
                        use--;
                        time=time+1;
                    }
                }
            }
        }
        if(time_ans>=time)
        {
            time_ans=time;
            height_ans=height;
        }
    }
    printf("%d %d",time_ans,height_ans);
    return 0;
}