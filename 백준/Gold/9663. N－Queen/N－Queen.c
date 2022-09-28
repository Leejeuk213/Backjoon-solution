#include<stdio.h>
int m;
int c=1;
int board[16][16];
int cnt=0;
int check(int row, int col)
{
    //가로체크
    for(int i=1;i<=m;i++)
    {
        if(board[row][i]==1)
        {
            return 0;
        }
    }
    //세로체크
    for(int i=1;i<=m;i++)
    {
        if(board[i][col]==1)
        {
            return 0;
        }
    }
  //대각선 1체크
    int a=row;
    int b=col;
    while(a!=m&&b!=1)
    {
        a++;
        b--;
    }
    while(1)
    {
        if(a==0||b>m)
        {
            break;
        }
        if(board[a][b]==1)
        {
            return 0;
        }
    a--;
    b++;
    }
    //대각선 2체크
    a=row;
    b=col;
    while(a!=1&&b!=1)
    {
        a--;
        b--;
    }
    while(1)
    {
        if(a>m||b>m)
        {
            break;
        }
        if(board[a][b]==1)
        {
            return 0;
        }
    a++;
    b++;
    }  
return 1;
}
void queen(int depth)
{
    if(depth==m)
    {
        cnt++;
        //return;
    }
    else
    {           
            int j=depth+1;       
            for(int k=1;k<=m;k++)
            {
                if(check(k,j))
                {
                    board[k][j]=1;
                    queen(depth+1);
                    board[k][j]=0;
                }
            }    
    }
}
int main()
{
   scanf("%d",&m);
   for(int i=1;i<=m;i++)
   {
        board[i][1]=1;
        queen(1);
        board[i][1]=0;
   }
   printf("%d",cnt);
    return 0;
}