#include<stdio.h>
int dp[100002][3];
int main()
{
    int roop;
    scanf("%d",&roop);
    dp[1][0]=1; dp[1][1]=1; dp[1][2]=1;
    for(int i=2;i<=roop;i++)
    {
        dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%9901;
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%9901;
        dp[i][2]=(dp[i-1][1]+dp[i-1][0])%9901;
    }
    printf("%d",(dp[roop][0]+dp[roop][1]+dp[roop][2])%9901);
    return 0;
}