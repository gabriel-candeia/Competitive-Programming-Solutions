#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, t;  
    vector<ll> a;
    cin >> t;
    while(t--){
        cin >> n;
        ll answ=0;
        a.assign(n,0);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        for(int i=1;i<n;i++){
            answ-=min(a[i]-a[i-1],0ll);
        }

        cout << answ <<'\n';
    }
    return 0;
}