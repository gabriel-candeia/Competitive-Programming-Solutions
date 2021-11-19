#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, k;   
    vector<ll> arr, soma;
    cin >> n >> k;

    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    ll window = 0;
    for(int i=0;i<k;i++)
        window+=arr[i];
    
    soma.push_back(window);
    for(int i=k;i<n;i++){
        window+=(arr[i]-arr[i-k]);
        soma.push_back(window);
    }

    ll answ = -soma[0]-soma[k], mx = -soma[0];
    for(int i=k;i<soma.size();i++){
        mx = max(mx,-soma[i-k]);
        answ = max(answ,-soma[i]+mx);
    }

    cout << answ <<"\n";


    return 0;
}