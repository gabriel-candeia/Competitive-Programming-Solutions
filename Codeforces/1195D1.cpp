#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const ll mod =  998244353;

int main(){
    ll n, a, answ = 0, pot;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        pot = 1;
        while(a){
            answ=(answ+(a%10)*((11ll*n)%mod*pot)%mod)%mod;
            pot=(pot*100ll)%mod;
            a/=10;
        }
    }
    cout << answ << '\n';
    return 0;
}