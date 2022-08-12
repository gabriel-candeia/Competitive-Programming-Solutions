#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

int main(){
    int n, k;
    vector<ll> arr, best;

    cin >> n >> k;
    arr.assign(max(n,k),0), best.assign(max(n,k),0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    ll soma=arr[0], somaMul = best[0] = arr[0];
    for(int i=1;i<k;i++){
        best[i] = somaMul;
        if(i<n)
            best[i] = min(best[i],arr[i]);
        soma = (soma + best[i])%mod;
        somaMul = (somaMul + soma)%mod;
    }
    
    cout << best[k-1] <<"\n";

    return 0;
}
/*
// soma i*a_{i} -> soma (i+1)*a_{i} + a_{0}

pedra 2: f1       
pedra 3: f2 + 2f1  | f2+f1
pedra 4: f3 + 2f2 + 3f1 | f3+f2+f1

somaAcm += cara_da_Vez
somaMul += somaAcm




*/