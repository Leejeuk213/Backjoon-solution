#include <iostream>
#include<queue>
using namespace std;
int max(int a,int b)
{
  if(a>=b)
  {
    return a;
  }
  else
  {
    return b;
  }
}
int test;
int dp[3][100002];
int sticker[2][100002];
int roop;
int main()
{
  scanf("%d",&test);
  for(int i=0;i<test;i++)
  {
    scanf("%d",&roop);
    for(int j=0;j<roop;j++)
    {
        scanf("%d",&sticker[0][j]);  
    }
    for(int j=0;j<roop;j++)
    {
         scanf("%d",&sticker[1][j]);  
    }
    dp[0][0]=sticker[0][0];
    dp[1][0]=sticker[1][0];
    dp[2][0]=0;
    int big=max(dp[0][0],dp[1][0]);
    for(int j=1;j<roop;j++)
    {
        for(int k=0;k<3;k++)
        {
          if(k==0)
          {
            dp[k][j]=max(dp[1][j-1]+sticker[0][j],dp[2][j-1]+sticker[0][j]);
          }
          if(k==1)
          {
             dp[k][j]=max(dp[0][j-1]+sticker[1][j],dp[2][j-1]+sticker[1][j]);
          }
          if(k==2)
          {
            dp[k][j]=max(dp[0][j-1],dp[1][j-1]);
          }
          if(big<dp[k][j])
          {
            big=dp[k][j];
          }
        }
    }
    printf("%d\n",big);
  }
  return 0;
}