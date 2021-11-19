#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll pontos[3][3] = {0, -1, 1,1,0,-1,-1,1,0};
const ll inf = 1e8;
ll dumb(array<ll,3> a, array<ll,3> b){
    bool poss = true;
    for(ll i=0;i<3;i++)
        if(a[i]!=0 || b[i]!=0)
            poss = false;
    if(poss) 
        return 0;
    ll answ = inf;
    for(ll i=0;i<3;i++){
        ll temp = -inf;
        for(ll j=0;j<3;j++){
            if(a[i] && b[j]){
                a[i]--, b[j]--;
                temp = max(temp,pontos[j][i] + dumb(array<ll,3>{a[0],a[1],a[2]},array<ll,3>{b[0],b[1],b[2]}));
                a[i]++, b[j]++;
            }
        }
        if(temp!=-inf)
            answ = min(answ,temp);
    }
    return answ;
}

int main(){
    ll t;

    cin >> t;
    while(t--){
        array<ll,3> a, b;
        for(auto &x:a) cin >> x;
        for(auto &x:b) cin >> x;

        ll score = 0, last;
        for(ll i=0;i<3;i++){
            score += min(b[(i+1)%3],a[i]);

            last  = min(b[(i+1)%3],a[i]);
            a[i] -= last;
            b[(i+1)%3] -= last;

            last = min(a[i],b[i]);
            a[i] -= last;
            b[i] -= last;

            last = min(a[i],b[(i-1+3)%3]);
            score -= last;
            a[i] -= last;
            b[(i-1+3)%3] -= last;
        }

        cout << score << "\n";
    }
    return 0;
}