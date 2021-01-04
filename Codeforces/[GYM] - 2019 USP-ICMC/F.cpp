#include<bits/stdc++.h>
using namespace std;

int n;
double solve(int x){
    if(x==0)
        return 0;
    return (n-x+1)*(1.0)/x + (x-1)*solve(x-1)*(1.0)/x;
}

int main(){
    
    cin >> n;
    cout << fixed << setprecision(8) << solve(n) << '\n';
    return 0;
}