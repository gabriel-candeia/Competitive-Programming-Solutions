#include<bits/stdc++.h>
using namespace std;

int n;
const int INF = int(1e9);

void read(){
    cin >> n;
}

int solve(int n){
    vector<int> steps(n+1,INF); steps[0] = 0;
    int x;

    for(int i=1;i<=n;i++){
        x = i;
        while(x){
            steps[i] = min(steps[i-x%10]+1,steps[i]);
            x /= 10;
        }
    }

    return steps[n];
}

int main(){
    
    read();
    cout << solve(n) << '\n';

    return 0;
}