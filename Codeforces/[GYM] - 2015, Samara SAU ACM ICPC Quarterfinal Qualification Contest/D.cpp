#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    map<ll,ll> pref;
    ll n, x, sum=0;
    pair<ll,ll> answ; answ.first = 0;
    answ.second = 1e7;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        sum += x;
        
        if(pref[sum]!=0 && answ.second>i+1-pref[sum]){
            answ.first = pref[sum]+1;  
            answ.second = i+1-pref[sum];
        }
        else if(sum==0 && answ.second>i){
            answ.first = 1;
            answ.second = i+1;  
        }
        
        pref[sum] = i+1;
    }

    if(answ.first==0)
        cout << -1 <<'\n';
    else
        cout << answ.first << " " << answ.second <<'\n';

    return 0;
}