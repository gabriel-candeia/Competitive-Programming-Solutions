#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b, k;
        bool ok = false;

        cin >> a >> b >> k;
        if(a==b){
            ok = (a!=1);
        }
        else if(a%2==0){
            if(b%2==0) b--;
            //if(a==b) ok = true;
            if((b-a+1)/2 <=k) ok = true;
        }
        else{
            a--;
            if(b%2==0) b--;
            //if(a==b) ok = true;
            if((b-a+1)/2 <=k) ok = true;
        }

        cout << ((ok) ? "YES" : "NO") <<"\n";

    }

    return 0;
}