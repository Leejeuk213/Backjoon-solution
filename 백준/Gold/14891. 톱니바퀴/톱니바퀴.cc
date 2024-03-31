#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int chain[4][8] ;
int now_chain[4][8];
int visited[4];
vector<pair<int,int>> rotate ;

int n;
int result = 0;

void rot(int index, int dir){

    int left;
    int right;
    for(int i = 0 ; i< 8; i++){

        if(now_chain[index][i] == 2) right = chain[index][i];
        if(now_chain[index][i] == 6) left = chain[index][i];
    }
    //cout << index << ' ' << dir << '\n';
    if(dir == -1){

        for(int i = 0; i< 8; i++){

            now_chain[index][i]--;
            if(now_chain[index][i]<0) now_chain[index][i] = 7;
        }

    }

    else{
        for(int i = 0; i< 8; i++){

            now_chain[index][i]++;
            if(now_chain[index][i]>7) now_chain[index][i] = 0;
        }

    }

    visited[index] = 1;

    if(index == 0){
        int a;
        for(int i = 0 ; i< 8; i++){
        if(now_chain[1][i] == 6) a = chain[1][i];
        }
        if(right != a && visited[1] == 0) rot(1,dir*-1);
    }

    else if (index == 3){
        int b;
        for(int i = 0 ; i< 8; i++){
        if(now_chain[2][i] == 2) b = chain[2][i];
        }
        if(left != b && visited[2] == 0) rot(2,dir*-1);
    }

    else if(index == 1){
        int a;
        int b;
        for(int i = 0 ; i< 8; i++){
        if(now_chain[2][i] == 6) a = chain[2][i];
        if(now_chain[0][i] == 2) b = chain[0][i];
        }
        if(left != b && visited[0] ==0) rot(0,dir * -1);
        if(right != a && visited[2] ==0) rot(2,dir*-1); 
    }

    else if(index == 2){
        int a;
        int b;
        for(int i = 0 ; i< 8; i++){
        if(now_chain[3][i] == 6) a = chain[3][i];
        if(now_chain[1][i] == 2) b = chain[1][i];
        }
        if(left != b && visited[1] == 0) rot(1,dir * -1);
        if(right != a && visited[3] == 0) rot(3,dir*-1); 
    }
    return ;
}

void solve(){


    int score[4]={1,2,4,8};
    for(int i=0;i<n;i++){

        int chain_index = rotate[i].first -1;
        int dir = rotate[i].second;

        memset(visited,0,sizeof(visited));
        rot(chain_index, dir);
    }

    for(int i=0;i<4;i++){
        for(int j=0; j<8;j++){

            if(now_chain[i][j]==0 && chain[i][j] == 1){
                result += score[i];
            }
        }
    }

    return ;
}

int main(){

    for(int i=0;i<4;i++){

        int raw_chain;
        cin >> raw_chain;
        for(int j=7;j>=0;j--){
            
            chain[i][j] = raw_chain % 10;
            raw_chain /=10;
            now_chain[i][j] = j;
        }
    }

    


    cin >>n;
    for(int i=0; i<n;i++) {
        int c_n ;
        int rn;
        cin >> c_n >> rn;
        rotate.push_back(make_pair(c_n,rn));
    }

    solve();

    cout << result;

    return 0; 
}