#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char,int> m;

    int year = (today[0]-'0')*1000+(today[1]-'0')*100+(today[2]-'0')*10+(today[3]-'0');
    int month = (today[5]-'0')*10+(today[6]-'0');
    int day = (today[8]-'0')*10+(today[9]-'0');
    
    for(int i=0; i<terms.size();i++)
    {
        if(terms[i].size() == 3) m.insert({terms[i][0],terms[i][2]-'0'});
        
        else if(terms[i].size() == 4) m.insert({terms[i][0],(terms[i][2]-'0')*10 + (terms[i][3]-'0')});

        else m.insert({terms[i][0],100});
    }

    for(int i=0; i<privacies.size();i++)
    {
        char term = privacies[i][11];
        int year2 = (privacies[i][0]-'0')*1000+(privacies[i][1]-'0')*100+(privacies[i][2]-'0')*10+(privacies[i][3]-'0');
        int month2 = (privacies[i][5]-'0')*10+(privacies[i][6]-'0');
        int day2 = (privacies[i][8]-'0')*10+(privacies[i][9]-'0');

        int result_year = year2;
        int result_month = month2;
        int result_day = day2;

        if(day2 == 1)
        {
            result_day = 28;
            if(result_month == 1)
            {
                result_month = 12;
                result_year--;
            }
            else result_month--;
        }
        else result_day--;

        result_month += m[term];

        while(result_month > 12)
        {
            result_month -= 12;
            result_year++;
        }
        
        if(year > result_year)
        {
            answer.push_back(i+1);
            continue;
        }

        else if(year < result_year) continue;

        else
        {
            if(month > result_month)
            {
                answer.push_back(i+1);
                continue;
            }

            else if(month < result_month) continue;

            else
            {
                if(day > result_day)
                {
                    answer.push_back(i+1);
                    continue;
                }

                else if(day < result_day) continue;
            }
        }
    }
    return answer;
}