#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    for(int i=0; i< ingredient.size();i++)
    {
        if( i>= 3 && ingredient[i] == 1)
        {   
            int oidx =0;
            int tidx =0;
            int thidx =0;
            int special_check = 0;

            int check = 3;
            int j = i-1;
            while(j >=0 && check>0)
            {   
                if(ingredient[j] == 0){j--; continue;}
                if(ingredient[j] == check)
                {
                    if(check == 3) thidx = j;
                    if(check == 2) tidx = j;
                    if(check == 1){
                        oidx = j;
                        if(oidx == 0) special_check = 1;
                    }
                    check--;
                    j--;
                }
                else break;
            }
            
            if(oidx == 0)
            {
                if(special_check && tidx && thidx)
                {
                    answer++;
                    ingredient[i] = 0;
                    ingredient[oidx]=0;       
                    ingredient[tidx]=0;       
                    ingredient[thidx]=0;       
                }
            }
            else{
                if(oidx && tidx && thidx)
                {
                    answer++;
                    ingredient[i] = 0;
                    ingredient[oidx]=0;       
                    ingredient[tidx]=0;       
                    ingredient[thidx]=0;       
                }
            }
        }
    }
    return answer;
}