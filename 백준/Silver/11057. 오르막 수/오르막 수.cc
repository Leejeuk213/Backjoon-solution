#include <iostream>
long long dp[1002][10];
int main() {
    int n;
    scanf("%d",&n);
    dp[1][0]=1;
    dp[1][1]=2;
    dp[1][2]=3;
    dp[1][3]=4;
    dp[1][4]=5;
    dp[1][5]=6;
    dp[1][6]=7;
    dp[1][7]=8;
    dp[1][8]=9;
    dp[1][9]=10;
    for(int i=2;i<=n;i++)
    {
      int carry=0;
       for(int j=0;j<10;j++)
        {
          carry=(carry+dp[i-1][j])%10007;
           dp[i][j]=carry;
        }
    }
    printf("%lld",dp[n][9]);
    return 0;
}