#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, x, a, acm=0, answ=0;
    map<int,int> cnt;

    cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> a;
        acm += a;
        answ+=cnt[acm-x] + (acm==x);
        cnt[acm]++;
    }

    cout << answ << '\n';

    return 0;
}