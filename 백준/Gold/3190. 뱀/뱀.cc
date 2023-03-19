#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int n,k,l;
int board[101][101];
queue<pair<int,char>> q;
int ans = 0;
int cnt[10001] = {0,};
queue<pair<int,int>>snake;
void solve()
{
    int vec = 1;
    int size = 1;
    int x = 0;
    int y = 0;
    snake.push(make_pair(0,0));
    board[x][y]= 2; // 뱀의 차지
    while(1)
    {
        // 1이면 우 2이면 하 3이면 좌 0면 상
        if(vec == 1) y ++;
        else if(vec == 2) x ++;
        else if(vec == 3) y --;
        else if(vec == 0) x --;

        if(x<0||y<0||x>=n||y>=n||board[x][y]==2) return;
        snake.push(make_pair(x,y));
        if(board[x][y] == 1) size++;
        else
        {
            board[snake.front().first][snake.front().second]=0;
            snake.pop();
            size--;
        }
        board[x][y]=2;
        ans++;
        if(cnt[ans]==1)
        {
            char a = q.front().second;
            q.pop();
            if(a=='D') vec = (vec+1)%4;
            else if (a=='L')
            {
                if(vec == 0) vec = 3;
                else vec = vec -1;
            }
        }
    }
    return ;
}
int main()
{
    cin >>n>>k;
    while(k--)
    {
        int i,j;
        cin >>i >>j;
        board[i-1][j-1]=1;
    }
    cin >>l;
    while(l--)
    {
        char x;
        int z;
        cin >>z>>x;
        q.push(make_pair(z,x));
        cnt[z]=1;
    }
    solve();
    
    cout <<ans+1;
    return 0;
}