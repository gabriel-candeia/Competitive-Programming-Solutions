#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    ll n, h, answ=0;
    vector<vector<ll>> mat,mx;

    cin >> n >> h;
    mat.assign(h+1,vector<ll>(n+1,0));
    mx.assign(h+1,vector<ll>(n+1,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<h;j++){
            cin>> mat[j][i];
            mx[j][i] = mat[j][i];
        }
    }

    for(ll i=1;i<=h;i++){
        for(ll j=0;j<n;j++){
            ll acm = mat[i-1][j];
            if(j-1>=0)
                acm = max(acm,mat[i-1][j-1]);
            if(j+1<n)
                acm = max(acm,mat[i-1][j+1]);
            mat[i][j]+=acm;
            answ = max(answ,mat[i][j]);
        }
    }

    cout << answ <<'\n';
    return 0;
}