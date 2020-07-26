#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll max(ll a, ll b){
    return (a<b) ? b : a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    int n, m, a;
    vector<ll> needed(33,0), available(33,0);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a;
        int ptr = 0;
        while(a!=0){
            needed[ptr++]+=a%2;
            a/=2;
        }
    }

    for(int i=0;i<m;i++){
        cin >> a;
        available[a]++;
    }
    ll pot = 1;
    for(int i=0;i<33;i++){
        needed[i] *= pot;
        pot*=2ll;
    }

    ll answ=0, rem, qtd;
    pot = 1;
    for(int i=0;i<33;i++){
        qtd = 1ll*available[i]*pot;
        for(int j=i;j<33;j++){
            rem = 0;
            if(qtd<needed[j]){
                rem = qtd;
            }
            else{
                rem = (needed[j]-(needed[j]%pot));
            }
            qtd -= rem;
            needed[j] -= rem;
            answ+=rem/pot;
        }
        pot*=2ll;
    }

    cout << answ << '\n';

    return 0;
}