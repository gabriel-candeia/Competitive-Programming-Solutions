#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<ll> arr;
        cin >> n;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        ll sum = 0, mult=0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            mult += (i+1);
        }
        bool ok = ((sum%mult)==0);
        sum/=mult;
        vector<ll> answ(n,0);
        for(int i=0;i<n;i++){
            ll aux = arr[i]-arr[((i-1)%n+n)%n];
            aux = sum-aux;
            if((aux%n)!=0 || aux<=0) ok = false;
            answ[i] = aux/n;
        }
        if(ok){
            cout <<"YES\n";
            for(auto x:answ)
                cout << x << " ";
            cout<<"\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}