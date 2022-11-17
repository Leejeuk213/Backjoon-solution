#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int roop;
        map <int,int> m;
        cin>>roop;
        priority_queue<int,vector<int>,less<int>> q;
        priority_queue<int,vector<int>,greater<int>> q2;
        for(int j=0;j<roop;j++)
        {
            char a;
            int num;
            cin>>a>>num;
            if(a=='I')
            {
                if(m.count(num)==0)
                {
                    m[num]=1;
                }
                else
                {
                    m[num]++;
                }
                q.push(num);
                q2.push(num);
            }
            else if(a=='D')
            {
                if(num==-1)
                {
                    while(!q2.empty()&&m[q2.top()]==0)
                    {
                        q2.pop();
                    }   
                    if(!q2.empty())
                    {
                        m[q2.top()]--;
                        q2.pop();
                    }  
                }
                else
                { 
                    while(!q.empty()&&m[q.top()]==0)
                    {
                        q.pop();
                    }   
                    if(!q.empty())
                    {
                        m[q.top()]--;
                        q.pop();
                    }
                }
            }
        }
        while(!q.empty()&&m[q.top()]==0)
        {
            q.pop();
        }
        while(!q2.empty()&&m[q2.top()]==0)
        {
            q2.pop();
        }  
        if(q.empty()||q2.empty())
        {
            cout<<"EMPTY"<<"\n";
        }
        else
        {
            cout<<q.top()<<" "<<q2.top()<<"\n";
        }
    }
    return 0;
}