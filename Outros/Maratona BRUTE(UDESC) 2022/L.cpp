#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

ll n, m, c, d;
vector<ll> rngs;

ll teto(ll a, ll b){
    return (a/b + ((a%b)!=0));
}

bool isok(ll med){
    ll atual = 0, qtd = 1;
    for(int i=0;i<rngs.size();i++){
        if(teto(atual+rngs[i],med)<=d){
            atual+=rngs[i];
        }
        else if(teto(rngs[i],med)<=d){
            qtd++;
            atual = rngs[i];
        }
        else{
            return false;
        }
    }
    return qtd<=c;
}

int main(){
    fastio();
    cin >> n >> m >> c >> d;

    for(int i=0;i<m;i++){
        ll a, b;
        cin >> a >> b;
        rngs.push_back(b-a);
    }

    ll l = 1, r = n, med = -1, answ;
    while(l<=r){
        med = l + (r-l)/2;
        if(isok(med)){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }

    cout << answ <<"\n";

    return 0;
}