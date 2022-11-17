#include<iostream>
#include<string>
#include<deque>
using namespace std;
int t;
int main()
{
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int size;
        int errorcheck=0;
        int R_on=0;
        string func;
        deque<int> d;
        string handler;
        string nums;
        cin>>func;
        cin>>size;
        cin>>nums;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]=='[')
            {
                ;
            }
            else if(nums[j]==']')
            {
                if(!handler.empty())
                {
                    d.push_back(stoi(handler));
                    handler="";
                }
            }
            else if(nums[j]==',')
            {
                d.push_back(stoi(handler));
                handler="";
            }
            else
            {
                handler=handler+nums[j];
            }
        }
        for(int j=0;j<func.size();j++)
        {
            if(func[j]=='R')
            {
                if(R_on==1)
                {
                    R_on=0;
                }
                else
                {
                    R_on=1;
                }
            }
            else if(func[j]=='D')
            {
                if(d.empty()==1)
                {
                    cout<<"error"<<"\n";
                    errorcheck=1;
                    break;
                }
                else
                {
                    if(R_on==1)
                    {
                        d.pop_back();
                        size--;
                    }
                    else
                    {
                        d.pop_front();
                        size--;
                    }
                }
            }
        }
        if(errorcheck!=1)
        {
            cout<<"[";
        }
        if(R_on==1)
        {
            while(!d.empty())
            {
                cout<<d.back();
                d.pop_back();
                if(d.empty()!=1)
                {
                    cout<<",";
                }
            }
            if(errorcheck!=1)
            {
                cout<<"]"<<"\n";
            }
        }
        else
        {
            while(!d.empty())
            {
                cout<<d.front();
                d.pop_front();
                if(d.empty()!=1)
                {
                    cout<<",";
                }
            }
            if(errorcheck!=1)
            {
                cout<<"]"<<"\n";
            }
        }
    }
    return 0;
}