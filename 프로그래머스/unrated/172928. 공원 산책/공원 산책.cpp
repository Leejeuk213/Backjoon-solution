#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x = park.size();
    int y = park[0].size();
    int result_x = 0;
    int result_y = 0;

    for(int i=0; i<x;i++)
    {
        for(int j=0;j<y;j++){
            if(park[i][j]=='S'){
                result_x = i;
                result_y = j;
                i = x;
                break;
            }
        }
    }
    for(int i=0; i<routes.size();i++)
    {
        int handle_x = result_x;
        int handle_y = result_y;
        char op = routes[i][0];
        int n = routes[i][2] -'0';
        if(op == 'E')
        {
            int ok=1;
            int moved_y = handle_y + n;
            if(moved_y>=y) continue;
            
            for(int j=handle_y; j<=moved_y;j++){
                if(park[handle_x][j]=='X'){
                    ok =0;
                    break;
                }
            }
            if(ok) result_y = moved_y;
        }

        else if(op == 'W')
        {
            int ok=1;
            int moved_y = handle_y - n;
            if(moved_y<0) continue;
            
            for(int j=handle_y; j>=moved_y;j--){
                if(park[handle_x][j]=='X'){
                    ok =0;
                    break;
                }
            }
            if(ok) result_y = moved_y;
        }

        else if(op == 'S')
        {
            int ok=1;
            int moved_x = handle_x + n;
            if(moved_x>=x) continue;
            
            for(int j=handle_x; j<=moved_x;j++){
                if(park[j][handle_y]=='X'){
                    ok =0;
                    break;
                }
            }
            if(ok) result_x = moved_x;
        }

        else if(op == 'N')
        {
            int ok=1;
            int moved_x = handle_x - n;
            if(moved_x<0) continue;
            
            for(int j=handle_x; j>=moved_x; j--){
                if(park[j][handle_y]=='X'){
                    ok =0;
                    break;
                }
            }
            if(ok) result_x = moved_x;
        }
    }

    answer.push_back(result_x);
    answer.push_back(result_y);
    return answer;
}
