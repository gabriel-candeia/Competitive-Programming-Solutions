#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    vector<ll> arr;

    cin >> n; arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    for(int i=1;i<n;i++)
        arr[i] += arr[i-1];

    map<ll,int> prefs;
    for(int i=0;i<n;i++){
        prefs[arr[i]]++;
    }

    int answ = 0;
    for(auto &p:prefs){
        answ = max(answ,p.second);
    }

    cout << n-answ <<"\n";

    return 0;
}