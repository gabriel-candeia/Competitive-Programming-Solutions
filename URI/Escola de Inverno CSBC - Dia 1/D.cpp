#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<array<int,3>> eventos;

        cin >> n;
        for(int i=0;i<n;i++){
            char op;
            int a, b;
            cin >> op >> a >> b;
            eventos.push_back(array<int,3>{a,0,op=='N'});
            eventos.push_back(array<int,3>{b,1,op=='N'});
        }
        sort(eventos.begin(),eventos.end());
        int answ = 0, acm = 0, qtd = 0;
        for(auto evento:eventos){
            acm += ((!evento[1]) ? 1 : -1);
            if(evento[2]) qtd += ((!evento[1]) ? 1 : -1);
            if(qtd) answ = max(answ,acm);
        }
        cout << answ <<"\n";
    }

    return 0;
}
