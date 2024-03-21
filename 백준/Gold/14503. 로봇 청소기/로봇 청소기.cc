#include<iostream>

using namespace std;

int n,m;
int result = 0;
int x,y,v;
int room[51][51];

int check(){

    if (x == 0 && y == 0){
        if(room[x+1][y] == 0 || room[x][y+1] == 0) return 3;
        return 2;
    }

    else if(x == 0){
        if(room[x+1][y] == 0 || room[x][y+1] == 0 || room[x][y-1] == 0) return 3;
        return 2;
    }

    else if (y == 0){
        if(room[x+1][y] == 0 || room[x][y+1] == 0 || room[x-1][y] == 0) return 3;
        return 2;
    }
    else if(x == n-1 && y == m-1){
        if(room[x-1][y] == 0 || room[x][y-1] == 0 ) return 3;
        return 2;
    }
    else if (x == n-1){
        if(room[x][y-1] == 0 || room[x][y+1] == 0 || room[x-1][y] == 0) return 3;
        return 2;
    }
    else if (y == m-1){
        if(room[x+1][y] == 0 || room[x][y-1] == 0 || room[x-1][y] == 0) return 3;
        return 2;
    }
    else{
        if(room[x+1][y] == 0 || room[x][y-1] == 0 || room[x-1][y] == 0 || room[x][y+1] == 0) return 3;
        return 2;
    }
}

int move_backward(){
    if(v == 0){
        if(x != n-1){
            if(room[x+1][y] != 1){
                x++;
                return 1;
            }
        }
    }
    else if(v == 1){
        if(y != 0){
            if(room[x][y-1] != 1){
                y--;
                return 1;
            }
        }
    }

    else if(v == 2){
        if(x != 0){
            if(room[x-1][y] != 1){
                x--;
                return 1;
            }
        }
    }

    else if(v == 3){
        if(y != m-1){
            if(room[x][y+1] != 1){
                y++;
                return 1;
            }
        }
    }
    return 0;
}

void move_forward(){
    while(1){
        v--;
        if(v < 0) v = 3;

        if(v == 0){
            if(x != 0){
                if(room[x-1][y] == 0){
                    x--;
                    break;
                }
            }
        }
        else if(v == 1){
            if(y != m-1){
                if(room[x][y+1] == 0){
                    y++;
                    break;
                }
            }
        }

        else if(v == 2){
            if(x != n-1){
                if(room[x+1][y] == 0){
                    x++;
                    break;
                }
            }
        }

        else if(v == 3){
            if(y != 0){
                if(room[x][y-1] == 0){
                    y--;
                    break;
                }
            }
        }
    }
    return;
}
void solve(){

    while(1){

        if(room[x][y]==0){ 
            result++;
            room[x][y] = 2;
            continue;
        }

        int check_res = check(); 
        // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        if(check_res == 2){
            if(move_backward()) continue;
            break;
        }
        // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
        else if(check_res == 3){
            move_forward();
        }

    }

    cout << result;
    return ;
}


int main()
{

    cin >> n >> m;
    cin >> x >> y >> v ;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m;j++)
        {
            cin >> room[i][j];
        }
    }

    solve();
    return 0;
}