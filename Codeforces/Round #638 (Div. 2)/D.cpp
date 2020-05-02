#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, t;
    
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> answ;
        ll qtd = 1, soma = 1;
        
        while(soma<=n){
            answ.push_back(qtd);
            qtd*=2;
            soma+=qtd;
        }

        soma -= qtd;

        if(soma!=n){    
            answ.push_back(n-soma);
        }

        sort(answ.begin(),answ.end());

        cout << answ.size()-1 << '\n';
        for(int i=1;i<answ.size();i++){
            cout << answ[i]-answ[i-1] << ' ';
        }
        cout << '\n';

    }

    return 0;
}