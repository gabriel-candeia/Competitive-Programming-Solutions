#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    vector<ll> arr;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr){
        cin >> x;
    }

    ll answ = 0; n--;

    // Combinação(n,q)%mod se o mod for primo
    // mod = 2, (n,q) é impar se (n-q)&q tem um bit em comum

    for(int i=0;i<=n;i++){
        if((((i)&(n-i))==0)){
            if(arr[i]==-1){
                answ = -1; 
                break;
            }
            else{
                answ = answ^arr[i];
            }
        }
    }
    
    cout << answ <<"\n";    
    return 0;
}

