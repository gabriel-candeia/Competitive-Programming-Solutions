#include<bits/stdc++.h>
#define N 256
using namespace std;

int main(){
    int n, k, a;
    vector<int> answ, rep(N,0), visited(N,0);

    for(int i=0;i<N;i++){
        rep[i] = i;
    }

    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a;
        if(!visited[a]){
            int j = max(0,a-(k-1));
            for(;j<=a;j++){
                if(a-rep[j]<=k-1){
                    rep[a] = rep[j];
                    break;
                }
            }
            for(;j<=a;j++){
                rep[j] = rep[a];
                visited[j] = true;
            }
        }
        answ.push_back(rep[a]);
    }

    for(auto x : answ){
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}