#include<bits/stdc++.h>
#define ll long long
using namespace std;

int teste(const string& s, char a){
    int best = 0, curr = 0;
    for(auto c:s){
        if(c==a){
            curr++;
        }
        else{
            curr=0;
        }
        best = max(best,curr);
    }
    return best;
}

int main(){
    int t;
    cin >> t;
    while(t--){
            int n;
        string s;
            cin >> n;
        cin >> s;
        vector<ll> cnt(2,0);
        for(auto c:s)
            cnt[c-'0']++;
        ll x = teste(s,'0'), y = teste(s,'1');

        cout << max({x*x,y*y,cnt[0]*cnt[1]}) <<"\n";
    }

    return 0;
}