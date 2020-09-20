#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    vector<int> a;
    vector<pair<int,int>> b;

    cin >> n;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        int t = sqrt(a[i]);
        b.push_back({min(a[i]-t*t,(t+1)*(t+1)-a[i]),0});
        if(b.back().first==0)
            b.back().second = ((a[i]==0) ? -2 : -1);
    }
    sort(b.begin(),b.end());
    ll answ=0;
    for(int i=0;i<n/2;i++){
        answ+=b[i].first;
    }
    for(int i=n/2;i<n;i++){
        answ-=b[i].second;
    }
    cout << answ <<'\n';

    return 0;
}