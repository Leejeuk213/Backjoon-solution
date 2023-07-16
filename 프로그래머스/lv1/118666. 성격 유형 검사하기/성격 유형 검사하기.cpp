#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map <char,int> m;

    m.insert({'R',0});
    m.insert({'T',0});

    m.insert({'C',0});
    m.insert({'F',0});

    m.insert({'J',0});
    m.insert({'M',0});

    m.insert({'A',0});
    m.insert({'N',0});

    for(int i=0; i<survey.size();i++)
    {
        if(choices[i] == 4) continue;

        if(choices[i]<4) m[survey[i][0]] += 4-choices[i];

        if(choices[i]>4) m[survey[i][1]] += choices[i]-4;
    }

    if(m['R'] >= m['T']) answer +='R';
    else answer += 'T';

    if(m['C'] >= m['F']) answer +='C';
    else answer += 'F';

    if(m['J'] >= m['M']) answer +='J';
    else answer += 'M';

    if(m['A'] >= m['N']) answer +='A';
    else answer += 'N';
    
    return answer;
}