#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int>s_q;
priority_queue<int,vector<int>,greater<int>>r_q;
int mid;

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%d",&mid);
    printf("%d\n",mid);
    for(int i=1;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        if(num>=mid)
        {
            r_q.push(num);
        }
        else
        {
            s_q.push(num);
        }
        if(s_q.size()>r_q.size()+1)
        {
            int temp=mid;
            mid=s_q.top();
            s_q.pop();
            r_q.push(temp);
            printf("%d\n",mid);
        }
        else if(s_q.size()+1<r_q.size())
        {
            int temp=mid;
            mid=r_q.top();
            r_q.pop();
            s_q.push(temp);
            printf("%d\n",mid);
        }
        else if((i+1)%2==0&&s_q.size()==r_q.size()+1)
        {
            int temp=mid;
            mid=s_q.top();
            s_q.pop();
            r_q.push(temp);
            printf("%d\n",mid);
        }
        else
        {
            printf("%d\n",mid);
        }
    }
    return 0;
}
