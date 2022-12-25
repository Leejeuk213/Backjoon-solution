#include<iostream>
#include<queue>
#include<string.h>
#include<tuple>
using namespace std;
int l,r,c;
int check[31][31][31];
char b[31][31][31];
int ans[31][31][31];
int rx[6]={0,0,1,-1,0,0};
int ry[6]={0,0,0,0,1,-1};
int rz[6]={1,-1,0,0,0,0};
void bfs(int f_z,int f_x,int f_y)
{
    queue<tuple<int,int,int>>q;
    q.push(make_tuple(f_z,f_x,f_y));
    while(!q.empty())
    {
        int z=get<0>(q.front());
        int x=get<1>(q.front());
        int y=get<2>(q.front());
        int cnt=ans[z][x][y];
        q.pop();
        for(int i=0;i<6;i++)
        {
            int cx=x+rx[i];
            int cy=y+ry[i];
            int cz=z+rz[i];
            if(cx<0||cy<0||cz<0||cz==l||cx==r||cy==c)
            {
                continue;
            }
            if(b[cz][cx][cy]=='E')
            {
                cout<<"Escaped in "<<cnt+1<<" "<<"minute(s)."<<"\n";
                return ;
            }
            if(check[cz][cx][cy]==0&&b[cz][cx][cy]=='.')
            {
                check[cz][cx][cy]=1;
                ans[cz][cx][cy]=ans[z][x][y]+1;
                q.push(make_tuple(cz,cx,cy));
            }
        }
    }
    cout<<"Trapped!"<<"\n";
    return ;
}
int main()
{
    while(1)
    {
        cin >>l>>r>>c;
        memset(check,0,sizeof(check));
        memset(ans,0,sizeof(ans));
        if(l==0&&r==0&&c==0)
        {
            break;
        }
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<r;j++)
            {
                cin>>b[i][j];
            }
        }
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<r;j++)
            {
                for(int k=0;k<c;k++)
                {
                    if(b[i][j][k]=='S')
                    {
                        bfs(i,j,k);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}