#include<iostream>
#include<string>
#include<queue>
using namespace std;
int start,finish;
string bfs()
{
    string visit[10000];
    queue<pair<int,string>> q;
    q.push(make_pair(start,""));
    while(!q.empty())
    {
        int num=q.front().first;
        string temp=q.front().second;
        q.pop();
        if(num==finish)
        {
            return temp;
        }
        int k=(num*2)%10000;
        if(k==finish)
        {
            return temp+'D';
        }  
        if(visit[k].size()==0)
        {
            q.push(make_pair(k,temp+'D'));
            visit[k]=temp+'D';
        }
        k=num-1;
        if(num==0) k=9999;
        if(k==finish)
        {
            return temp+'S';
        }  
        if(visit[k].size()==0)
        {
            q.push(make_pair(k,temp+'S'));
            visit[k]=temp+'S';
        }
        
        k=(num%1000)*10+num/1000;
        if(k==finish)
        {
            return temp+'L';
        }  
        if(visit[k].size()==0)
        {
            q.push(make_pair(k,temp+'L'));
            visit[k]=temp+'L';
        }
        
        k=(num%10)*1000+(num/10);
        if(k==finish)
        {
            return temp+'R';
        } 
        if(visit[k].size()==0)
        {
            q.push(make_pair(k,temp+'R'));
            visit[k]=temp+'R';
        }
        
    }
}
int main()
{
    int t;
    cin >>t;
    for(int i=0;i<t;i++)
    {
        cin >>start>>finish;
        cout<<bfs()<<"\n";
    }
    return 0;
}