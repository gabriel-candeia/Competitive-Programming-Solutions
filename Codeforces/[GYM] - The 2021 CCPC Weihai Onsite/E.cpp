#include<bits/stdc++.h>
#define maxn int(2097152)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
using namespace std;

vector<double> arr, pref, copia;

int bb(int i, double x){
    int l = 0, r = i, med, answ=-1;
    while(l<=r){
        med = (l+r)/2;
        if(arr[med]<x){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ;
}

int main(){
    fastio();
    ll n, k, q;

    cin >> n >> k >> q;
    arr.assign(n,0);
    copia.assign(n,0);
    for(int i=0;i<n;i++)
        cin >> arr[i], copia[i] = arr[i];

    sort(arr.begin(),arr.end());
    
    pref.assign(n,0);
    pref[0] = arr[0];
    for(int i=1;i<n;i++)
        pref[i] = pref[i-1]+arr[i];
    
    vector<double> dp(105,0);
    for(ll i=1;i<n;i++){
        dp[0] += (pref[i-1]+i*arr[i])*2.0/(n*n-n);
    }
    
    for(int i=1;i<=k;i++){
        for(int j=1;j<arr.size();j++){
            int med = bb(j-1,dp[i-1]-arr[j]);
            //cout  <<med << " " << dp[i-1]-arr[j]<<"\n";
            //if(med==-1) continue;
            dp[i] += dp[i-1]*(med+1)*2.0/(n*n-n);
            int m = j-med-1;
            double acm = pref[j-1] -  ((med!=-1) ? pref[med] : 0);
            //cout << arr[j] << " " << dp[i-1]-arr[j] << " "<< med << " " << arr[j]*m+acm  << " " << (arr[j]*m+acm)*2.0/(n*n-n) << " " << dp[i-1]*(med+1)*2.0/(n*n-n) << "\n";
            //cout << (n*n-n) <<"\n";
            dp[i] += (arr[j]*m+acm)*2.0/(n*n-n);
        }
    }
    //cout << dp[0] << " " << dp[1] <<"\n";
    cout << fixed << setprecision(10) << dp[k] <<"\n";
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        
        if(c==0){
            cout << "accept" <<"\n";
        }
        else if(copia[a-1]+copia[b-1]<dp[c-1]){
            cout << "reselect" <<"\n";
        }
        else if(copia[a-1]+copia[b-1]==dp[c-1]){
            cout << "both" <<"\n";
        }
        else{
            cout << "accept" <<"\n";
        }
    }

    return 0;
}