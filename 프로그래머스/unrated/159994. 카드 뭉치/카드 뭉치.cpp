#include <string>
#include <vector>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";

    int p1 = 0;
    int p2 = 0;

    for(int i=0; i<goal.size();i++)
    {
        if(goal[i]!= cards1[p1] && goal[i] != cards2[p2])
        {
            answer = "No";
            break;
        }
        else if(goal[i] == cards1[p1]) p1++;

        else if(goal[i] == cards2[p2]) p2++;
    }
    return answer;
}