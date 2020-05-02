#include<bits/stdc++.h>
#define D(x) cout << #x << "=" << x << '\n'
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

ll ceil(ll a, ll b){
    return a/b + (a%b!=0);
}

ll max(ll a, ll b){
    return (a<b) ? b : a;
}

ll min(ll a, ll b){
    return (a>b) ? b : a;
}

ll multiplesInRange(ll l, ll r, ll x){
    ll temp = r/x - ceil(l,x)+1;
    return max(temp,0);
}

int main(){
    int t, a, b, q;
    ll  l, r;

    cin >> t;
    while(t--){
        cin >> a >> b >> q;
        ll answ = 0, temp = max(a,b), cnt;
        a = min(a,b); b = temp;

        while(q--){
            cin >> l >> r;

            //invalid
            ll mmc = (a*b)/gcd(a,b);
            cnt = multiplesInRange(l,r,mmc);
            //D(mmc);

            //invalid-middle
            cnt = cnt*b;
            //D(cnt);

            //before first-multiple in range
            temp =  (l/b)*b;
            if(temp%a==0){
                cnt+= (min(ceil(l,b)*b-1,r)-l+1);
            }
            //D(cnt);

            //last-multiple
            temp = (r/b)*b;
            if(temp%a==0 && temp>=l){
                cnt += min(b,r-temp+1)-b;
            }
            //D(cnt);

            cout << r-l+1 - cnt << ' ';
        }
        cout << "\n";
    }

    return 0;
}