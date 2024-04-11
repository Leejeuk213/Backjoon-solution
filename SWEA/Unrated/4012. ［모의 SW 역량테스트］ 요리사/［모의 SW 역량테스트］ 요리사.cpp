#include<iostream>

using namespace std;

int board[16][16];
int visited[16];
int t ;
int n;
long long result = 987654321;
void sum(){
    long long re = 0;
    long long zero_cnt = 0;
    long long one_cnt = 0;
    for(int i= 0 ; i<n; i++){
        for(int j = 0; j<n; j++){
            if(visited[i] == visited[j] && visited[i] == 0){
                zero_cnt += board[i][j];
            }
            else if(visited[i] == visited[j] && visited[i] == 1){
                one_cnt += board[i][j];
            }
        }
    }
    if(one_cnt >= zero_cnt) re = one_cnt -zero_cnt;
    else re = zero_cnt - one_cnt;
    if(re<result) result = re;

    return ;
}
void solve(int depth, int index){

    if(depth == n/2) {
        sum();
        return ;
    }
    for(int i=index;i<n;i++){

        if(visited[i] ==0){
            visited[i] = 1;
            solve(depth+1,i);
            visited[i] = 0;
        }
    }
    return;
}

int main(){

    cin >> t;
    for(int i=1; i<=t; i++){

        cin >> n;
        result = 987654321;
        for(int j=0; j<n;j++){

            for(int k= 0; k<n;k++){
                cin >> board[j][k];
            }
        }
        solve(0,0);
        cout << '#' <<i <<' ' << result << '\n';
    }

    return 0;
}