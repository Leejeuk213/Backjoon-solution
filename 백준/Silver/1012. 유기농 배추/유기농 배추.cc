#include<stdio.h>
int roop;
    int row,col,num;
    int row_tile;
    int col_tile;
int cnt=0;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
void dfs(int parm[51][51],int checkparm[51][51],int row_tile,int col_tile)
{
    for(int i=0;i<4;i++)
    {
        int x=row_tile+dx[i];
        int y=col_tile+dy[i];
        if(x<0||x>=row||y>=col||y<0)
        continue;
        if(parm[x][y]==1&&checkparm[x][y]!=1)
        {
            checkparm[x][y]=1;
            dfs(parm,checkparm,x,y);
        }
    }
}
int main()
{
    scanf("%d",&roop);
    for(int i=0;i<roop;i++)
    {
        scanf("%d %d %d",&row,&col,&num);
        int parm[51][51]={0,};
        int checkparm[51][51]={0,};
        cnt=0;
        for(int j=0;j<num;j++)
        {
            scanf("%d %d",&row_tile,&col_tile);
            parm[row_tile][col_tile]=1;
        }
        for(int j=0;j<row;j++)
        {
            for(int k=0;k<col;k++)
            {
                if(parm[j][k]==1&&checkparm[j][k]!=1)
                {
                    checkparm[j][k]=1;
                    cnt++;
                    dfs(parm,checkparm,j,k);
                }
            }
        }
        printf("%d\n",cnt);
    }
}