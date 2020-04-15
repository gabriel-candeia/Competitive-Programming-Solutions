#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int t;
    ll n;
    
    cin >> t;
    while(t--){
        cin >> n;
        if(n%2){
            cout << n/2 << '\n';
        }
        else{
            cout << (n-1)/2 << '\n';
        }
    }

    return 0;
}