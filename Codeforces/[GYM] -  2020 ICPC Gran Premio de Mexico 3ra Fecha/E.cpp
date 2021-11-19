#include<bits/stdc++.h>
#define maxn int(1e6+5)
#define ll long long
using namespace std;

int main(){
    int n, b;
    vector<ll> answ, arr;
    vector<vector<int>> adj(maxn,vector<int>());

    cin >> n >> b;
    arr.assign(n,0);
    answ.assign(n,0);
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
        adj[arr[i]].push_back(i);
    }
    
    for(int i=1;i<maxn;i++){
        for(auto p:adj[i]){
            ll mx = 0;
            if(arr[(p+1)%n] < arr[p]){
                mx = max(answ[(p+1)%n],mx);
            }
            if(arr[(p-1+n)%n] < arr[p]){
                mx = max(answ[(p-1+n)%n],mx);
            }
            answ[p] = mx+b;
        }
    }


    for(int i=0;i<(int)answ.size()-1;i++)
        cout << answ[i] << " ";
    cout<< answ.back() << "\n";

    return 0;
}