#include<iostream>
#include<queue>
using namespace std;
int roop;
int cnt=0;
priority_queue<int,vector<int>,greater<int>> q;
int main()
{
    cin >>roop;
    if(roop==1)
    {
        cout<<'0';
        return 0;
    }
    for(int i=0;i<roop;i++)
    {
        int num;
        cin >> num;
        q.push(num);
    }
    int num1;
    int num2;
    while(!q.empty())
    {
        num1=q.top();
        cnt=cnt+num1;
        q.pop();
        if(q.empty())
        {
            break;
        }
        num2=q.top();
        cnt=cnt+num2;
        q.pop();
        if(q.empty())
        {
            break;
        }
        q.push(num1+num2);
    }
    cout << cnt;
    return 0;
}