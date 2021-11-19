#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    vector<ll> a, b, answ;
    int n;
    
    cin >> n;
    answ.assign(n,0);
    for(int i=0;i<n;i++){
        ll x, y, z;
        cin >> x >> y >> z;
        a.push_back(x+y+z);
        b.push_back(x+y+z-max({x,y,z}));
        if(b.back()<=a.back()-2)
            answ[i] = -1;
    }

    sort(b.begin(),b.end());
    b.push_back(3e9);
    for(int i=0;i<n;i++){
        auto it = upper_bound(b.begin(),b.end(),a[i]-2);
        //cout << i << " " << a[i] << " " << it-b.begin() <<"\n";
        answ[i] += it-b.begin();
        cout << answ[i] << " ";
    }
    cout<<"\n";

    return 0;
}