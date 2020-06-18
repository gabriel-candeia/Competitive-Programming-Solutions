#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, m, k, jog, resto;

    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        jog = min(m,n/k);
        resto = m-jog;
        resto = resto/(k-1) + ((resto%(k-1))!=0);
        cout << jog-resto << '\n';
    }

    return 0;
}