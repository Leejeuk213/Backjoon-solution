#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;
deque<int> s;
int n,k;
int main()
{
    scanf("%d %d",&n,&k);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int num;
        scanf("%1d",&num);
        if(s.empty())
        {
            s.push_back(num);
            continue;
        }
        if(s.back()>=num||cnt==k)
        {
            s.push_back(num);
        }    
        else if(s.back()<num&&cnt<k)
        {
            while(s.back()<num&&cnt<k)
            {
                s.pop_back();
                cnt++;
                if(s.empty())
                {
                    break;
                }
            }
            s.push_back(num);
        }
    }
    for(int i=0;i<n-k;i++)
    {
        printf("%d",s.front());
        s.pop_front();
    }
    return 0;
}