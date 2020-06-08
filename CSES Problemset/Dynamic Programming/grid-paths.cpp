#include<bits/stdc++.h>
#define N 1003
#define ll long long
using namespace std;

const int mod = int(1e9)+7;
int n;
char grid[N][N];

void read(){
    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> grid[i][j];
        }
    }
}

int solve(){
    vector<int> cnt(n+1,0);
    cnt[1] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(grid[i][j]=='*'){
                cnt[j] = 0;
            }
            else{
                cnt[j] = (cnt[j]+cnt[j-1])%mod;
            }
        }
    }
    return cnt[n];
}

int main(){
    
    read();
    cout << solve() << '\n';

    return 0;
}