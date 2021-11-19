#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll x, ll y){
    if(y==0)
        return 2*x+y;
    if(x==1)
        return y+1;
    return x+1+solve(x-1,y);
}

int main(){
    int n, x=0;
    
    cin >> n;
    for(int i=0;i<n;i++){
        int y;
        cin >> y;
        x+=y;
    }

    cout << solve(x,n-x) << '\n';

    return 0;
}