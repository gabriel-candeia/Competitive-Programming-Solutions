#include <bits/stdc++.h>
#define ll long long    
using namespace std;
    
int main(){
    ll n, k;
    ll sum = 0;

    cin >> n >> k;

    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        sum += x;
    }

    cout << sum/n << ".";
    sum = sum%n;

    int decimal = 0; 
    sum = sum*10;   
    while(decimal<k){
        if(sum<n){
            cout << 0;
        }
        else{
            cout << sum/n;
            sum = sum%n;
        }
        sum = sum*10;
        decimal++;
    }

    return 0;
}