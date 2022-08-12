#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
using namespace std;

const ll base = 31, mod = 18014398241046527;

int main(){
    fastio();
    unordered_set<ll> st;
    string s;
    int n;

    cin >> s;
    n  = s.size();
    ll acm = 0, pot = 1;
    for(int i=0;i<s.size();i++){
        acm = (acm*base + (s[i]-'a'+1))%mod;
        st.insert(acm);
    }

    acm = 0;
    vector<int> ok(n+1,0);
    for(int i=n-1;i>=0;i--){
        acm = (acm + pot*(s[i]-'a'+1))%mod;
        ok[i] = st.find(acm)!=st.end();
        ok[i]+=ok[i+1];
        pot = (pot*base)%mod;
    }// são os sufixos a partir de i que são prefixos da string

    int q;
    cin >> q;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        cout << ok[max(x,n+1-x)] << "\n";
    }

    return 0;
}
