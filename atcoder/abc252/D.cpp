#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(auto &x:arr)
        cin >> x;

    ll answ = 0;
    map<ll,ll> freq;

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    ll acm = 0;
    for(auto &p:freq){
        answ += acm*(n-p.second-acm)*p.second;
        acm += p.second;
    }

    cout << answ<<"\n";


    return 0;
}