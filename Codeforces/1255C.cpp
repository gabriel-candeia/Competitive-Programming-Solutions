#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, c;
    vector<vector<int>> adj;
    vector<int> dg;

    cin >> n;
    adj.assign(n+1,vector<int>());
    dg.assign(n+1,0);

    for(int i=0;i<n-2;i++){
        cin >> a >> b >> c;
        dg[a]++; dg[b]++; dg[c]++;

        adj[a].push_back(b); adj[a].push_back(c);
        adj[b].push_back(a); adj[b].push_back(c);
        adj[c].push_back(a); adj[c].push_back(b);
    }

    int start = 0;
    for(int i=1;i<n;i++){
        if(dg[i]==1){
            start = i;
            break;
        }
    }

    for(auto i:dg){
        cout << i << ' ';
    }
    cout << '\n';

    vector<int> answ;
    int next;
    while(answ.size()<n){
        answ.push_back(start);
        for(auto i : adj[start]){
            dg[i]--;
            if(dg[i]==1){
                next = i;
            }
        }
        start = next;
    }
    
    for(auto i:answ){
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}