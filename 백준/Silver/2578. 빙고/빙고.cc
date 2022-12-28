#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>>v[26];
int bingo[5][5];
int cnt=0;
int num[26];
int check[5][5];
int bingocheck()
{
    int bingocnt=0;
    //행체크
    for(int i=0;i<5;i++)
    {
        int ok=1;
        for(int j=0;j<5;j++)
        {
            if(check[i][j]!=1)
            {
                ok=0;
                break;
            }
        }
        if(ok)
        {
            bingocnt++;
        }
    }

    //열체크
    for(int i=0;i<5;i++)
    {
        int ok=1;
        for(int j=0;j<5;j++)
        {
            if(check[j][i]!=1)
            {
                ok=0;
                break;
            }
        }
        if(ok)
        {
            bingocnt++;
        }
    }

    //대각선 체크
    for(int i=0;i<5;i++)
    {
        if(check[i][i]!=1)
        {
            break;
        }
        if(i==4)
        {
            bingocnt++;
        }
    }
    for(int i=4;i>=0;i--)
    {
        if(check[4-i][i]!=1)
        {
            break;
        }
        if(i==0)
        {
            bingocnt++;
        }
    }
    return bingocnt;
}
int main()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>bingo[i][j];
            v[bingo[i][j]].push_back(make_pair(i,j));
        }
    }
    int ans=0;
    for(int i=1;i<=25;i++)
    {
        cin>>num[i];

    }
    for(int i=1;i<=25;i++)
    {
        int x=v[num[i]][0].first;
        int y=v[num[i]][0].second;
        check[x][y]=1;
        if(bingocheck()>=3)
        {
            ans=i;
            break;
        }
    }
    cout<<ans;
    return 0;
}