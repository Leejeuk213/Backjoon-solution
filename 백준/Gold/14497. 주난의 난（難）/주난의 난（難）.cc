#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
using namespace std;

int rx[4]={0,0,-1,1};
int ry[4]={-1,1,0,0};
int n,m;
int visit[301][301];
char room[301][301];
int x1,y1,x2,y2;
int cnt=0;
void bfs()
{
    queue<pair<int,int>>q;
    while(1)
    {
        cnt++;
        q.push(make_pair(x1,y1));
        memset(visit,0,sizeof(visit));
        while(!q.empty())
        {
            int fx=q.front().first;
            int fy=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=fx+rx[i];
                int y=fy+ry[i];

                if(x<0||y<0||x==n||y==m) continue;

                if(room[x][y]=='*') continue;

                if(room[x][y]=='#') return;
            
                if(room[x][y]=='1') 
                {
                    visit[x][y]=1;
                    room[x][y]='0';
                }
                else if(room[x][y]=='0'&&visit[x][y]==0) 
                {
                    visit[x][y]=1;
                    q.push(make_pair(x,y));
                }

            }
        }
    }
}
int main()
{
    cin >>n>>m;
    cin >>x1>>y1>>x2>>y2;
    x1--;
    y1--;
    x2--;
    y2--;
    for(int i=0;i<n;i++)
    {
        cin >>room[i];
    }
    
    bfs();

    cout <<cnt;
    return 0;
}