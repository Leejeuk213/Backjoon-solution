#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    map <char,int> m;

    for(int i=0; i<skip.size();i++)
    {
        m.insert({skip[i],1});
    }
    
    for(int i=0; i<s.size();i++)
    {
        char word =s[i];
        for(int j=0; j<index; j++)
        {
            if(m.count(word)==1)
            {
                while(m.count(word)==1)
                {
                    if(word=='z') word = 'a';

                    else word ++;
                }
            }
            if(word=='z') word = 'a';

            else word ++;

            if(m.count(word)==1)
            {
                while(m.count(word)==1)
                {
                    if(word=='z') word = 'a';

                    else word ++;
                }
            }
        }
        answer = answer+word;
    }
    return answer;
}