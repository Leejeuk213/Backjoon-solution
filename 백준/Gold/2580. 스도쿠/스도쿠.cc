#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int board[9][9] ;
int rx[3];
int ry[3];
int cnt=0;
bool checking(int x, int y,int value)
{
    for(int i=0;i<9;i++)
    {
        if(board[x][i] == value) return false;
        if(board[i][y] == value) return false;
    }

    if(x%3==0)
    {
        rx[0]=0;
        rx[1]=1;
        rx[2]=2;
    }
    else if(x%3==1)
    {
        rx[0]=-1;
        rx[1]=0;
        rx[2]=1;
    }
    else if(x%3==2)
    {
        rx[0]=-2;
        rx[1]=-1;
        rx[2]=0;
    }

    if(y%3==0)
    {
        ry[0]=0;
        ry[1]=1;
        ry[2]=2;
    }
    else if(y%3==1)
    {
        ry[0]=-1;
        ry[1]=0;
        ry[2]=1;
    }
    else if(y%3==2)
    {
        ry[0]=-2;
        ry[1]=-1;
        ry[2]=0;
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int tx=x+rx[i];
            int ty=y+ry[j];      
            if(board[tx][ty] == value) return false;
        }
    }
    return true;
}

void back(int depth,int x, int y)
{
    if(depth==cnt)
    {
        cout<<"\n";
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout << board[i][j] <<" ";
            }
            cout<<"\n";
        }
        exit(0);
    }
    for(int i=x;i<9;i++)
    {
        for(int j=y;j<9;j++)
        {
            if(board[i][j]==0) // 판별하고 백트래킹 시작
            {
                for(int k=1;k<10;k++)
                {
                    if(checking(i,j,k))
                    {
                        board[i][j]=k;
                        back(depth+1,i,j+1);
                        board[i][j]=0;
                    }
                    if(k==9) return;
                }
            }
        }
        y=0;
    }
    return ;
}

int main()
{

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin >>board[i][j];
            if(board[i][j]==0) cnt++;
        }
    }

    back(0,0,0); 
    return 0;
}