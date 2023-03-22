#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;

int map[1001][1001];
int ans[1001][1001];
int zero[1001][1001]; //0의 개수
int visit[1001][1001];
int n,m;
int rx[4]={0,0,1,-1};
int ry[4]={1,-1,0,0};
int check=0;
void bfs(int x, int y)
{
    check +=1;
    queue<pair<int,int>>q;
    queue<pair<int,int>>total_q;
    q.push(make_pair(x,y));
    total_q.push(make_pair(x,y));
    visit[x][y]=check;
    int cnt=1;
    while(!q.empty())
    {
        int fx=q.front().first;
        int fy=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int lx = fx+rx[i];
            int ly = fy+ry[i];
            if(lx<0||ly<0||lx>=n||ly>=m) continue;

            if(visit[lx][ly]==0&&map[lx][ly]==0)
            {
                visit[lx][ly]=check;
                cnt++;
                q.push(make_pair(lx,ly));
                total_q.push(make_pair(lx,ly));
            }
        }

    }
    
    while(!total_q.empty())
    {
        int rx = total_q.front().first;
        int ry = total_q.front().second;
        zero[rx][ry]=cnt;
        total_q.pop();
    }
    return ;
}

int main()
{

    cin >>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%1d",&map[i][j]);
        }
    }
    if(n==1&&m==1&&map[0][0]==1) 
    {
        cout<<"1";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j]==0&&visit[i][j]==0) bfs(i,j);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int sum=1;
            vector<tuple<int,int,int>>v;
            if(map[i][j]==1)
            {
                for(int k=0;k<4;k++)
                {
                    int x = i+rx[k];
                    int y = j+ry[k];
                    if(x<0||y<0||x>=n||y>=m) continue;
                    v.push_back(make_tuple(visit[x][y],x,y));
                }
                sort(v.begin(),v.end());
                int bef_x = get<0>(v[0]);
                int y = get<1>(v[0]);
                int z = get<2>(v[0]);
                sum += zero[y][z];
                for(int i=1;i<v.size();i++)
                {
                    int x = get<0>(v[i]);
                    y = get<1>(v[i]);
                    z = get<2>(v[i]);
                    if(bef_x==x) continue;

                    bef_x=x;
                    sum +=zero[y][z];
                }
                ans[i][j] = sum%10;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ans[i][j];
        }
        cout<<"\n";
    }
    return 0;
}