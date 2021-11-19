#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main(){
    fastio();

    int n, k;
    vector<vector<int>> answ;
    
    cin >> n >> k;
    answ.assign(k,vector<int>());
    for(int i=1;i<=n;i++){
        answ[i%k].push_back(i);
    }

    for(auto arr:answ){
        for(auto x:arr){
            cout << x << " ";
        }
    }
    cout << '\n';

    return 0;
}