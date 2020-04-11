#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, b;
    map<int,pair<ll,ll>> mp;
    pair<int,ll> temp; 

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> b;
        if(mp.count(b-i)){
            temp = mp[b-i];
            mp[b-i] = make_pair(temp.first+1,temp.second+i);
        }
        else{
            mp[b-i] = make_pair(1,i);
        }
    }

    ll answ = 0;
    for(auto p:mp){
        answ = max(answ,p.first*p.second.first+p.second.second);
    }
    cout << answ << '\n';
    return 0;
}