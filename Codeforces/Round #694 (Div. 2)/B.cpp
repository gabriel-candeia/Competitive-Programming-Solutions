#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<ll> arr;
        ll n, y;
        cin >> n >> y;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;   

        ll sum = 0, mn=64, pivot=-1;

        for(int i=0;i<n;i++){
            ll qtd=0, x=arr[i];
            while(x%y==0){
                x/=y;
                qtd++;
            }
            if(qtd<mn){
                mn = qtd;
                pivot = i;
            }
        }
        for(int i=0;i<n;i++){
            if(i<pivot){
                sum+=(mn+2)*arr[i];
            }
            else{
                sum+=(mn+1)*arr[i];
            }
        }

        cout << sum << "\n";

    }

    return 0;
}