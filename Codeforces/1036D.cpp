#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, m;
    ll sum=0;
    vector<ll> a, b;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }

    cin >> m;
    b.assign(m,0);
    for(int i=0;i<m;i++){
        cin >> b[i];
        sum-=b[i];
    }

    if(sum==0){
        ll cnt=0, acmA=0, acmB=0, l=0, r=0;

        while(l<n && r<m){
            if(acmA==acmB){
                cnt++;
                acmA=a[l++];
                acmB=b[r++];
            }
            else if(acmA>acmB){
                acmB+=b[r++];
            }
            else{
                acmA+=a[l++];
            }
        }

        cout << cnt << '\n';
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}

