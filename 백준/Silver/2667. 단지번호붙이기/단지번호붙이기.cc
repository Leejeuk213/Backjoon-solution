#include <iostream>
#include <algorithm>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int N;
int input[26][26];
int visited[26][26];
int cnt=0;
int ans[626]={0,};
void dsp(int x_,int y_,int index)
{
    for(int i=0;i<4;i++)
    {
        int x= x_+dx[i];
        int y= y_+dy[i];
        if(x<0||x>=N||y<0||y>=N)
        {
            continue;
        }
        else
        {
            if(input[x][y]==1&&visited[x][y]!=1)
            {
                visited[x][y]=1;
                ans[cnt]++;
                dsp(x,y,cnt);
            }
        }
    }
}
int main ()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%1d", &input[i][j]);
        }
	}
    for(int j=0;j<N;j++)
    {
        for(int k=0;k<N;k++)
        {
            if(input[j][k]==1&&visited[j][k]!=1)
            {
                visited[j][k]=1;
                ans[cnt]=1;
                dsp(j,k,cnt);
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    sort(&ans[0],&ans[cnt]);
    for(int i=0;i<cnt;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}