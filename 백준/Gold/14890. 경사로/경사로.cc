#include<iostream>
#include<cstring>

using namespace std;

int map[101][101];
int n,l;

int result = 0;

void solve(){

    int visited[101][101] = {0,};
    for(int i=0; i<n;i++){
        int is_ok = 1;
        for(int j=0; j<n-1;j++){

            if(map[i][j] == map[i][j+1]) continue;

            if (map[i][j] == map[i][j+1]+1)  {
                for(int k = j+1; k<=j+l;k++){
                    if(k >= n) {
                        is_ok = 0;
                        break;
                    }
                    if(visited[i][k] !=0) is_ok = 0;
                    if(map[i][j+1]!=map[i][k]) is_ok =0;

                    if(!is_ok) break;
                }
                if(is_ok){
                    for(int k = j+1; k<=j+l;k++) visited[i][k] = 1;
                }
            }
            else if(map[i][j] == map[i][j+1]-1) {
                for(int k = j; k>j-l;k--){
                    if(k < 0) {
                        is_ok = 0;
                        break;
                    }
                    if(visited[i][k] !=0) is_ok = 0;
                    if(map[i][j]!=map[i][k]) is_ok =0;

                    if(!is_ok) break;
                }
                if(is_ok){
                    for(int k = j; k>j-l;k--) visited[i][k] = 1;
                }
            }
            else {
                is_ok = 0;
                break;
            }
        }

        if(is_ok){
            //cout << i <<'\n';
            result++;
        }
    }
    
    int visited2[101][101] = {0,};

    for(int j=0; j<n;j++){
        int is_ok = 1;
        for(int i=0; i<n-1;i++){

            if(map[i][j] == map[i+1][j]) continue;

            if(map[i][j] == map[i+1][j]+1) {
                for(int k = i+1; k<=i+l;k++){
                    if(k >= n) {
                        is_ok = 0;
                        break;
                    }
                    if(visited2[k][j] !=0) is_ok = 0;
                    if(map[i+1][j]!=map[k][j]) is_ok =0;

                    if(!is_ok) break;
                }
                if(is_ok){
                    for(int k = i+1; k<=i+l;k++) visited2[k][j] = 1;
                }
            }
            else if(map[i][j] == map[i+1][j]-1){
                for(int k = i; k>i-l;k--){
                    if(k < 0) {
                        is_ok = 0;
                        break;
                    }
                    if(visited2[k][j] !=0) is_ok = 0;
                    if(map[i][j]!=map[k][j]) is_ok =0;

                    if(!is_ok) break;
                }
                if(is_ok){
                    for(int k = i; k>i-l;k--) visited2[k][j] = 1;
                }
            }

            else {
                is_ok = 0;
                break;
            }
        }
        if(is_ok){
            //cout << j <<'\n';
            result++;
        }
    }
    return ;
}




int main(){


    cin >> n >> l;

    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++) cin >> map[i][j];
    }

    solve();
    cout << result ;
    return 0;
}