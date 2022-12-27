#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s,boom,temp=""; // 1
    cin >> s;
    cin >> boom;
    for(int i=0; i<s.size(); i++){// 2
        temp+=s[i];
        if(temp.back()==boom.back()){ // 3
            bool ch = true;
            if(temp.size()<boom.size()) continue; // 4
            for(int j=0; j<boom.size(); j++){ // 5
                if(temp[temp.size()-boom.size()+j]!=boom[j]){
                    ch = false;
                    break;
                }
            }
            if(ch){ // 6
                for(int j=0; j<boom.size(); j++) temp.pop_back();
            }
        }
    }
    if(temp.empty()) cout << "FRULA" << "\n"; // 7
    else cout << temp << "\n";
    return 0;
}