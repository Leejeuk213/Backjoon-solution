#include<stdio.h>
#include<queue>

using namespace std;

int main()
{
    queue<int>a;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        a.push(i);
    }
    while(a.size()!=1)
    {
        a.pop();
        int num=a.front();
        a.push(num);
        a.pop();
    }
    printf("%d",a.front());
    return 0;
}