#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    int n, x;
    vector<pair<ll,ll>> a;

    cin >> n;
    a.assign(n,{0,0});
    for(int i=0;i<n;i++){
        cin >> x;
        a[i].first = x;
    }
    for(int i=0;i<n;i++){
        cin >> x;
        a[i].second = x;
    }

    sort(a.begin(),a.end());
    ll r = 0, target=0, sum=0, answ=0;
    multiset<ll> s;

    while(r<n||s.size()){
        if(!s.size() || target==a[r].first){
            target = a[r].first;
            while(a[r].first==target){
                sum+=a[r].second;
                s.insert(-a[r++].second);
            }
        }
        sum+=*(s.begin());
        s.erase(s.begin());
        target++;
        answ+=sum;
    }

    cout << answ << '\n';

    return 0;
}