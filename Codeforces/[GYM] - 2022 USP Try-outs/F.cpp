#include<bits/stdc++.h>
using namespace std;

int solve(int n, bool turn){
    if(n==1){
        return 1;
    }
    if(turn == 0){
        return 2*solve(n-n/2,!turn)-1;
    }
    if(n%2){
        return 2*solve(n-n/2,!turn)-1;
    }
    return 2*solve(n-n/2,!turn);
}

int main(){ 
    int n;

    cin >> n;
    cout << solve(n,0) <<"\n";

    return 0;
}