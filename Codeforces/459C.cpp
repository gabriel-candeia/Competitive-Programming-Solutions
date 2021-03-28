#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, k, d;
    cin >> n >> k >> d;

    if(n/k + (n%k!=0) <= d){
        for(int i=-1;i<d-1;i++){
            for(int j=0;j<n;j++){
                cout << (j/k + (j%k==i))%k + 1 << ' ';
            }
            cout<<'\n';
        }
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}