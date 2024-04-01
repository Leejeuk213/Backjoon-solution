#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int visited[8][8][8][8];
int room[8][8] ;
int n,m;

int result = 99999999;


void observe(int x, int y, int tv, int dir){

    if(tv == 1){
        if(dir == 1){

            for(int i = y+1; i<m; i++){
                if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
            }
        }

        else if(dir == 2){
            for(int i = x+1; i<n; i++){
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }
        }

        else if(dir == 3){
            for(int i = y-1; i >=0; i--){
                if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
            }
        }

        else if(dir == 4){
            for(int i = x-1; i>=0; i--){
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }
        }
    }

    else if(tv == 2){
        if(dir == 1){

            for(int i = y+1; i<m; i++){
                if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
            }

            for(int i = y-1; i >=0; i--){
                if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
            }
        }

        else if(dir == 2){
            for(int i = x+1; i<n; i++){
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }

            for(int i = x-1; i>=0; i--){
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }
        }
    }

    else if(tv == 3){
        if(dir == 1){

            for(int i = x-1; i>=0; i--){
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }

            for(int i = y+1; i<m; i++){
                if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
            }
        }

        else if(dir == 2){
            for(int i = x+1; i<n; i++){
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }

            for(int i = y+1; i<m; i++){
                if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
            }
        }

        else if(dir == 3){

            for(int i = y-1; i >=0; i--){
                if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
            }

            for(int i = x+1; i<n; i++){
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }
        }

        else if(dir == 4){
            for(int i = y-1; i >=0; i--){
                if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
            }
            for(int i = x-1; i>=0; i--){
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }
        }
    }

    else if(tv == 4){
        if(dir == 1){
            for(int i = y-1; i >=0; i--){
                if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
            }
            for(int i = x-1; i>=0; i--){
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }
            for(int i = y+1; i<m; i++){
                if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
            }
        }

        else if(dir == 2){
            
            for(int i = x-1; i>=0; i--){
                
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }
            for(int i = x+1; i<n; i++){
                
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }
            for(int i = y+1; i<m; i++){
                if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
            }
        }

        else if(dir == 3){
            for(int i = y-1; i >=0; i--){
                if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
            }
            for(int i = x+1; i<n; i++){
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }
            for(int i = y+1; i<m; i++){
                if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
            }
        }

        else if(dir == 4){
            for(int i = x-1; i>=0; i--){
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }
            for(int i = x+1; i<n; i++){
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }
            for(int i = y-1; i >=0; i--){
                if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
            }
            
        }
    }

    else if(tv == 5){
        for(int i = x-1; i>=0; i--){
                if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
            }
        for(int i = x+1; i<n; i++){
            if(room[i][y] == 6) break;
                
                else if(room[i][y] == 0){
                    room[i][y] = 9;
                    visited[x][y][i][y] = 1;
                }
                else continue;
        }
        for(int i = y-1; i >=0; i--){
            if(room[x][i] == 6) break;

                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
        }
        for(int i = y+1; i<m; i++){
            if(room[x][i] == 6) break;
                
                else if(room[x][i] == 0){
                    room[x][i] = 9;
                    visited[x][y][x][i] = 1;
                }
                else continue;
        }
    }

    return;
}

void de(int x, int y){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[x][y][i][j] == 1) {
                room[i][j] = 0;
                visited[x][y][i][j] = 0;
            }
        }
    }
    return ;
}

void solve(int x , int y){

    if(y >= m){
        y = 0;
        x ++;
    }
    for(int i = x; i<n;i++){
        for(int j=y; j<m;j++){

            if(room[i][j] == 1){
                for(int k = 1; k<=4; k++){
                    observe(i,j,1,k);
                    solve(i,j+1);
                    de(i,j);
                    //deobserve(i,j,1,k);
                }
            }

            else if(room[i][j] == 2){
                for(int k = 1; k<=2; k++){
                    observe(i,j,2,k);
                    solve(i,j+1);
                    de(i,j);
                    //deobserve(i,j,2,k);
                }
            }

            else if(room[i][j] == 3){
                for(int k = 1; k<=4; k++){
                    observe(i,j,3,k);
                    solve(i,j+1);
                    de(i,j);
                    //deobserve(i,j,3,k);
                }
            }

            else if(room[i][j] == 4){
                for(int k = 1; k<=4; k++){
                    observe(i,j,4,k);
                    solve(i,j+1);
                    de(i,j);
                    //deobserve(i,j,4,k);
                }
            }

            else if(room[i][j] == 5){
                int visited[8][8] ={0,};
                observe(i,j,5,0);
                solve(i,j+1);
                de(i,j);
                //deobserve(i,j,5,0);
            }
            if( j == m-1) y = 0;
        }
    }

    int cnt = 0;
    for(int i = 0; i<n;i++){
        for(int j=0; j<m;j++){
            if(room[i][j] != 0) cnt ++;
        }
    }

    if(result >= (n*m)-cnt){

        result = (n*m)-cnt;

        //cout << '\n';
        for(int i = 0; i<n;i++){
            for(int j=0; j<m;j++){

                //cout  << room[i][j] << ' ';
            }
      //  cout <<'\n';
        }
    }
    return ;
}

int main(){

    cin >> n >>m;

    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            cin >> room[i][j];
        }
    }



    solve(0,0);

    cout << result ;

    return 0;
}