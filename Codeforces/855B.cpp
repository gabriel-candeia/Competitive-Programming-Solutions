#include<bits/stdc++.h>
#define ll long long int
#define N int(1e5+3)
using namespace std;

ll min(ll a, ll b){
    return (a<b) ? a : b;
}

ll max(ll a, ll b){
    return (a<b) ? b : a;
}

int main(){
    ll n, arr[N], p, q, r;
    vector<ll> prefMax, prefMin, sufMax, sufMin;

    cin >> n >> p >> q >> r;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    prefMax.push_back(arr[0]);
    prefMin.push_back(arr[0]);
    for(int i=1;i<n;i++){
        prefMin.push_back(min(prefMin.back(),arr[i]));
        prefMax.push_back(max(prefMax.back(),arr[i]));
    }

    sufMax.push_back(arr[n-1]);
    sufMin.push_back(arr[n-1]);
    for(int i=1;i<n;i++){
        sufMin.push_back(min(sufMin.back(),arr[n-1-i]));
        sufMax.push_back(max(sufMax.back(),arr[n-1-i]));
    }

    reverse(sufMax.begin(),sufMax.end());
    reverse(sufMin.begin(),sufMin.end());

    ll answ=0, resp=-3e18;
    for(int j=0;j<n;j++){
        answ = q*(arr[j]);
        answ += p*((p>0) ? prefMax[j] : prefMin[j]);
        answ += r*((r>0) ? sufMax[j] : sufMin[j]);
        resp = max(answ,resp);
    }

    cout << resp <<'\n';
    return 0;
}