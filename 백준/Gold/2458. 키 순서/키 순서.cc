#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int INF=987654321;
int d[501][501];
int cnt=0;
int ans[501][501];
int n,m;
int main()
{
    cin >>n;
    cin >>m;

    for(int i=0;i<m;i++)
    {
        int q,w;
        cin >>q>>w;
        d[q][w]=1; // q는 w보다 작다
        d[w][q]=2; // w는 q보다 크다
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)ans[i][j]=0;
            else if(d[i][j]) ans[i][j]=d[i][j];
            else ans[i][j]=INF; 
        }
    }
    
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(ans[i][j]==INF)
                {
                    if(ans[i][k]==1&&ans[k][j]==1) ans[i][j]=1;
                    if(ans[i][k]==2&&ans[k][j]==2) ans[i][j]=2;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cnt++;
        for(int j=1;j<=n;j++)
        {
            if(ans[i][j]==INF)
            {
                cnt--;
                break;
            }
        }
    }
    cout <<cnt;
    return 0;
}