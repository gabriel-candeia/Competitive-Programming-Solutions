#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        ll acm = 1, answ=0;
        cin >> n >> k;

        while(acm<n){
            if(acm>=k){
                answ += (n-acm)/k + ((n-acm)%k!=0);
                break;
            }
            answ++;
            acm = acm + min(acm,k);
        }

        cout << answ << "\n";


    }

    return 0;
}