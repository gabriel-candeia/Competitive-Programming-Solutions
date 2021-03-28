#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        ll n;
        map<ll,ll> mp;
        vector<ll> x, y;

        cin >> n; x.assign(n,0), y.assign(n,0);
        for(int i=0;i<n;i++)
            cin >> x[i] >> y[i];


        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        ll answ = (x[(n-1)/2+(n%2==0)]-x[(n-1)/2]+1)*(y[(n-1)/2+(n%2==0)]-y[(n-1)/2]+1);

        cout << answ << '\n';
    }
    return 0;
}