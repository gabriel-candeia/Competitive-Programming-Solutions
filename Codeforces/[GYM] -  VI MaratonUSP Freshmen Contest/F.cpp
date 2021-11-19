#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    vector<ll> arr, pref;

    cin >> n;
    arr.assign(n,0), pref.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    
    pref[0] = arr[0];
    for(int i=1;i<n;i++)
        pref[i] = pref[i-1] + arr[i];

    bool isok = true;
    for(int i=0;i<n;i++) if(pref[i]<0) isok = false;

    if(isok){cout << "morete chapou: errou conta!" << "\n"; return 0;}

    vector<ll> dp(n+1,0);
    for(int i=n-1;i>=0;i--) dp[i] = min(dp[i+1]+arr[i],arr[i]);

    ll acm = 0;
    vector<int> answ;
    for(int i=0;i<n;i++){
        if(acm>=-dp[i+1]){
            answ.push_back(i);
        }
        if(acm+arr[i]<0) break;
        acm += arr[i];
    }


    if(answ.size()!=0){
        cout << answ.size() << "\n";
        for(auto x:answ)
            cout << x+1 << " ";
        cout<<'\n';
    }
    else{
        cout << "morete chapou: ficou com saldo negativo!" << "\n";
    }
    

    return 0;
}