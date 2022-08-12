#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    ll k;
    vector<ll> arr, v, last;

    cin >> n >> k;
    arr.assign(n,0), v.assign(n,0), last.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    ll cicloSoma = 0, cicloTamanho = 0;


    ll qtd = 0, tempo = 1;
    while(k && v[qtd%n]==0){
        v[qtd%n] = tempo++;
        last[qtd%n] = qtd;
        qtd += arr[qtd%n];
        k--;
    }
    cicloSoma = qtd-last[qtd%n];
    cicloTamanho = tempo-v[qtd%n];

    //cout << qtd << " " << k << " " << cicloTamanho << " " << cicloSoma <<"\n";

    qtd += cicloSoma*(k/cicloTamanho);
    k = k%cicloTamanho;

    while(k){
        qtd += arr[qtd%n];
        k--;
    }

    cout << qtd <<"\n";

    return 0;
}

