#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool ehPossivel(ll a, int k, bitset<64>& basek){
    int last_bit, i=0;
    while(a!=0){
        last_bit = a%k;
        if(last_bit>=2 || (last_bit==1 && basek[i]==1)){
            return false;
        }
        else if(last_bit==1){
            basek[i] = 1;
        }
        a /= k;
        i++;
    }
    return true;
}

int main(){
    int t, n, k;
    ll a;
    bitset<64> basek;
    bool poss;

    cin >> t;
    while(t--){

        cin >> n >> k;
        basek &= 0;

        poss = true;
        for(int i=0;i<n;i++){
            cin >> a;
            if(poss){
                poss *= ehPossivel(a,k,basek);
            }
        }
        cout << ((poss) ? "YES" : "NO") << '\n';
    }


    return 0;
}