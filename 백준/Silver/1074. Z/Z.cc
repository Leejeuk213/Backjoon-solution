#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int ans=0;
int n,m;
void solve(int x,int y,int size)
{
    if(x==n&&y==m)
    {
        printf("%d",ans);
        exit(0);
    }
    if(x+size>n&&y+size>m)
    {
      solve(x,y,size/2);
    solve(x,y+size/2,size/2);
    solve(x+size/2,y,size/2);
    solve(x+size/2,y+size/2,size/2);
    }
    else
    {
        ans=ans+size*size;
        return ;
    }
      
}
int main()
{
    int roop;
    scanf("%d %d %d",&roop,&n,&m);
    solve(0,0,pow(2,roop));
    return 0;
}