#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define ll long long
using namespace std;

ll pref[maxn], mx[maxn], coord=0, answ=0, n;

int main(){
    cin >> n;
    for(ll i=1;i<=n;i++){
        cin >> pref[i];
        pref[i]+=pref[i-1];
        mx[i] = max(pref[i],mx[i-1]);
        answ = max(answ,coord+mx[i]);
        coord+=pref[i];
    }

    cout << answ <<'\n';

    return 0;
}