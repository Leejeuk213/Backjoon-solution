#include<stdio.h>
#include<queue>
using namespace std;

int main()
{
    int roop;
    priority_queue<int,vector<int>,greater<int>> a;

    scanf("%d",&roop);
    for(int i=0;i<roop;i++)
    {
        int num;
        scanf("%d",&num);
        if(num==0)
        {
            if(a.empty())
            {
                printf("0\n");
            }
            else
            {
                int d=a.top();
                a.pop();
                printf("%d\n",d);
                
            }
        }
        else
        {
            a.push(num);
        }
    }
    return 0;
}