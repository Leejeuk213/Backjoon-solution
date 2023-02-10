#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int parent[1000001];
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
    for(int i=0;i<=n;i++) parent[i]=-1;

    for(int i=0;i<m;i++)
    {
        int q,w,e;
        cin >>q>>w>>e;
        if(q==1)
        {
            if(find(w)==find(e)) cout<<"YES"<<"\n";
            else cout <<"NO"<<"\n";
        }
        else
        {
            union_(w,e);
        }
    }
    return 0;
}