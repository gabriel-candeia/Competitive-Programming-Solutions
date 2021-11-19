#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, answ = 0;
        cin >> n;

        for(int i=1;i<10;i++){
            ll acm = i;
            for(;acm<=n;acm = 10*acm+i) answ++;
        }
        cout << answ << "\n";
    }

}