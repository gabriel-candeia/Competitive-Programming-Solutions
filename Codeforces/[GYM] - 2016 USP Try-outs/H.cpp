#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mult = 1e10;
ll n, m;
ll v1[2<<16], v2[2<<16];
map<double, ll> mapa1, mapa2;

void generate1(int num){
    int tamanho = (1<<num);
    double ans;
    for(int i = 1; i < tamanho; i++){
        ans = 0;
        for(int j = 0; j < num; j++){
            if(i&(1<<j)){
                ans += log(v1[j]);
            }
        }
        mapa1[floor(ans*mult)] = i;
    }
}

void generate2(int num){
    int tamanho = (1<<num);
    double ans;
    for(int i = 1; i < tamanho; i++){
        ans = 0;
        for(int j = 0; j < num; j++){
            if(i&(1<<j)){
                ans += log(v2[j]);
            }
        }
        mapa2[floor(ans*mult)] = i;
    }
}
int main(){
    cin >> n >> m; 
    for(int i = 0; i < n; i++){
        cin >> v1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> v2[i];
    }
    generate1(n);
    generate2(m);
    int n2 = -1, m2 = -1;
    int ans1, ans2;
    for(auto par:mapa1){
        if(mapa2.count(par.first)){
            ans1 = par.second;
            ans2 = mapa2[par.first];
            n2 = __builtin_popcount(ans1);
            m2 = __builtin_popcount(ans2);
        }
    }

    if(n2 == -1){
        cout << "N\n";
        return 0;
    }
    cout << "Y\n";
    cout << n2 << " " << m2 << "\n";
    for(int i = 0; i < n; i++){
        if(ans1&(1<<i)){
            cout << v1[i] << " ";
        }
    } 
    cout << "\n";
    for(int i = 0; i < m; i++){
        if(ans2&(1<<i)){
            cout << v2[i] << " ";
        }
    } 
    cout << "\n";
    return 0;
}