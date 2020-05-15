#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<ll> a(n+1,0), b(n+1,0);

        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        for(int i=0;i<n;i++){
            cin >> b[i];
        }

        sort(b.rbegin(),b.rend());
        sort(a.rbegin(),a.rend());

        ll answ = 0;
        for(int i=0;i<n-k;i++){
            answ+=a[i];
        }

        for(int i=0;i<k;i++){
            answ+=max(a[n-1-i],b[i]);
        }
        cout << answ << '\n';
    }


    return 0;
}
