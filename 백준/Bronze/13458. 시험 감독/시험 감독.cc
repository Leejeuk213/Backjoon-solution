#include<iostream> 

using namespace std;

int n_room = 0;
int n_candidate[1000001]={0,};
int b,c = 0;
long long result = 0;

int main()
{
    cin >> n_room;

    for(int i=0;i<n_room;i++)
    {
        cin >> n_candidate[i];
    }
    cin >> b >> c;


    for(int i=0; i< n_room; i++){
        n_candidate[i]-= b;
        result++;
        
        if(n_candidate[i] > 0){
            
            if(n_candidate[i] < c)
            {
                n_candidate[i] -= c;
                result++;
            }
            else{
                int d = n_candidate[i] / c;
                n_candidate[i] -= d*c;
                result += d;
                if(n_candidate[i] % c != 0) result++;
            }
        }
        
    }

    cout << result;
    return 0;
}