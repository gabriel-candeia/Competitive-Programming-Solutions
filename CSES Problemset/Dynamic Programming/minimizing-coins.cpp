#include<bits/stdc++.h>
using namespace std;

int n, x;
vector<int> c;
const int INF = 1e9;

void read(){
    cin >> n >> x;
    c.assign(n+1,0);
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
}

int solve(){
    vector<int> cnt(x+1,INF);
    cnt[0] = 0;
    
    for(int i=1;i<=x;i++){
        for(auto val:c){
            if(val<=i){
                cnt[i] = min(cnt[i],cnt[i-val]+1);
            }
        }
    }

    return (cnt[x]!=INF) ? cnt[x] : -1;
}


int main(){

    read();
    cout << solve() << '\n';

    return 0;
}