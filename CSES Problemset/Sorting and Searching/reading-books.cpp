#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll max(ll a, ll b){
    return (a<b) ? b : a;
}

int main(){
    ll sum=0, n, mx=-1, a;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        sum+=a;
        mx = max(a,mx);
    }

    cout << sum + max(0,2*mx-sum) <<'\n';

    return 0;
}