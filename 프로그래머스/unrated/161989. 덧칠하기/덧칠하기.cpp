#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    queue<int> q;
    for(int i=0; i<section.size();i++)q.push(section[i]);
    while(q.size()!=0)
    {
        int first = q.front();
        q.pop();
        answer++;
        for(int i = first; i<first +m;i++)
        {
            if(q.size()!= 0)
            {
                if(q.front()== i)
                {
                    q.pop();
                } 
            }
        }
    }
    return answer;
}