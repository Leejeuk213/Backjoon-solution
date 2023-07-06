#include <string>
#include <vector>
#include<map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    map<char,int> m;
    vector<int> answer;

    for(int i = 0; i<keymap.size();i++)
    {
        for(int j=0;j< keymap[i].size();j++)
        {
            if(m.count(keymap[i][j]) == 0)
            {
                m.insert({keymap[i][j],j+1});
            }
            else
            {
                if(m[keymap[i][j]]>j+1)
                {
                    m[keymap[i][j]] = j+1;
                }
            }
        }
    }
    for(int i = 0; i<targets.size();i++)
    {
        int sum = 0;
        int check = 1;
        for(int j=0; j<targets[i].size();j++)
        {
            if(m.count(targets[i][j]) == 0)
            {
                check = 0;
                answer.push_back(-1);
                break ;
            }
            sum +=m[targets[i][j]] ;
        }
        if(check){
            answer.push_back(sum);
        }
    }

    return answer;
}