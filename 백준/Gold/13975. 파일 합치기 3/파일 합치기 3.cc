#include<iostream>
#include<queue>
using namespace std;
int n;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        priority_queue<long long,vector<long long>,greater<long long>>q;
        int q_size;
        cin>>q_size;
        for(int j=0;j<q_size;j++)
        {
            int num;
            cin >> num;
            q.push(num);
        }
        long long hand=q.top();
        q.pop();
        hand=hand+q.top();
        long long ans=0;
        q.pop();
        while(!q.empty())
        {
            long long temp=q.top();
            q.pop();
            if(q.empty())
            {
                ans=ans+hand+temp+hand;
                break;
            }
            if(temp+q.top()<temp+hand)
            {
                q.push(temp);
                q.push(hand);
                ans=ans+hand;
                hand=q.top();
                q.pop();
                hand=hand+q.top();
                q.pop();
            }
            else
            {
                q.push(hand+temp);
                ans=ans+hand+temp+hand;
                hand=q.top();
                q.pop();
                hand=hand+q.top();
                q.pop();
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}