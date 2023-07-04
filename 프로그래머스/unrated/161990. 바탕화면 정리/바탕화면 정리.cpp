#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) 
{
    vector<int> answer;
    int first_x = 0;
    int first_y = 51;
    int last_x = 0;
    int last_y = 0;
    int is_init = 0;
    for(int i = 0; i<wallpaper.size();i++)
    {
        int check =1;
        for(int j=0; j<wallpaper[i].size();j++)
        {
            if(wallpaper[i][j] == '#')
            {
                if(is_init == 0)
                {
                    is_init = 1;
                    first_x = i;
                }

                if(last_x< i) last_x = i;

                if(j < first_y) first_y = j;

                if(last_y < j) last_y = j;
            }
        }
        
    }
    answer.push_back(first_x);
    answer.push_back(first_y);
    answer.push_back(last_x+1);
    answer.push_back(last_y+1);
    return answer;
}