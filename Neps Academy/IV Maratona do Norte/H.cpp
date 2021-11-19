#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll f(int x){
    ll pot = 1;
    for(;x;x/=2)
        pot = 2*pot;
    return pot;
}

int solve(int i, int j){
    if(i==0 && j==0) return 0;
    int n = f(max(i,j));
    
    if(j>=n/2 && j<n && i>=n/2 && i<n){
        return solve(i-n/2,j-n/2);
    }
    else if(j>=n/2 && i<n/2){
        return n/2+solve(i,j-n/2);
    }
    else{
        return n/2+solve(i-n/2,j);
    }
}

int main(){
    int x, y;
    cin >> x >> y;
    cout << solve(x-1,y-1) << "\n";
    return 0;
}