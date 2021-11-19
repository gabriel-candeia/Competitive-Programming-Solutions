#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    map<ll,int> mp;

    ll n, x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        mp[x]++;
    }
    ll last = -1, answ = -1, acm = 0;
    for(auto &p:mp){
        p.second += acm;
        acm = p.second;
    }

    for(auto p:mp){
        if(p.second%3==0 && p.second>last){
            answ = p.first;
        }
    }
    
    cout << answ <<"\n";

    return 0;
}