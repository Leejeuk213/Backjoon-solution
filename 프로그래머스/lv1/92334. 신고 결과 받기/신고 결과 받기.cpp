#include <string>
#include <vector>
#include<algorithm>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> m;
    map<string, int> result;
    
    //신고횟수 맵 초기화
    for(int i=0; i<id_list.size();i++)
    {
        m.insert({id_list[i],0});
        result.insert({id_list[i],0});
    }

    sort(report.begin(),report.end());

    //신고횟수 누적 중복 제외
    for(int i=0; i<report.size();i++)
    {
        if(i!=0){
            if(report[i-1]==report[i]) continue;
        }

        string name ="";
        int check =0;

        for(int j=0;j<report[i].size();j++)
        {   
            if(check) name +=report[i][j];
            if(report[i][j]==' ') check = 1;
        }

        m[name] ++;
    }

    for(int i=0; i<report.size();i++)
    {
        if(i!=0){
            if(report[i-1]==report[i]) continue;
        }

        string first_name ="";
        string second_name ="";
        int check =1;

        for(int j=0;j<report[i].size();j++)
        {   
            if(report[i][j]==' '){
                check = 0;
                continue;
            }

            if(check) first_name +=report[i][j];

            else second_name += report[i][j];

        }

        if(m[second_name] >=k) result[first_name]++;
    }
    // 결과 입력
    for(int i=0; i<id_list.size();i++)
    {
        answer.push_back(result[id_list[i]]);
    }

    return answer;
}