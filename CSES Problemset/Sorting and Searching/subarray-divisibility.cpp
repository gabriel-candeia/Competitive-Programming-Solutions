#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, sum=0, a, answ=0, k;
    map<ll,int> cnt;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        sum+=a;
        k  = sum%n;
        if(k<0){ k+=n;}

        answ+=cnt[k] + (sum%n==0);
        cnt[k]++;
    }

    cout << answ << '\n';

    return 0;
}