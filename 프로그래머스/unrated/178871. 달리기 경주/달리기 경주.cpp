#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

static bool comp(pair<string,int>& a, pair<string,int> & b){
    return a.second <b.second;
}
vector<string> solution(vector<string> players, vector<string> callings) {

    vector<string> result;
    map <string, int> m;
    map <int, string> m2;


    for (int i= 0; i<players.size();i++){
        m.insert({players[i],i});
        m2.insert({i,players[i]});
    }

    for(int i =0; i<callings.size();i++){
        m[callings[i]]--; // 내 등수 올리고
        string temp = m2[m[callings[i]]]; // 내가 제친 애를 기록
        m2[m[callings[i]]] = callings[i]; // 올려진 내 등수에 내 이름 기록
        m2[m[callings[i]]+1] = temp ; // 제친 애를 이전 내 등수에 기록
        m[temp] ++; // 제쳐진 애 등수 내리기
    }

    vector<pair<string,int>> v(m.begin(),m.end());
    
    sort (v.begin(),v.end(),comp);

    for (int i=0; i< v.size();i++)
    {
        result.push_back(v[i].first);
    }
    return result;
}