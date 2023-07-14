#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    for(int i=0; i<t.size()-p.size()+1; i++)
    {
        int check = 1;
        for(int j=0; j<p.size();j++)
        {
            if(t[i+j]>p[j]) {
                check =0;
                break;
            }

            else if(t[i+j]<p[j]){
                answer++;
                check =0;
                break;
            }
            else continue;
        }
        if(check) answer++;
    }
    return answer;
}