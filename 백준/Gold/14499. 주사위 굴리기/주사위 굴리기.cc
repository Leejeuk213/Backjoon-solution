#include<iostream>

using namespace std;
int n,m,x,y,k;
int map[21][21];
int operate[1001];
int row[3]={0,};
int col[4]={0,}; 

void role(int a)
{
    if(a==1)
    {
        int temp = row[0];
        row[0] = row[1];
        row[1] = row[2];
        row[2] = col[3];
        col[3] = temp;
        col[1] = row[1];
    }
    else if(a==2)
    {
        int temp = row[2];
        row[2] = row[1];
        row[1] = row[0];
        row[0] = col[3];
        col[3] = temp;
        col[1] = row[1];
    }
    else if(a==3)
    {
        int temp = col[0];
        col[0] = col[1];
        col[1] = col[2];
        col[2] = col[3];
        col[3] = temp;
        row[1] = col[1];
    }
    else if(a==4)
    {
        int temp = col[3];
        col[3] = col[2];
        col[2] = col[1];
        col[1] = col[0];
        col[0] = temp;
        row[1] = col[1];
    }
    return;
}
void solve()
{

    for(int i=0;i<k;i++)
    {
        int te_x=x;
        int te_y=y;  

        if(operate[i]==1) te_y++;
        else if(operate[i]==2) te_y--;
        else if(operate[i]==3) te_x--;
        else if(operate[i]==4) te_x++;


        if(te_x<0||te_y<0||te_x>=n||te_y>=m) continue;

        x=te_x;
        y=te_y;

        if(map[x][y]==0)
        {
            role(operate[i]);
            map[x][y]=row[1];
        }
        else
        {
            role(operate[i]);
            row[1]=map[x][y];
            col[1]=map[x][y];
            map[x][y]=0;
        }
        
        cout <<col[3]<<"\n";
    }
    return ;
}
int main()
{
    cin >>n>>m>>x>>y>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> map[i][j];
        }
    }
    for(int i=0;i<k;i++)
    {   
        cin >>operate[i];
    }
    solve();
    return 0;
}