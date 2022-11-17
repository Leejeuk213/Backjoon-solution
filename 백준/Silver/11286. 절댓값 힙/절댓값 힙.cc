#include<stdio.h>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
struct cmp{
    bool operator()(int a, int b){
        if(abs(a)==abs(b))
        {
            return a>b;
        }
        else
        {
            return abs(a)>abs(b);
        }
    }
};
int main()
{
    int roop;
    priority_queue<int,vector<int>,cmp> a;

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