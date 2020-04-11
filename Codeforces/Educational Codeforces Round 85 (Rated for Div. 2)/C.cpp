#include<bits/stdc++.h>
#define N int(3e5)+3
#define ll long long
using namespace std;

int main(){
    int t, n;   
    ll a[N], b[N], c[N];

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        ll answ=-1, sum=0;

        for(int i=0;i<n;i++){
            cin >> a[i] >> b[i];
        }

        c[0] = a[0] - b[n-1];
        for(int i=1;i<n;i++){
            c[i] = a[i]-b[i-1];
            c[i] =((c[i]>0)*c[i]);
            sum+=c[i];
        }
        c[0] = c[0]*(c[0]>0);
        sum += c[0];

        for(int i=0;i<n;i++){
            answ = ((sum+a[i]-c[i]<answ || answ==-1) ? sum+a[i]-c[i] : answ);
        }
        cout << answ << '\n';
    }

    return 0;
}