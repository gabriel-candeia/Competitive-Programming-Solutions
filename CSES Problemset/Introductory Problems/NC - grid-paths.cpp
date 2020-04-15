#include<bits/stdc++.h>
#define N 10
using namespace std;

int memo[48+5][N][N];

int alg(string s, int ptr, int i, int j){
    if(i<=0 || j<=0 || i>7 || j>7 || (48-ptr < (7-i + j-1))){
        return 0;
    }
    else if(ptr>=48){
        return (i==7 && j==1);
    }

    int answ=0;
    if(s[ptr]=='D' || s[ptr]=='?'){
        answ+=alg(s,ptr+1,i+1,j);
    }
    if(s[ptr]=='U' || s[ptr]=='?'){
        answ+=alg(s,ptr+1,i-1,j);
    }
    if(s[ptr]=='R' || s[ptr]=='?'){
        answ+=alg(s,ptr+1,i,j+1);
    }
    if(s[ptr]=='L' || s[ptr]=='?'){
        answ+=alg(s,ptr+1,i,j-1);
    }
    return answ;
}

int main(){
    string s;

    cin >> s;
    for(int i=0;i<=51;i++){
        for(int j=0;j<=N;j++){
            for(int l=0;l<=N;l++){
                memo[i][j][l] = -1;
            }
        }
    }
    cout << alg(s,0,1,1) <<'\n';
    
    return 0;
}