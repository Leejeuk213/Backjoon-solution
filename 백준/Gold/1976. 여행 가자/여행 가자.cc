#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int>ans;
int parent[201];
int n,m;
int find(int x)
{
    if(parent[x] < 0)return x;
    
    return parent[x]=find(parent[x]);
}

void union_(int x, int y) 
{
    x = find(x);
    y = find(y);

    if (x == y)return;

    // parent[x], parent[y] 값은 음수이므로 값이 작은 경우가 더 높이가 큰 노드이다.
    if (parent[x] < parent[y])
    {
        parent[x] += parent[y];
        parent[y] = x;
    }
    else 
    {
        parent[y] += parent[x];
        parent[x] = y;
    }
    return;
}

int main()
{
    cin.tie(0);
	cin.sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
    cin >>n>>m;
    for(int i=1;i<=n;i++) parent[i]=-1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int num;
            cin >>num;
            if(num==1) union_(i,j);
        }
    }
    for(int i=0;i<m;i++)
    {
        int num;
        cin >>num;
        ans.push_back(num);
    }
    int recent=find(ans[0]);
    for(int i=1;i<m;i++)
    {
        int num1=find(ans[i]);
        if(recent!=num1)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}