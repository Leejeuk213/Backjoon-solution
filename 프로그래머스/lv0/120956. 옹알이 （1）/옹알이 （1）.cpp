#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> test;
    test.push_back("aya");
    test.push_back("ye");
    test.push_back("woo");
    test.push_back("ma");
    for(int i=0;i<babbling.size();i++)
    {
        int cnt=0;
        int str_index=0;
        int check=0;
        while(1)
        {
            for(int j=0;j<4;j++)
            {
                string temp="";
                
                for(int k=str_index;k<str_index+test[j].size();k++)
                {
                    if(k>=babbling[i].size())
                    {
                        break;
                    }
                    temp=temp+babbling[i][k];
                }
                if(temp==test[j])
                {
                    cnt=cnt+test[j].size();
                    check=1;
                    str_index=str_index+test[j].size();
                    break;
                }
                check=0;
            }
            if(!check)
            {
                break;
            }
            if(cnt==babbling[i].size())
            {
                answer++;
                break;
            }
        }
    }
    return answer;
}